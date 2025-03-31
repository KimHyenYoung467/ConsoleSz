#pragma once
#include "Renderer.h"
#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Gamesystems.h"

#ifndef SCENE_H
#define SCENE_H

typedef enum {
		MENU, 
		PLAY, 
		END 
} SceneType;

extern char map[ScreenHeight][ScreenWidth];

void RunGame(); 
void ShowScene();
void UpateScene();

SceneType GetCurrentScene();
SceneType SetCurrentScene(SceneType nextScene); 

// UI Components 
extern bool isActive; 

//void MapSetInit(); 
void MapSetInit();
void PrintMap();

#endif // !SCENE_H 
