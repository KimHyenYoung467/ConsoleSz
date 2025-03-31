#pragma once
#include <Windows.h>

// Foreground
#define FG_BLACK		0
//FG_BLACK 강조는 없음

#define FG_RED			FOREGROUND_RED|FOREGROUND_INTENSITY
#define FG_GREEN		FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define FG_BLUE			FOREGROUND_BLUE|FOREGROUND_INTENSITY

#define FG_RED_DARK		FOREGROUND_RED
#define FG_GREEN_DARK	FOREGROUND_GREEN 
#define FG_BLUE_DARK	FOREGROUND_BLUE

#define FG_YELLOW		FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define FG_SKY			FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define FG_PINK			FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY

#define FG_YELLOW_DARK	FOREGROUND_RED|FOREGROUND_GREEN
#define FG_SKY_DARK		FOREGROUND_GREEN|FOREGROUND_BLUE
#define FG_PINK_DARK	FOREGROUND_RED|FOREGROUND_BLUE

#define FG_GRAY			FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE
#define FG_WHITE		FG_GRAY|FOREGROUND_INTENSITY

// Background
#define BG_BLACK		0
//FG_BLACK 강조는 없음

#define BG_RED			BACKGROUND_RED|BACKGROUND_INTENSITY
#define BG_GREEN		BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BG_BLUE			BACKGROUND_BLUE|BACKGROUND_INTENSITY

#define BG_RED_DARK		BACKGROUND_RED
#define BG_GREEN_DARK	BACKGROUND_GREEN
#define BG_BLUE_DARK	BACKGROUND_BLUE

#define BG_YELLOW		BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BG_SKY			BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY
#define BG_PINK			BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_INTENSITY

#define BG_YELLOW_DARK	BACKGROUND_RED|BACKGROUND_GREEN
#define BG_SKY_DARK		BACKGROUND_GREEN|BACKGROUND_BLUE
#define BG_PINK_DARK	BACKGROUND_RED|BACKGROUND_BLUE

#define BG_GRAY			BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE
#define BG_WHITE		BG_GRAY|BACKGROUND_INTENSITY

#define ScreenWidth 80
#define ScreenHeight 40

namespace ConsoleRender
{
	void ScreenInit();
	void ScreenRelease();

	void ScreenFlipping();
	void ScreenClear();

	//더블 버퍼 (문제 없음) 활용 문제는 나중 문제.
	/*void Buffersinit(int x, int y, char* ch);
	HANDLE swapBuffers();
	void BufferRender(int x, int y);*/

	bool ScreenDrawChar(int x, int y, char ch, WORD attr);
	bool ScreenDrawChar(int x, int y, wchar_t ch, WORD attr);
	bool ScreenDrawString(int x, int y, const char* pStr, WORD attr);
	bool ScreenDrawString(int x, int y, const wchar_t* pStr, WORD attr);
	bool ScreenSetAttributes(WORD attr);

	//int ScreenWidth();
	//int ScreenHeight();
};

