#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <stdlib.h>
#include <string.h>

PSP_MODULE_INFO("BTCPSP", 0, 1, 0);

#define printf pspDebugScreenPrintf

void dump_threadstatus(void);

int done = 0;

int exit_callback(int arg1, int arg2, void *common)
{
	done = 1;
	return 0;
}

int CallbackThread(SceSize args, void *argp)
{
	int cbid;

	cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);
	sceKernelSleepThreadCB();

	return 0;
}

int SetupCallbacks(void)
{
	int thid = 0;

	thid = sceKernelCreateThread("update_thread", CallbackThread,
				     0x11, 0xFA0, 0, 0);
	if(thid >= 0)
	{
		sceKernelStartThread(thid, 0, 0);
	}

	return thid;
}

int main(void)
{
     // A bit messy but whatever
    unsigned int CROSS_COUNTER = 0; unsigned int SQUARE_COUNTER = 0; unsigned int CIRCLE_COUNTER = 0;
    unsigned int TRIANGLE_COUNTER = 0; unsigned int DOWN_COUNTER = 0; unsigned int RIGHT_COUNTER = 0;
    unsigned int LEFT_COUNTER = 0; unsigned int UP_COUNTER = 0; unsigned int START_COUNTER = 0;
    unsigned int SELECT_COUNTER = 0; unsigned int L_TRIGGER_COUNTER = 0; unsigned int R_TRIGGER_COUNTER = 0;

	SceCtrlData pad;

	pspDebugScreenInit();
	SetupCallbacks();

	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

	while(!done){
		pspDebugScreenSetXY(0, 2);

    	sceCtrlReadBufferPositive(&pad, 1); 

        // A bit messy but whatever

	printf("Analog X = %d ", pad.Lx);
	printf("Analog Y = %d \n\n", pad.Ly);
        printf("Cross Counter: %d\n", CROSS_COUNTER);
        printf("Square Counter: %d\n", SQUARE_COUNTER);
        printf("Circle Counter: %d\n", CIRCLE_COUNTER);
        printf("Triangle Counter: %d\n\n", TRIANGLE_COUNTER);
        printf("Down Counter: %d\n", DOWN_COUNTER);
        printf("Right Counter: %d\n", RIGHT_COUNTER);
        printf("Left Counter: %d\n", LEFT_COUNTER);
        printf("Up Counter: %d\n\n", UP_COUNTER);
        printf("Start Counter: %d\n", START_COUNTER);
        printf("Select Counter: %d\n", SELECT_COUNTER);
        printf("L-Trigger Counter: %d\n", L_TRIGGER_COUNTER);
        printf("R-Trigger Counter: %d\n\n\n\n\n\n", R_TRIGGER_COUNTER);
        printf("\n\n\n\n\n\n\n\nMade By MicSuit in 2022");

		if (pad.Buttons != 0){

             // A bit messy but whatever (lol)
			if (pad.Buttons & PSP_CTRL_SQUARE){
				SQUARE_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_SQUARE)
                    sceCtrlReadBufferPositive(&pad, 1);
			}
			else if (pad.Buttons & PSP_CTRL_TRIANGLE){
				TRIANGLE_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_TRIANGLE)
                    sceCtrlReadBufferPositive(&pad, 1);
			} 
			else if (pad.Buttons & PSP_CTRL_CIRCLE){
				CIRCLE_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_CIRCLE)
                    sceCtrlReadBufferPositive(&pad, 1);
			} 
			else if (pad.Buttons & PSP_CTRL_CROSS){
				CROSS_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_CROSS)
                    sceCtrlReadBufferPositive(&pad, 1);
			} 

			else if (pad.Buttons & PSP_CTRL_UP){
				UP_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_UP)
                    sceCtrlReadBufferPositive(&pad, 1);
			} 
			else if (pad.Buttons & PSP_CTRL_DOWN){
				DOWN_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_DOWN)
                    sceCtrlReadBufferPositive(&pad, 1);
			} 
			else if (pad.Buttons & PSP_CTRL_LEFT){
				LEFT_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_LEFT)
                    sceCtrlReadBufferPositive(&pad, 1);
			} 
			else if (pad.Buttons & PSP_CTRL_RIGHT){
				RIGHT_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_RIGHT)
                    sceCtrlReadBufferPositive(&pad, 1);
			}      

			else if (pad.Buttons & PSP_CTRL_START){
				START_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_START)
                    sceCtrlReadBufferPositive(&pad, 1);
			}
			else if (pad.Buttons & PSP_CTRL_SELECT){
				SELECT_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_SELECT)
                    sceCtrlReadBufferPositive(&pad, 1);
			}
			else if (pad.Buttons & PSP_CTRL_LTRIGGER){
				L_TRIGGER_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_LTRIGGER)
                    sceCtrlReadBufferPositive(&pad, 1);
			}
			else if (pad.Buttons & PSP_CTRL_RTRIGGER){
				R_TRIGGER_COUNTER += 1;
                while (pad.Buttons & PSP_CTRL_RTRIGGER)
                    sceCtrlReadBufferPositive(&pad, 1);
			}      
		}
	}

	sceKernelExitGame();
	return 0;
}
