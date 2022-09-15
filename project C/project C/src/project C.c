/*
 ============================================================================
 Name        : project.c
 Author      : Abdallah Nabil
 Version     :
 Copyright   : Your copyright notice
 Description : mini_projevt C , Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define enable 1

//////////////////functions prototyping///////
//void quit(char ch);
void turn_off_vehicle_engine (char ch);
void main_options(void);
void second_options(void);
void read_screen(int engine_state,int AC_state,int controller_state,int vehicle_speed,int temp,int temp_engine );
int main(void) {
	///////////////initialization///////////////
    int re=1;
    int re2=0;
	char ch;
	char ch2;
	int engine_state=0;
	int vehicle_speed=0;
	int AC_state=0;
	int temp=12;
	int controller_state=0;
	int temp_engine=12;
	while(re==1){
	main_options();//////main options/////
	scanf(" %c",&ch);
	if (ch=='a'){
		  re2=1;
		//////////
		while(re2==1){
		second_options();/////second options
		fflush(stdout);
		scanf(" %c",&ch2);
		/////////////if turn on the vehicle engine////////////
		if(ch2=='a'){         ////////////option a////////
			 re2=0;
		}
		//////////option b//////////color////
		if(ch2=='b'){
			re2=1;
			char color='R';
			printf("Enter the color required(capital letter)\n");
			fflush(stdout);
			scanf(" %c",&color);

			if(color=='G'){
				engine_state=1;     vehicle_speed=100;

			}
			else if(color=='o'){
				engine_state=1;     vehicle_speed=30;

			}
			else if (color=='R'){
				engine_state=1;      vehicle_speed=0;
			}
		}

		/////////option c/////////room temperature///////
		if(ch2=='c'){
              re2=1;
			printf("Enter the room temperature required/n");
			fflush(stdout);
			scanf("%d",&temp);
			if(temp<10){
				AC_state=1;     temp =20;
			}
			else if(temp>30){
				AC_state=1;     temp =20;
			}
			else{
				AC_state=0;
			}
		}
		//////////option d//////////engine temperature/////
#if enable
		if(ch2=='d'){
			re2=1;
			printf("Enter the engine temperature required/n");
			fflush(stdout);
			scanf("%d",&temp_engine);
			if(temp_engine<100){
				controller_state=1;  temp_engine=125;
			}
			else if(temp_engine>150){
				controller_state=1;  temp_engine=125;
			}
			else{
				controller_state=0;
			}
		}
#endif
		///condition if vehicle speed is 30
		if(vehicle_speed==30){
			AC_state=1;
			temp=temp*(5/4)+1;
#if enable
			controller_state=1;
			temp_engine=temp_engine*(5/4)+1;
#endif
		}
		read_screen(engine_state, AC_state, controller_state, vehicle_speed,temp,temp_engine);//read screen

	}
	}

	    if(ch=='b'){
	    	turn_off_vehicle_engine( ch);
            re=1;
	    }
		if(ch=='c'){
			 re=0;
				printf("\nQuit the system\n   Thank u \n");

			}
}
}

/////functions
/////function read screen
void read_screen(int engine_state,int AC_state,int controller_state,int vehicle_speed,int temp,int temp_engine ){
	///**reading on the screen **
	if(engine_state==1)
		printf("Engine is ON\n");
	else
		printf("Engine is OFF\n");
	printf("the vehicle speed : %d\n",vehicle_speed);
	if(AC_state==1)
		printf("AC is ON\n");
	else
		printf("AC is ON\n");

	printf("room temperature :%d\n",temp);
#if enable
	if(controller_state==1)
		printf("Engine Temperature Controller is ON\n");
	else
		printf("Engine Temperature Controller is Off\n");
	printf("engine temperature : %d\n",temp_engine);
#endif
}
////////////function/////////second options////////
void second_options(void){
	printf("\n***Turn on the vehicle engine***\n");

	printf("\na. Turn off the engine\nb. Set the traffic light color\nc. Set the room temperature (Temperature Sensor)\n");
#if enable
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
}
////////function//////////main options//////////////////
void main_options(void){
	printf("\n******main options******");
	printf("\na. Turn on the vehicle engine \nb. Turn off the vehicle engine\nc. Quit the system\n");
	fflush(stdout);
}
////////////////funtion ////////option b in the main options/////////

void turn_off_vehicle_engine (char ch){

	if(ch=='b'){
		//printf("\n***Turn off the vehicle engine***\n");

	}
}
