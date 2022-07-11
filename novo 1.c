#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6
#define BUTTON_3 p7
#define BUTTON_4 p8

#define LED1 p9
#define LED2 p10
#define LED3 p11
#define LED4 p12

DigitalIn StartButton(BUTTON_1);
DigitalIn StopButton(BUTTON_2);
DigitalIn MachineGuardSensorSwitch (BUTTON_3);
DigitalIn TemperatureSensorSwitch (BUTTON_4);


DigitalOut Ready(LED1);
DigitalOut Running(LED2);
DigitalOut Fault_GuardOpen(LED3);
DigitalOut Fault_ExcessTemp(LED4);

MachineGuardSensorSwitch = 1;
TemperatureSensorSwitch =0;
StartButton=0;
StopButton=0;

	int main(){
	
		while(1){
			While (MachineGuardSensorSwitch = 0 || TemperatureSensorSwitch = 1){
				Running = 0;
				Fault_ExcessTemp = 0;
				Fault_GuardOpen = 0;
				Ready = 0;
				wait(0.2);
			}
			Ready = 1;
			while(StartButton = 0){
				wait(0.1);
			
		}
		Running = 1;
			while(Running == 1){
				if(MachineGuardSensorSwitch == 0){
					Fault_GuardOpen = 1;
					wait(0.5);
					Fault_GuardOpen = 0;
					Running = 0;
				}else if(TemperatureSensorSwitch == 1){
					Fault_ExcessTemp = 1;
					wait(0.5);
					Fault_ExcessTemp = 0;
					Running = 0;
				}else if(StopButton == 1){
					Running = 0;
				}
			
			}
		

		}
	}