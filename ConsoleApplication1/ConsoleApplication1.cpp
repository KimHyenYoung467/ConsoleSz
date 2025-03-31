#include <iostream>
#include "GameScene.h"
#include "Player.h"
#include "Time.h"
#include "Input.h"

//char* map = (char*)malloc(sizeof(char) * (mapsize.map_x * mapsize.map_y)); 
//ConsoleRender::ScreenWidth() * ConsoleRender::ScreenHeight()
//char* map = (char*)malloc(sizeof(char) * ConsoleRender::ScreenWidth() * ConsoleRender::ScreenHeight());




int main()
{
    srand(time(NULL));  // 랜덤 시드 설정
    RunGame(); 
}

