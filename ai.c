////////////////////////////////////////
//
//	File : ai.c
//	CoSpace Robot
//	Version 1.0.0
//	Jan 1 2016
//	Copyright (C) 2016 CoSpace Robot. All Rights Reserved
//
//////////////////////////////////////
//
// ONLY C Code can be compiled.
//
/////////////////////////////////////

#define CsBot_AI_H//DO NOT delete this line
#ifndef CSBOT_REAL
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define DLL_EXPORT extern __declspec(dllexport)
#define false 0
#define true 1
#endif//The robot ID : It must be two char, such as '00','kl' or 'Cr'.
char AI_MyID[2] = { '0','2' };


#define Yellow 1
#define Red 2
#define Blue 3
#define Green 4
#define Cyan 5
#define Gray 6
#define trapblue 7
#define Orange 8
#define White 9
#define pBlue 10
#define superobj 11
#define Yellow2 12
#define Orange2 13
//a
int AI_SensorNum = 13;
int afterdeposit = 0;
int antilit = 0;
//b
int borojlo = 0;
int bGameEnd = false;

//c
int watchdogs = 0;
int CurAction = -1;
int CurGame = 0;
int CSLeft_R = 0;
int CSLeft_G = 0;
int CSLeft_B = 0;
int CSRight_R = 0;
int CSRight_G = 0;
int CSRight_B = 0;
int Compass = 0;
int cyanobj = 0;
int colorcount = 0;
clock_t t;
int checkblockzone = 0;

//d
int Duration = 0;

//e
//f
int i2 = 0;
//g
int greenobj = 0;

//h
int shartenadidanobsacle = 0;
//i
//j
int j = 100;

//k
int kodumdarimirim = 0;

//l
int ltime = 0;
int LoadedObjects = 0;
int LED_1 = 0;
int Left = 0;
int level = 3;
int gotosuper[100];
//m
int mapx = 350;
int mapy = 260;
int maxbox = 19;
int MyState = 0;
int mame = 0;

//n
//o
int orangexy[2][2] = { { 47,23 },{ 346,241 } };
int obs = 0;

//p
int PositionX = 0;
int PositionY = 0;
int positionx = 0;
int positiony = 0;

//q
//r
int redobj = 0;
int Right = 0;
int Range = 10;

//s
int Speed = 0;
int shartnadidanobsacle = 0;
int superobject = 0;
int superobject1 = 0;
int SuperObj1_flag = 0;
int SuperDuration = 0;
int SuperObj_Num = 0;
int SuperObj_X = 0;
int SuperObj_Y = 0;
int SuperObj_X1 = 0;
int SuperObj_Y1 = 0;

//t
int TimeTrap = 0;
int tedadesuper = 0;
int tafrishi2 = 100;
int supere1barmasraf = 0;
int Teleport = 0;
int TM_State = 0;
int Time = 0;
int time2 = 0;
int time3 = 0;
int type = 2;
static int time1 = 0;
time_t timezone;
double timezone1 = 0;

//u
int usimbolt = 0;
int masircount =16 ;
int unloadw2[100][4] = { { 180, 212, 1, -1 },{ 181, 254, 2, 0 },{ 116, 249, -1, 1 },{ 182, 213, 4, -1 },{ 190, 252, 5, 3 },{ 298, 242, 6, 4 },{ 345, 159, 7, 5 },{ 335, 96, 8, 6 },{ 245, 101, 9, 7 },{ 153, 80, -1, 8 },{ 184, 211, 11, -1 },{ 191, 250, 12, 10 },{ 309, 237, 13, 11 },{ 350, 148, 14, 12 },{ 327, 63, 15, 13 },{ 253, 44, -1, 14 } };
int MAX = 37;
int khat[1000][4] = { { 148,230,157,230, },{ 158,231,158,186, },{ 149,187,158,187, },{ 149,187,148,229, },{ 250,156,198,156, },{ 199,156,199,116, },{ 198,117,86,115, },{ 86,115,87,105, },{ 87,104,209,105, },{ 209,103,210,146, },{ 210,146,250,145, },{ 250,147,248,127, },{ 250,125,276,126, },{ 277,128,279,157, },{ 280,156,309,156, },{ 309,156,309,114, },{ 309,114,322,115, },{ 322,115,322,156, },{ 322,156,309,158, },{ 309,158,309,186, },{ 309,186,278,186, },{ 277,187,279,157, },{ 278,157,251,156, },{ 311,81,268,81, },{ 268,81,269,70, },{ 269,70,312,69, },{ 312,68,312,80, },{ 209,70,198,71, },{ 198,70,198,39, },{ 197,40,159,40, },{ 158,39,159,28, },{ 159,27,210,26, },{ 210,27,210,69, },{ 87,105,60,104, },{ 60,103,60,74, },{ 60,74,89,71, },{ 89,73,89,103 } };
//int unloadw2[100][4] = { { 10000,10000,-1,1 },{ 98,95,2,-1 },{ 137,74,3,1 },{ 141,50,4,2 },{ 161,29,5,3 },{ 144,8,6,4 },{ 14,20,7,5 },{ 47,57,8,6 },{ 15,90,9,7 },{ 99,167,10,8 },{ 256,26,11,9 },{ 346,115,12,10 },{ 249,153,13,11 },{ 85,236,-1,12 }};
int US_Front = 0;
int US_Left = 0;
int US_Right = 0;

//w
int WheelLeft = 0;
int WheelRight = 0;
int WheelSum = 0;

//x
int SuperObj_X2 = 0;
int SuperObj_Y2 = 0;
//y
int yy = 0;
//z
float zz = 0;


#define CsBot_AI_C

DLL_EXPORT void SetGameID(int GameID)
{
	CurGame = GameID;
	bGameEnd = 0;
}
DLL_EXPORT int GetGameID()
{
	return CurGame;
}
DLL_EXPORT int IsGameEnd()
{
	return bGameEnd;
}
#ifndef CSBOT_REAL

DLL_EXPORT char* GetDebugInfo()
{
	char info[1024];
	sprintf(info, "Duration=%d;SuperDuration=%d;bGameEnd=%d;CurAction=%d;CurGame=%d;SuperObj_Num=%d;SuperObj_X=%d;SuperObj_Y=%d;Teleport=%d;LoadedObjects=%d;US_Front=%d;US_Left=%d;US_Right=%d;CSLeft_R=%d;CSLeft_G=%d;CSLeft_B=%d;CSRight_R=%d;CSRight_G=%d;CSRight_B=%d;PositionX=%d;PositionY=%d;TM_State=%d;Compass=%d;Time=%d;WheelLeft=%d;WheelRight=%d;LED_1=%d;MyState=%d;", Duration, SuperDuration, bGameEnd, CurAction, CurGame, SuperObj_Num, SuperObj_X, SuperObj_Y, Teleport, LoadedObjects, US_Front, US_Left, US_Right, CSLeft_R, CSLeft_G, CSLeft_B, CSRight_R, CSRight_G, CSRight_B, PositionX, PositionY, TM_State, Compass, Time, WheelLeft, WheelRight, LED_1, MyState);
	return info;
}

DLL_EXPORT char* GetTeamName()
{
	return " Salam Zeynoddin";
}

DLL_EXPORT int GetCurAction()
{
	return CurAction;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT int GetTeleport()
{
	return Teleport;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT void SetSuperObj(int X, int Y, int num)
{
	SuperObj_X = X;
	SuperObj_Y = Y;
	SuperObj_Num = num;
}
//Only Used by CsBot Rescue Platform
DLL_EXPORT void GetSuperObj(int *X, int *Y, int *num)
{
	*X = SuperObj_X;
	*Y = SuperObj_Y;
	*num = SuperObj_Num;
}

#endif 
DLL_EXPORT void SetDataAI(volatile int* packet, volatile int *AI_IN)
{

	int sum = 0;

	US_Front = AI_IN[0]; packet[0] = US_Front; sum += US_Front;
	US_Left = AI_IN[1]; packet[1] = US_Left; sum += US_Left;
	US_Right = AI_IN[2]; packet[2] = US_Right; sum += US_Right;
	CSLeft_R = AI_IN[3]; packet[3] = CSLeft_R; sum += CSLeft_R;
	CSLeft_G = AI_IN[4]; packet[4] = CSLeft_G; sum += CSLeft_G;
	CSLeft_B = AI_IN[5]; packet[5] = CSLeft_B; sum += CSLeft_B;
	CSRight_R = AI_IN[6]; packet[6] = CSRight_R; sum += CSRight_R;
	CSRight_G = AI_IN[7]; packet[7] = CSRight_G; sum += CSRight_G;
	CSRight_B = AI_IN[8]; packet[8] = CSRight_B; sum += CSRight_B;
	PositionX = AI_IN[9]; packet[9] = PositionX; sum += PositionX;
	PositionY = AI_IN[10]; packet[10] = PositionY; sum += PositionY;
	TM_State = AI_IN[11]; packet[11] = TM_State; sum += TM_State;
	Compass = AI_IN[12]; packet[12] = Compass; sum += Compass;
	Time = AI_IN[13]; packet[13] = Time; sum += Time;
	packet[14] = sum;

}
DLL_EXPORT void GetCommand(int *AI_OUT)
{
	AI_OUT[0] = WheelLeft;
	AI_OUT[1] = WheelRight;
	AI_OUT[2] = LED_1;
	AI_OUT[3] = MyState;
}
boolean CheckL(int LR, int HR, int LG, int HG, int LB, int HB)
{
	if (LR <= CSLeft_R && CSLeft_R <= HR && LG <= CSLeft_G && CSLeft_G <= HG && LB <= CSLeft_B && CSLeft_B <= HB) 
	{
		return true;
	}
	return false;
}
boolean CheckR(int LR, int HR, int LG, int HG, int LB, int HB)
{
	if (LR <= CSRight_R && CSRight_R <= HR && LG <= CSRight_G && CSRight_G <= HG && LB <= CSRight_B && CSRight_B <= HB) 
	{
		return true;
	}
	return false;
}
float distance(int x1, int y1)
{
	float dis = sqrt(((y1 - PositionY)*(y1 - PositionY)) + ((x1 - PositionX)*(x1 - PositionX)));
	return dis;
}
float distance2(int x1, int y1)
{
	float dis = sqrt(((y1 - SuperObj_Y1)*(y1 - SuperObj_Y1)) + ((x1 - SuperObj_X1)*(x1 - SuperObj_X1)));
	return dis;
}
int intcorrecter(int a)
{
	if (a > 360) {
		a = a - 360;
	}
	if (a < 0) {
		a = a + 360;
	}
	return a;
}
float floatcorrecter(float a) 
{
	if (a > 360) {
		a = a - 360;
	}
	if (a < 0) {
		a = a + 360;
	}
	return a;
}
double doublecorrecter(double a)
{
	if (a > 360) 
	{
		a = a - 360;
	}
	if (a < 0)
	{
		a = a + 360;
	}
	return a;
}
void Colorcheck() {
	Left = 0;
	Right = 0;
	if (CheckL(204, 235, 217, 248, 0, 0)) {
		Left = Yellow;
	}
	if (CheckR(204, 235, 217, 248, 0, 0)) {
		Right = Yellow;
	}
	if (CheckL(204, 235, 217, 248, 0, 0)) {
		Left = Yellow2;
	}
	if (CheckR(204, 235, 217, 248, 0, 0)) {
		Right = Yellow2;
	}
	if (CheckL(232, 255, 29, 39, 29, 39)) {
		Left = Red;
	}
	if (CheckR(232, 255, 29, 39, 29, 39)) {
		Right = Red;
	}
	if (CheckL(0, 10, 0, 20, 0, 30)) {
		Left = Blue;
	}
	if (CheckR(0, 10, 0, 20, 0, 30)) {
		Right = Blue;
	}
	if (CheckL(29, 39, 249, 255, 255, 255)) {
		Left = Green;
	}
	if (CheckR(29, 39, 249, 255, 255, 255)) {
		Right = Green;
	}
	if (CheckL(29, 39, 29, 39, 29, 39)) {
		Left = Cyan;
	}
	if (CheckR(29, 39, 29, 39, 29, 39)) {
		Right = Cyan;

	}
	if (CheckL(133, 153, 141, 161, 187, 207)) {
		Left = Gray;
	}
	if (CheckR(133, 153, 141, 161, 187, 207)) {
		Right = Gray;
	}
	if (CheckL(54, 62, 97, 111, 221, 245)) {
		Left = trapblue;

	}
	if (CheckR(54, 62, 97, 111, 221, 245)) {
		Right = trapblue;

	}
	if (CheckL(54, 62, 97, 111, 221, 245)) {
		Left = pBlue;
		colorcount++;
	}
	if (CheckR(54, 62, 97, 111, 221, 245)) {
		Right = pBlue;
		colorcount++;
	}
	if (CheckL(194, 240, 153, 190, 0, 0)) {
		Left = Orange;
	}
	if (CheckR(194, 240, 153, 190, 0, 0)) {
		Right = Orange;
	}
	if (CheckL(194, 240, 153, 190, 0, 0)) {
		Left = Orange2;
	}
	if (CheckR(194, 240, 153, 190, 0, 0)) {
		Right = Orange2;
	}
	if (CheckL(190, 217, 184, 205, 185, 189)) {
		Left = White;
	}
	if (CheckR(190, 217, 184, 205, 185, 189)) {
		Right = White;
	}
	if (CheckL(232, 255, 30, 40, 254, 255)) {
		Left = superobj;
	}
	if (CheckR(232, 255, 30, 40, 254, 255)) {
		Right = superobj;
	}

}
boolean Intersects(int P1X, int P1Y, int P2X, int P2Y, int p3X, int p3Y, int p4X, int p4Y)
{
	boolean lines_intersect;
	boolean segments_intersect;
	float dx12 = P2X - P1X;
	float dy12 = P2Y - P1Y;
	float dx34 = p4X - p3X;
	float dy34 = p4Y - p3Y;
	float denominator = (dy12 * dx34 - dx12 * dy34);
	float t1 = 0;
	float t2 = 0;
	if (denominator == 0)
	{
		lines_intersect = false;
		segments_intersect = false;
		// intersection = new PointF(float.NaN, float.NaN);
		// close_p1 = new PointF(float.NaN, float.NaN);
		// close_p2 = new PointF(float.NaN, float.NaN);
		return false;
	}
	else
	{
		t1 = ((P1X - p3X) * dy34 + (p3Y - P1Y) * dx34) / denominator;
	}
	lines_intersect = true;

	t2 = ((p3X - P1X) * dy12 + (P1Y - p3Y) * dx12) / -denominator;
	// intersection = new PointF(P1.X + dx12 * t1, P1.Y + dy12 * t1);
	segments_intersect = ((t1 > 0) && (t1 < 1) && (t2 > 0) && (t2 < 1));
	// if (t1 < 0)
	// {
	//     t1 = 0;
	// }
	// else if (t1 > 1)
	// {
	//     t1 = 1;
	// }

	// if (t2 < 0)
	// {
	//     t2 = 0;
	// }
	// else if (t2 > 1)
	// {
	//     t2 = 1;
	// }
	// close_p1 = new PointF(P1.X + dx12 * t1, P1.Y + dy12 * t1);
	// close_p2 = new PointF(p3.X + dx34 * t2, p3.Y + dy34 * t2);
	// return segments_intersect ? (float)(Math.Sqrt(Math.Pow(p3.X - intersection.X, 2) + Math.Pow(p3.Y - intersection.Y, 2))) : -1;
	return segments_intersect ? true : false;
}
boolean isViewable(int x, int y)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		if (Intersects(PositionX, PositionY, x, y, khat[i][0], khat[i][1], khat[i][2], khat[i][3]))
			return false;
	}
	return true;
}
boolean isViewable2(int x, int y, int x2, int y2)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		if (Intersects(x2, y2, x, y, khat[i][0], khat[i][1], khat[i][2], khat[i][3]))
			return false;
	}
	return true;
}
void execute(int left, int right, int led, int duration);
boolean stayincolor(int color, int durat) 
{
	time3++;
	if (durat > time3) 
	{
		if (Left == color || Right == color) 
		{
			if (Left == color) 
			{
				if (Right != color)
				{
					execute(-1, 3, 0, 0);
					return true;
				}
			}
			if (Right == color)
			{
				if (Left != color)
				{
					execute(3, -1, 0, 0);
					return true;
				}
			}
		}
		if (colorcount > 0) 
		{
			if (Right != color && Left != color) 
			{
				execute(-5, 5, 0, 0);
				return true;
			}
		}
	}
	if (time3 > durat) 
	{
		time3 = 0;
	}
	return false;
}
int zaviebeinmavaoon(int x, int y)
{
	double darajebeinemavaoon = (((atan((double)(y - PositionY) / (x - PositionX))) * 180) / 3.1415);
	doublecorrecter(darajebeinemavaoon);
	return (int)darajebeinemavaoon;
}
int converttocompass(int darajebeinemavaoon, int x, int y) 
{
	if ((x - PositionX >= 0) && (y - PositionY >= 0)) 
	{
		darajebeinemavaoon = darajebeinemavaoon + 270;
	}
	if ((x - PositionX < 0) && (y - PositionY >= 0)) 
	{
		darajebeinemavaoon = darajebeinemavaoon - 270;
	}
	if ((x - PositionX >= 0) && (y - PositionY < 0)) 
	{
		darajebeinemavaoon = darajebeinemavaoon - 90;
	}
	if ((x - PositionX < 0) && (y - PositionY < 0)) 
	{
		darajebeinemavaoon = darajebeinemavaoon + 90;
	}
	return darajebeinemavaoon;
}
boolean gotoxymanage(int darajebeinemavaoon, int x, int y, int led, int duration2)
{
	shartnadidanobsacle = 0;
	if ((abs(PositionX - x) < 5) && (abs(PositionY - y) < 5)) 
	{

		//execute(0, 0, led, duration2);
		time3 = 0;

		if (kodumdarimirim == 4)
		{
			j = unloadw2[j][3];
		}
		if (kodumdarimirim == 3) 
		{
			printf("avazshod = %d\n", tedadesuper - 1);
			tedadesuper = tedadesuper - 1;
		}
		if (kodumdarimirim == 2)
		{
			printf("-----------------------residim be super\n");
			execute(0, 0, 1, 50);
			SuperObj1_flag = 0;
			shartenadidanobsacle = 90;
			SuperObj_X1 = 0;
			SuperObj_Y1 = 0;

		}

		//	printf("changed j= %d\n", j);

		//if (SuperObj1_flag == 1) {
		//	SuperObj_X1 = 0;
		//	SuperObj_Y1 = 0;
		//}
		return true;

	}
	else 
	{
		if (darajebeinemavaoon > 0) 
		{
			superobject1 = superobject;
		}
		int min = darajebeinemavaoon - 15;
		int max = darajebeinemavaoon + 15;
		int arcom = darajebeinemavaoon - Compass;
		min = intcorrecter(min);//ablah jolosh bayad benevisi ,return faghat meghdar mide
		max = intcorrecter(max);
		arcom = intcorrecter(arcom);
		if ((arcom) > 180) 
		{
			execute(1, -1, 0, 0);
			if (max > min) 
			{
				if ((min < Compass) && (Compass < max))
				{
					if (superobject1 == superobject) 
					{
						execute(3, 3, 0, 0);
						return true;
					}
				}
			}
			if (max<min) 
			{
				if ((Compass>min) || (Compass < max))
				{
					if (superobject1 == superobject) 
					{
						execute(3, 3, 0, 0);
						return true;
					}
				}

			}
			return true;
		}
		if ((arcom) < -180)
		{
			execute(-1, 1, 0, 0);
			if (max > min)
			{
				if ((min < Compass) && (Compass < max))
				{
					if (superobject1 == superobject) 
					{
						execute(3, 3, 0, 0);
						return true;
					}
				}
			}
			if (max<min) 
			{
				if ((Compass>min) || (Compass < max)) 
				{
					if (superobject1 == superobject) 
					{
						execute(3, 3, 0, 0);
						return true;

					}
				}

			}
			return true;
		}

		if (0 < (arcom) && (arcom) < 180) 
		{
			execute(-1, 1, 0, 0);
			if (max > min) {
				if ((min < Compass) && (Compass < max))
				{
					if (superobject1 == superobject)
					{
						execute(3, 3, 0, 0);
						return true;

					}
				}
			}
			if (max<min) 
			{
				if ((Compass>min) || (Compass < max))
				{
					if (superobject1 == superobject) 
					{
						execute(3, 3, 0, 0);
						return true;
					}
				}

			}
			return true;
		}
		if (0 >(arcom) && (arcom)>-180)
		{
			execute(1, -1, 0, 0);
			if (max > min) {
				if ((min < Compass) && (Compass < max)) 
				{
					if (superobject1 == superobject) 
					{
						execute(3, 3, 0, 0);
						return true;
					}
				}
			}
			if (max<min) {
				if ((Compass>min) || (Compass < max))
				{
					if (superobject1 == superobject)
					{
						execute(3, 3, 0, 0);
						return true;
					}
				}
			}
			return true;
		}
	}
	return false;
}
void gotoxy(int x, int y, int led, int duration2) 
{
	int darajebeinemavaoon2 = zaviebeinmavaoon(x, y);
	int compassbeinemavaoon = converttocompass(darajebeinemavaoon2, x, y);
	printf("x=%d\t", x);
	printf("y=%d\t", y);
	shartenadidanobsacle = 13;
	gotoxymanage(compassbeinemavaoon, x, y, led, duration2);
	time2 = 0;

}
boolean cmp(int bo, int dur)
{

	int wcmp = 0;
	wcmp = bo - Compass;
	wcmp = intcorrecter(wcmp);
	int min = wcmp - 10;
	int max = wcmp + 10;
	min = intcorrecter(min);
	max = intcorrecter(max);
	if (min < max)
	{
		if (min < Compass && Compass < max)
		{
			execute(3, 3, 0, 0);
			return true;
		}
		else if (wcmp < 180)
		{
			if (wcmp > 0 && wcmp < 45)
			{
				execute(-1, 1, 0, 0);
				return true;
			}
			if (wcmp > 45 && wcmp < 90) 
			{
				execute(-2, 1, 0, 0);
				return true;
			}
		}
		else
		{

			execute(1, -1, 0, 0);
			return true;
		}
	}
	else
	{

		if (min < Compass || Compass < max)
		{
			execute(3, 3, 0, 0);
			return true;
		}
		else if (wcmp < 180)
		{

			execute(-1, 1, 0, 0);
			return true;
		}
		else
		{

			execute(1, -1, 0, 0);
			return true;
		}
	}
	return false;
}
boolean TrapCheck() 
{

	if (Left == Yellow || Left == Yellow2) 
	{
		printf("leftyellow\n");
		execute(3, -4, 0, 0);
		return true;
	}
	if (Right == Yellow || Right == Yellow2)
	{
		printf("rightyellow\n");
		execute(-4, 3, 0, 0);
		return true;
	}
	if ((Left == Yellow && Right == Yellow) || (Left == Yellow2 && Right == Yellow2)|| (Left == Yellow && Right == Yellow2)|| (Left == Yellow2 && Right == Yellow))
	{
		printf("everywhere yellow\n");
		execute(-3, -5, 0, 2);
		return true;
	}
	return false;
}
boolean tto(int deg)
{
	int baze = 15;
	int min = deg - baze;
	int max = deg + baze;
	int arcom = deg - Compass;
	min = intcorrecter(min);//ablah jolosh bayad benevisi ,return faghat meghdar mide
	max = intcorrecter(max);
	arcom = intcorrecter(arcom);
	if (min < max)
	{
		//printf("normal\n");
		if (min < Compass && Compass < max)
		{
			execute(3, 3, 0, 0);
			return true;
		}
		else if (arcom < 180)
		{
			//	printf("normal <\n");
			execute(-1, 1, 0, 0);
			return false;
		}
		else
		{
			//	printf("normal >\n");
			execute(1, -1, 0, 0);
			return false;
		}
	}
	else
	{
		//	printf("UUUnoraml\n");
		if (min < Compass || Compass < max)
		{
			execute(3, 3, 0, 0);
			return true;
		}
		else if (arcom < 180)
		{
			//	printf("UUUnoraml <\n");
			execute(-1, 1, 0, 0);
			return false;
		}
		else
		{
			//	printf("UUUnoraml >\n");
			execute(1, -1, 0, 0);
			return false;
		}
	}


}
boolean tto2(int deg)
{
	int baze = 15;
	int min = deg - baze;
	int max = deg + baze;
	int arcom = deg - Compass;
	min = intcorrecter(min);//ablah jolosh bayad benevisi ,return faghat meghdar mide
	max = intcorrecter(max);
	arcom = intcorrecter(arcom);

	if (min < max)
	{
		if (min < Compass && Compass < max)
		{
			execute(3, 3, 0, 0);
			return true;
		}
		else if (arcom < 180)
		{
			zz = (float)arcom / 45;
			//printf("zz1=%f\n", zz);
			if (zz < 4 && zz >= 3)
			{
				execute(-4, 4, 0, 0);
				return false;
			}
			if (zz < 3 && zz >= 2) 
			{
				execute(-3, 3, 0, 0);
				return false;
			}
			if (zz < 2 && zz >= 1)
			{
				execute(-2, 2, 0, 0);
				return false;
			}
			if (zz < 1 && zz >= 0)
			{
				execute(-1, 1, 0, 0);
				return false;
			}
		}
		else
		{
			zz = (float)arcom / 45;

			//	printf("zz2=%f\n", zz);
			if (zz < 8 && zz >= 7) 
			{
				execute(-1, 1, 0, 0);

				return false;
			}
			if (zz < 7 && zz >= 6)
			{
				execute(-2, 2, 0, 0);

				return false;
			}
			if (zz < 6 && zz >= 5) 
			{
				execute(-3, 3, 0, 0);
				return false;
			}
			if (zz < 5 && zz >= 4) 
			{
				execute(-4, 4, 0, 0);
				return false;
			}
		}
	}
	else
	{
		if (min < Compass || Compass < max)
		{
			execute(3, 3, 0, 0);
			return true;
		}
		else if (arcom < 180)
		{
			zz = (float)arcom / 45;
			//	printf("zz3=%f\n", zz);
			if (zz < 4 && zz >= 3) 
			{
				execute(-4, 4, 0, 0);
				return false;
			}
			if (zz < 3 && zz >= 2) 
			{
				execute(-3, 3, 0, 0);
				return false;
			}
			if (zz < 2 && zz >= 1) 
			{
				execute(-2, 2, 0, 0);
				return false;
			}
			if (zz < 1 && zz >= 0) 
			{
				execute(-1, 1, 0, 0);
				return false;
			}
		}
		else
		{
			zz = (float)arcom / 45;
			//	printf("zz4=%f\n", zz);
			if (zz < 8 && zz >= 7) 
			{
				execute(-4, 4, 0, 0);
				return false;
			}
			if (zz < 7 && zz >= 6) 
			{
				execute(-3, 3, 0, 0);
				return false;
			}
			if (zz < 6 && zz >= 5)
			{
				execute(-2, 2, 0, 0);
				return false;
			}
			if (zz < 5 && zz >= 4) 
			{
				execute(-1, 1, 0, 0);
				return false;
			}
		}
	}
}
void teleport(int timez) 
{
	if (Time > timez) 
	{
		Teleport = 2;
		greenobj = 0;
		redobj = 0;
		cyanobj = 0;
	}
}
void execute(int left, int right, int led, int duration)
{
	LED_1 = led;
	Duration = duration;
	if (checkblockzone == 1)
	{
		if (left == right)
		{
			if (left > 0)
			{
				WheelLeft = 3;
				WheelRight = 3;
			}
			if (left < 0)
			{
				WheelLeft = -3;
				WheelRight = -3;
			}
		}
		else if (left*right > 0)
		{
			if (left >0)
			{
				if (left > right)
				{
					WheelLeft = 3;
					WheelRight = -3;
				}
				else
				{
					WheelLeft = -3;
					WheelRight = 3;
				}

			}
			else
			{
				if (left > right)
				{
					WheelLeft = 3;
					WheelRight = -3;
				}
				else
				{
					WheelLeft = -3;
					WheelRight = 3;
				}
			}
		}
		else
		{
			if (left > right)
			{
				WheelLeft = 3;
				WheelRight = -3;
			}
			else
			{
				WheelLeft = -3;
				WheelRight = 3;
			}
		}

	}

	else
	{
		WheelLeft = left;
		WheelRight = right;

	}
	if (Left == Gray || Right == Gray)
	{
		if (left == right && left > 0)
		{
			WheelLeft = 5;
			WheelRight = 5;
		}
		if (left == right && left < 0)
		{
			WheelLeft = -5;
			WheelRight = -5;
		}
		if (left != right &&left>right)
		{
			WheelLeft = 5;
			WheelRight = -5;
		}
		if (left != right &&left<right)
		{
			WheelLeft = -5;
			WheelRight = 5;
		}
	}
}
void unloadworld2()
{
	if (redobj + greenobj + cyanobj + superobject>5)
	{
		if (j == 100)
		{
			float min = distance(unloadw2[0][0], unloadw2[0][1]);
			for (int i = 0; i < maxbox; i++)
			{
				if ((distance(unloadw2[i][0], unloadw2[i][1])< min))
				{
					min = distance(unloadw2[i][0], unloadw2[i][1]);
					j = i;
				}
			}
		}
		kodumdarimirim = 4;
		gotoxy(unloadw2[j][0], unloadw2[j][1], 0, 0);
	}
}
void object1() {
	if (redobj + greenobj + cyanobj != 6)
	{
		if (Left == Red || Right == Red)
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;

			borojlo = 1;
			redobj++;
		}
		if (Left == Cyan || Right == Cyan)
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;
			borojlo = 1;
			cyanobj++;
		}
		if (Left == Green || Right == Green)
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;
			borojlo = 1;
			greenobj++;
		}
		if (Left == superobj || Right == superobj)
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;
			borojlo = 1;
			superobject++;
			antilit++;
		}
	}
}
void object2()
{
	if (redobj + greenobj + cyanobj<6)
	{
		if ((Left == Red || Right == Red) && (redobj <= 1))
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;
			borojlo = 1;
			redobj++;
		}
		if ((Left == Cyan || Right == Cyan) && (cyanobj <= 1))
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;
			borojlo = 1;
			cyanobj++;
		}
		if ((Left == Green || Right == Green) && (greenobj <= 1))
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;
			borojlo = 1;
			greenobj++;
		}
		if (Left == superobj || Right == superobj)
		{
			WheelLeft = 0;
			WheelRight = 0;
			Duration = 50;
			LED_1 = 1;
			borojlo = 1;
			superobject++;
			antilit++;
		}
	}
}
void btrap()
{
	if (Left == trapblue || Right == trapblue)
	{
		execute(-5, -5, 0, 0);
		greenobj = 0;
		redobj = 0;
		cyanobj = 0;
		superobject = 0;
		antilit = 0;
	}
}
boolean USFrontcheck(int usl)
{
	if (US_Front < usl)
	{
		return true;
	}
	else
	{
		return false;
	}

}
boolean US_Rightcheck(int usl)
{
	if (US_Right < usl)
	{
		return true;
	}
	else
	{
		return false;
	}

}
boolean US_Leftcheck(int usl)
{
	if (US_Left < usl)
	{
		return true;
	}
	else
	{
		return false;
	}

}
boolean ObstacleCheck()
{
	if (shartenadidanobsacle != 13)
	{
		if (USFrontcheck(15))
		{
			if (US_Left > US_Right)
			{
				execute(-3, 3, 0, 0);
				if (shartnadidanobsacle == 1)
				{
					obs = 1;

				}
				return true;
			}
			else
			{
				execute(3, -3, 0, 0);
				if (shartnadidanobsacle == 1)
				{
					obs = 1;
				}
				return true;
			}
		}
		else if (US_Rightcheck(8))
		{
			execute(1, 3, 0, 0);
			if (shartnadidanobsacle == 1)
			{
				obs = 1;
			}
			return true;
		}
		else if (US_Leftcheck(8))
		{
			execute(3, 1, 0, 0);
			if (shartnadidanobsacle == 1)
			{
				obs = 1;
			}
			return true;
		}
		else
		{
			time2++;
		}
		return false;
	}
	return false;
}
boolean orangee()
{

	if (redobj + cyanobj + greenobj + superobject > 5 && Left == Orange&&Right == Orange)
	{
		execute(0, 0, 2, 50);
		redobj = 0;
		cyanobj = 0;
		greenobj = 0;
		superobject = 0;
		afterdeposit = 1;
		return true;
	}
	return false;
}
boolean outline()
{
	if (PositionX != 0 && PositionY != 0)
	{
		if (PositionY > mapy - Range) {
			if (Compass <= 20 || Compass >= 340)
			{
				execute(-2, -5, 0, 0);
				return true;

			}
			else if (Compass < 50 && Compass > 20)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 90 && Compass > 50)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 340 && Compass > 310)
			{
				cmp(Compass - 89, 0);

			}
			else if (Compass < 310 && Compass > 270)
			{
				cmp(Compass - 89, 0);

			}
		}
		else if (PositionX > mapx - Range)
		{
			if (Compass >= 250 && Compass <= 290)
			{
				execute(-2, -5, 0, 0);
				return true;
			}
			else if (Compass < 320 && Compass > 290)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 360 && Compass > 320)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 250 && Compass > 220)
			{
				cmp(Compass - 89, 0);

			}
			else if (Compass < 220 && Compass > 180)
			{
				cmp(Compass - 89, 0);

			}
		}
		else if (PositionY < Range)
		{
			if (Compass >= 160 && Compass <= 200)
			{
				execute(-2, -5, 0, 0);
				return true;

			}
			else if (Compass < 230 && Compass > 200)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 270 && Compass > 230)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 160 && Compass > 130)
			{
				cmp(Compass - 89, 0);

			}
			else if (Compass < 130 && Compass > 90)
			{
				cmp(Compass - 89, 0);
			}
		}
		else if (PositionX < Range)
		{
			if (Compass >= 70 && Compass <= 110)
			{
				execute(-2, -5, 0, 0);
				return true;
			}
			else if (Compass < 140 && Compass > 110)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 180 && Compass > 140)
			{
				cmp(Compass + 89, 0);

			}
			else if (Compass < 70 && Compass > 40)
			{
				cmp(Compass - 89, 0);

			}
			else if (Compass < 40 && Compass > 0)
			{
				cmp(Compass - 89, 0);

			}
		}
		if (PositionX > mapx - Range + 5)
		{
			cmp(90, 0);

		}
		if (PositionX < Range - 5)
		{
			cmp(270, 0);

		}
		if (PositionY > mapy - Range + 5)
		{
			cmp(180, 0);

		}
		if (PositionY < Range - 5)
		{
			cmp(0, 0);

		}
	}
		return false;
}
void checksuperobject()
{
	if ((SuperObj_X > 0) && (SuperObj_Y > 0))
	{
		SuperObj_X1 = SuperObj_X;
		SuperObj_X2 = SuperObj_X;
		SuperObj_Y1 = SuperObj_Y;
		SuperObj_Y2 = SuperObj_Y;
		SuperObj1_flag = 1;
	}
}
boolean antiswamp() 
{
	//printf("== Antiswamp ==");
	//printf("%d == Left And %d == Right",Left,Right);
	if (type == 1) 
	{
		if (Left == Gray && Right != Gray)
		{
			//		printf("+ + 1 of 3 + +");
			execute(5, 0, 0, 0);
			return true;
		}
		if (Right == Gray && Left != Gray)
		{
			//		printf("+ + 2 of 3 + +");
			execute(0, 5, 0, 0);
			return true;
		}
		if (Left == Gray && Right == Gray) 
		{
			if (Time < time1 + 5) 
			{
				//			printf("+ + 3 of 3 + +");
				execute(5, -5, 0, 0);
				return true;
			}
		}
		else 
		{
			time1 = Time;
		}
	}
	return false;
}
int startflag = 0;
clock_t lastcycle;
double px = 0, py = 0;
void blockzone() 
{
	timezone1 = ((clock() - lastcycle) / (float)CLOCKS_PER_SEC);
	if (checkblockzone == 0)
	{
		px = PositionX;
		py = PositionY;
	}
	//printf("||cos = %f\n ", cos((double)Compass*3.14/180.0));
	//printf("||sin = %f\n ", sin((double)Compass*3.14 / 180.0));
	if (checkblockzone == 1)
	{
		PositionX = px;
		PositionY = py;
	}
	if (checkblockzone == 1 && timezone1 < 1 && WheelRight == 3 && WheelLeft == 3)
	{
		int zarib = 29.61;
		if (Left == Gray || Right == Gray)
			zarib = zarib / 5;
		px = px - sin((double)Compass*3.14 / 180.0) * zarib * timezone1;
		py = py + cos((double)Compass*3.14 / 180.0) * zarib * timezone1;
		//printf("X position = %f\n", px);
		//printf("Y position = %f\n", py);
		PositionX = px;
		PositionY = py;
	}

	lastcycle = clock();
}
void strategyworld1()
{
	

	if (level == 0 && redobj + greenobj + cyanobj > 5)
	{
		level = 3;
	}
	if (redobj + greenobj + cyanobj > 5)
	{
		if (level == 1)
		{
			if (tto(180))
			{
				printf("1\n");
				if (USFrontcheck(10))
				{
					level = 2;
				}
			}
		}
		if (level == 2)
		{
			if (tto(90))
			{
				printf("2\n");
				if (USFrontcheck(10))
				{
					level = 3;
				}
			}
		}
		if (level == 3)
		{
			if (tto(180))
			{
				printf("3\n");
				if (USFrontcheck(10))
				{
					level = 4;
				}

			}
		}
		if (level == 4)
		{
			if (tto(90))
			{
				printf("4\n");
				if (USFrontcheck(10))
				{
					level = 5;
				}
			}
		}
		if (level == 5)
		{
			if (tto(0))
			{
				printf("5\n");
				if (Left == Yellow || Left == Yellow2 || Right == Yellow|| Right == Yellow2) {
					tto(230);
				}
				if (USFrontcheck(10))
				{
					
					level = 6;
				}
			}
		}
		if (level == 6)
		{
			if (tto(270))
			{
				printf("6\n");
				if (USFrontcheck(10))
				{
					level = 7;
				}
			
			}
		}
		if (level == 7)
		{
			if (tto(0))
			{
				printf("7\n");
				if (USFrontcheck(10))
				{
					level = 3;
				}
			}
		}
	}

}

void gotosuperobj()
{
	if (SuperObj1_flag == 1)
	{
		printf("-----------sedashod----------");
		if (supere1barmasraf == 0)
		{
			if (SuperObj_X1 != 0)
			{
				float min = INT_MAX;
				for (int i = 0; i < maxbox; i++)
				{
					if (isViewable2(unloadw2[i][0], unloadw2[i][1], SuperObj_X2, SuperObj_Y2))
					{
						printf("i=%d\n", i);
						if ((distance2(unloadw2[i][0], unloadw2[i][1]) < min))
						{
							min = distance2(unloadw2[i][0], unloadw2[i][1]);
							tafrishi2 = i;
							shartnadidanobsacle = 1;
							i2 = i;
						}
					}
				}
				//printf("Tafreshi2=%d\n", tafrishi2);

				gotosuper[0] = tafrishi2;
				int i = 1;
				for (i = 1; unloadw2[gotosuper[i - 1]][3] != -1; i++)
				{
					gotosuper[i] = unloadw2[gotosuper[i - 1]][3];
					//	printf("super=%d\n", gotosuper[i]);
					//gotoxy(gotosuper[i + 1][0], gotosuper[i + 1][1],0,0);
				}

				//printf("i=%d\n", i);
				tedadesuper = i - 1;
				printf("**************\n");
				for (int i = 0; i < tedadesuper; i++)
				{
					printf("super %d = %d\n", i, gotosuper[i]);
				}
				printf("**************\n");
				tedadesuper--;
				supere1barmasraf = 85;
			}
		}
		else {
			printf("in seri tedad=%d \n", tedadesuper);

			if (tedadesuper >= 0)
			{
				kodumdarimirim = 3;
				gotoxy(unloadw2[gotosuper[tedadesuper]][0], unloadw2[gotosuper[tedadesuper]][1], 0, 0);
				printf("unloadw2[x]=%d\n", unloadw2[gotosuper[tedadesuper]][0]);
				printf("unloadw2[y]=%d\n", unloadw2[gotosuper[tedadesuper]][1]);
				printf("gotosuper=%d\n", gotosuper[tedadesuper]);
			}
			else
			{
				//if (positionx == unloadw2[i2][0] && positiony == unloadw2[i2][1]) {
				printf("$$$$$$$$$$$ %d %d", SuperObj_X1, SuperObj_Y1);
				gotoxy(SuperObj_X1, SuperObj_Y1, 1, 0);
				kodumdarimirim = 2;
				//}
			}
		}
	}
}

void Game0()
{
	Colorcheck();
	if (Duration > 0)
	{
		Duration--;
	}
	else if (borojlo == 1)
	{
		execute(3, 3, 0, 3);
		borojlo = 0;
	}
	else if (afterdeposit == 3)
	{
		execute(3, 3, 0, 3);
		afterdeposit = 0;
	}
	else if (afterdeposit == 2)
	{
		execute(1, 5, 0, 3);
		afterdeposit = 3;
	}
	else if (afterdeposit == 1)
	{
		execute(-5, -5, 0, 2);
		afterdeposit = 2;
	}
	else
	{
		execute(3, 3, 0, 0);
		if (level == 3) {
			TrapCheck();
			ObstacleCheck();
			btrap();
			object1();
		}
		orangee();
		teleport(240);
		strategyworld1();
		if ((redobj + greenobj + cyanobj) > 4 && (Left == Orange|| Left==Orange2) && (Right == Orange||Right==Orange2))
		{
			execute(0, 0, 2, 50);
			redobj = 0;
			cyanobj = 0;
			greenobj = 0;
			afterdeposit = 1;
			j = 100;
			level = 3;
		}
	
		Speed = (WheelLeft + WheelRight) / 2;
		WheelSum += Speed;
		WheelSum = WheelSum / 2;
		if (WheelSum > 0.1) { TimeTrap = Time; }
		if (WheelSum < 0.1 && Time - TimeTrap >= 10 ) {
			printf("watchdog=%d\n",watchdogs);
			watchdogs++;
			if (watchdogs <= 2) {
				execute(-1, -2, 0, 0);
				watchdogs = 5;
			}
			if (watchdogs == 5) {
				execute(-1, -2, 0, 0);
				watchdogs = 10;
			}
			if(watchdogs==10){
				execute(3, 3, 0, 0);
				watchdogs = 0;
			}
		}
	}
}

void Game1()
{
	printf("redobj=%d\n",redobj);
	printf("greenobj=%d\n", greenobj);
	printf("blackobj=%d\n", cyanobj);
	printf("superobj=%d\n", antilit);
	if (time2 > 50)
	{
		obs = 0;
	}
	if (PositionX != 0 && PositionY != 0)
	{
		positionx = PositionX;
		positiony = PositionY;
	}
	if (PositionX == 0 && PositionY == 0)
	{
		checkblockzone = 1;
	}
	else
	{
		checkblockzone = 0;
	}
	//printf("checkblockzone %d\n", checkblockzone);
	blockzone();
	Colorcheck();
	btrap();
	if (Duration>0)
	{
		Duration--;
	}
	else if (borojlo == 1)
	{
		execute(3, 3, 0, 3);
		borojlo = 0;
	}
	else if (afterdeposit == 3)
	{
		execute(3, 3, 0, 3);
		afterdeposit = 0;
	}
	else if (afterdeposit == 2)
	{
		execute(3, -3, 0, 2);
		afterdeposit = 3;
	}
	else if (afterdeposit == 1)
	{
		execute(-5, -5, 0, 5);
		afterdeposit = 2;
	}
	else
	{
		execute(3, 3, 0, 0);
		if (ObstacleCheck())
		{
		}
		else if (outline())
		{
		}
		else if ((redobj + greenobj + cyanobj + antilit) > 5 && (Left == Orange || Left==Orange2) && (Right == Orange || Right==Orange2) && positionx>172 && positionx<193 && positiony>194 && positiony<222)
		{
			printf("nn");
			execute(0, 0, 2, 50);
			redobj = 0;
			cyanobj = 0;
			greenobj = 0;
			superobject = 0;
			antilit = 0;
			afterdeposit = 1;
			supere1barmasraf = 0;
			j = 100;
			shartenadidanobsacle = 90;
		}
		else
		{
			checksuperobject();
			gotosuperobj();
			unloadworld2();
		}
		object2();
		TrapCheck();
		Speed = (WheelLeft + WheelRight) / 2;
		WheelSum += Speed;
		WheelSum = WheelSum / 2;
		if (WheelSum > 0.1) { TimeTrap = Time; }
		if (WheelSum < 0.1 && Time - TimeTrap >= 10) {
			printf("watchdog");
			execute(-1, -2, 0, 1);
		}
		}
	
}


DLL_EXPORT void OnTimer()
{
	switch (CurGame)
	{
	case 9:
		break;
	case 10:
		WheelLeft = 0;
		WheelRight = 0;
		LED_1 = 0;
		MyState = 0;
		break;
	case 0:
		Game0();
		break;
	case 1:
		Game1();
		break;
	default:
		break;
	}
}

