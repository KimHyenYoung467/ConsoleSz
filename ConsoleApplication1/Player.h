#pragma once
#include "GameScene.h"
#include "Renderer.h"
#include "ConsoleRenderer.h"
#include "Input.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	int x;
	int y;
	int score; 
	bool isAttack; 
} Player;

extern bool GameQuit;

void EscapeKeyInput();

void InitPlayer();
void PlayerAttackCheck();

void PlayerKeyUpdate();

void MoveCheck(int x, int y); 
void ProcessInput();
//void MovePlayerLeft();
//void MovePlayerRight(); 
//void MovePlayerJump(); 

#endif 