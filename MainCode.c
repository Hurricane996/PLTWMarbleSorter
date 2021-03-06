#pragma config(Sensor, in2,    lfScanner,      sensorLineFollower)
#pragma config(Motor,  port2,           smCupCatcher,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           smGate,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           mHopper,       tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define M_HOPPER_SPEED            30
#define M_HOPPER_WAIT_TIME        75

#define SM_GATE_OPEN_POSITION    -70
#define SM_GATE_CLOSED_POSITION  -10
#define SM_GATE_OPEN_TIME       1000

#define LF_READ_TIME            1000

#define LF_THRESHOLD_METAL      2900
#define LF_THRESHOLD_PLASTIC    2830

#define SM_METAL                 -40
#define SM_PLASTIC                50
#define SM_WOOD                  127


task main(){
	while(1==1){
		setServo(smGate,SM_GATE_CLOSED_POSITION);

		startMotor(mHopper, M_HOPPER_SPEED);
		sleep(M_HOPPER_WAIT_TIME);
		stopMotor(mHopper);
		sleep(LF_READ_TIME);

		int sensor = SensorValue[lfScanner];
	  int smPos = sensor > LF_THRESHOLD_METAL   ?   SM_METAL :
				        sensor > LF_THRESHOLD_PLASTIC ? SM_PLASTIC :
				                                        SM_WOOD ;

	 setServo(smCupCatcher,smPos);


	 setServo(smGate,SM_GATE_OPEN_POSITION);

	 sleep(SM_GATE_OPEN_TIME);
	}
}
