// NOTE: Compile this file with g++ compiler
// Type in console
//    g++ -o program play_pianotiles.cpp -lgdi32
//    start program
// to start this script.
// Then go to piano tiles 2 game
// (can be found by link below)
//  https://www.microsoft.com/en-us/p/piano-tiles-2/9pg27qb44xq5?activetab=pivot:overviewtab)
// Start a level and enjoy!
//
// NOTE: the script may do not see the tiles sometimes
// But this is going to be fixed and optimized in future versions
//
// NOTE: the script works for some time then shuts down
// due to probability of the script not to finish

#include <iostream>
#include "Windows.h"

#define TILE_Y_COORD 800

using namespace std;

const int TILE_X_COORD[] = {732, 883, 1034, 1185};

struct Point
{
    int x, y;
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

void ClickOnPoint(Point __point)
{
    SetCursorPos(__point.x, __point.y);
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, __point.x, __point.y, 0, 0);
}

void ScanForTiles(HDC screen)
{
    for (int i = 0; i < 4; ++i)
    {
        Point current(TILE_X_COORD[i], TILE_Y_COORD);
        COLORREF pixel_color = GetPixel(screen, current.x, current.y);
        if (GetRValue(pixel_color) < 150 && GetGValue(pixel_color) < 150 && GetBValue(pixel_color) < 150)
            ClickOnPoint(current);
    }
}

int main()
{
    size_t k = 0;
    HDC screen = GetDC(NULL);
    Sleep(10000);//time to switch the window
    while (k <= 1e7)//emergency exit
    {
        ScanForTiles(screen);
        ++k;
    }
    return 0;
}
