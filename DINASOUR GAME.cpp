//DINASOUR GAME- CS(B) --->PROJECT#1---->SEM2

//Muhammad Umair (22-NTU-CS-1211)

//-----------------------------------------------------------------------------------------------------------------------
#include <conio.h>      //for kbhit function & getch()
#include <iostream>     //for cout
#include <time.h>       //for clock function
#include <windows.h>    //for custom gotoxy function
using namespace std;
void gotoxy(int x, int y)//custom gotoxy()function
{
 COORD coord; //data type of coordinates     //COORD->predefined structure having an instance coord!
 coord.X = x;//asign value to x coordinate
 coord.Y = y;//asign value to y coordinate
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);    //predefined function having predefined parameters! (HANDLE,COORD)
//the output screen has total of 25 rows and 80 columns!
} 
void delay(unsigned int mseconds){ //argument as milisecond from function call (default time is a clock tick/clock second)
clock_t goal;  //clock_t-> predefined datatype in library of time.h
goal = mseconds + clock();  //adding argument value and clock value
//clock function return the time that programm take during execution. i.e.,Compilation Time
while (goal > clock());
}
//INSTRUCTION FUNCTION
void getup()       
{
	system("cls");//clear the screen 
	gotoxy(10,2); //setting 10th column and 2nd row
	cout<<"Press X to Exit, Press Space to Jump";
	gotoxy(62,2);//setting 62th col and 2nd row
	cout<<"SCORE : ";
	gotoxy(0,25);//setting 0th col and 25th row
	for(int x=0;x<150;x++)
	cout<<"�"; //printing road for walking of dino
}
int t,speed=40;
//DINASOUR BODY STRUCTURE
void ds(int jump=0) 
{
	if(jump==0)//if it recieve zero argument from main
		t=0;
	else if(jump==2)//if recieve 2 in argument from main
		t--;
	else //if recieve argument other than 0,2 from main
	t++;
	//jump=1-->t++........jump=2--->t--......jump=0-->t=0;
	gotoxy(2,15-t);
	cout<<"                 ";
	gotoxy(2,16-t);
	cout<<"         ��������"; //by subtracting with t we are taking dino high and low.
	gotoxy(2,17-t);
	cout<<"         ��������";
	gotoxy(2,18-t);
	cout<<"         ��������";
	gotoxy(2,19-t);
	cout<<" �      �������� ";
	gotoxy(2,20-t);
	cout<<" ���  ���������� ";
	gotoxy(2,21-t);
	cout<<""" ������������  � ";
	gotoxy(2,22-t);
	cout<<"   ���������     ";
	gotoxy(2,23-t);
	static int a=1;
	//when user press space dino stops to walk. (dino's feet stop moving i.e., it takes a jump)  //stationary feet
	if(jump==1 || jump==2){
	cout<<"    ��� ��       ";
	gotoxy(2,24-t);
	cout<<"    ��   ��      ";
	}
	//if not so.... dino keep on walking.
	else if(a==1)
	{
	cout<<"    ����  ���    ";//printing the leg of dino
	gotoxy(2,24-t);
	cout<<"      ��         ";//printing foot of dino
	a=2;
	}
	else if(a==2)
	{
	cout<<"     ��� ��      ";//printing  2nd leg of dino
	gotoxy(2,24-t);
	cout<<"          ��     ";//printing 2nd foot of dino.
	a=1;
	}
	gotoxy(2,25-t);
	if(jump!=0){
	cout<<"                ";
	//we are printing space because the road on which dino is walking is removed when dino jump and dino easily move upward.
	}
	else
	{
		
		cout<<"�����������������";//this is for printing again road that is removed in upper portion.
	}
	delay(speed);
	//if we decrese speed from 40 so delay function increase the speed of dino.
	//if we increase speed from 40 to more then delay function slow down the speed of dino.
}
//For creating hurdle for dino...
void obj()
{
//GAME OVER COORDINATES!
	static int x=0,score=0;
	if(x==56 && t<4)//condition for game over
	{
	score=0;
	speed=40;
	gotoxy(36,8);//coordinates for displaying 'game over'
	cout<<" Game Over ";
	getch();  // to hold the output screen for some time until the user any key from the keyboard to exit the console screen!
	gotoxy(36,8);
	cout<<"         ";
	}
	//For creating hurdle for dino...
	gotoxy(74-x,20);
	//we are taking difference to move the hurdle to backward coordinate.
	cout<<"�     � ";
	gotoxy(74-x,21);
	cout<<"�     � ";
	gotoxy(74-x,22);
	cout<<"������� ";
	gotoxy(74-x,23);
	cout<<"   �    ";
	gotoxy(74-x,24);
	cout<<"   �  " ;
	x++;
	//by increasing x we move the hurdle. 
	if(x==73)
	//when x is 73 which is only 1 less then 74
	{
	x=0; // we again set x=0 which again start moving hurdle
	score++; //this calculate the score when each time hurdle reach on last
	gotoxy(70,2);
	cout<<"     ";
	gotoxy(70,2);
	cout<<score; //we print score on screen
	if(speed>20)
		speed--;
	}
}
int main()
{
	system("mode con: lines=29 cols=150");   
	cout<<"----Press 'ENTER' to start Game----\n";
	system("date");
	cout<<endl; 
	
	char ch;
	int i;
	getup();   //function calling of above getup function
	while(1)
	{
		while(!kbhit()){ 
		//kbhit returns nonzero value when key is pressed other wise return zero. 
		//!kbhit returns zero value when key is pressed other wise return nonzero.   
		//this function start game when user press any key.
			ds();
			obj();
		}
		ch=getch();
		if(ch==' ')
		{
			for(i=0;i<10;i++)
			{
			ds(1);
			obj();
			}
			for(i=0;i<10;i++)
			{
			ds(2);
			obj();
			}
		}
		else if (ch=='x' || ch=='X')     //to stop the game!
			break;
	} 
	
}
