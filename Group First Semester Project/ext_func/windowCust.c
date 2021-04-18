#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void setWindowSize(){
	system("mode 64, 30");
	SMALL_RECT WinRect = {0, 0, 1000, 1000};
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
}

void setFontSize(){
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    fontInfo.dwFontSize.X = 7;
    fontInfo.dwFontSize.Y = 15;
    fontInfo.FontWeight = 600;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &fontInfo);
}
