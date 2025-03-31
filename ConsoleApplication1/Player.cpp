#include "Player.h"

Player player = { 3, ScreenHeight - 3 , 0, false };


void InitPlayer()
{
	player.x = 3;
	player.y = ScreenHeight - 3;
	player.score = 0;
	player.isAttack = false; 
	
}

void PlayerAttackCheck()
{
	float time = Time::GetDeltaTime();

	if (player.x == 'S' && player.y == 'S')
	{
		player.isAttack = true;
		player.score++; 
	}
	else if (player.x == 'F' && player.y == 'F')
	{
		player.isAttack = true; 
		player.score--; 
		time -= 3.0f;
	}
}

// 게속 키 검사 하고, 키에 따라서 플레이어의 위치를 변경한다. 
void PlayerKeyUpdate()
{
	//MovePlayerLeft();
	//MovePlayerRight();
	ProcessInput();
	EscapeKeyInput();
	
}

void MoveCheck(int x, int y)
{
	// 범위 체크 
	if (x < 0 || x >= ScreenWidth - 1) return; 
	if (y < 0 || y >= ScreenHeight - 3) return; 

	// 벽 체크 하기 
	if (map[y][x] == 1) return; 

	// 기존 위치 정리 
	map[player.y][player.x] = 0; 
	
	// 새 위치로 이동하기 
	player.x = x; 
	player.y = y; 
	map[player.y][player.x] = 3;
}

void EscapeKeyInput()
{
	if (Input::IsKeyDown(VK_ESCAPE))
	{
		GameQuit = true;

		ConsoleRender::ScreenClear();
	}
}

//void MovePlayerLeft()
//{
//	if (Input::IsKeyDown(VK_LEFT))
//	{
//		if (player.x > 0)
//			player.x--;
//	}	
//}
//
//void MovePlayerRight()
//{
//	if (Input::IsKeyDown(VK_RIGHT))
//	{
//		if (player.x < ScreenWidth - 1)
//			player.x++;
//	}
//}

//void MovePlayerJump()
//{
//	if (Input::IsKeyDown(VK_SPACE))
//	{
//		if (player.y <= 2)
//		{
//			player.y += 2.0f; 
//		}
//	}
//	else if (Input::IsKeyReleased(VK_SPACE))
//	{
//		if (player.y <= 2)
//		{
//			player.y -= 2.0f;
//		}
//	}
//}
void ProcessInput()
{
	MoveCheck(player.x, player.y);

	if (Input::IsKeyDown(VK_LEFT)) { //����
		player.x--;
	}
	else if (Input::IsKeyPressed(VK_LEFT) && Input::IsKeyDown(VK_UP)) {
		player.x++;
		player.y++;
		if ((Input::IsKeyPressed(VK_LEFT) || Input::IsKeyReleased(VK_LEFT)) && Input::IsKeyReleased(VK_UP))
			player.y--;
	}
	else if (Input::IsKeyDown(VK_RIGHT)) { //������
		player.x++;
	}
	else if (Input::IsKeyPressed(VK_RIGHT) && Input::IsKeyDown(VK_UP)) {
		player.x++;
		player.y++;
		if ((Input::IsKeyPressed(VK_RIGHT) && Input::IsKeyReleased(VK_UP)))
			player.y--;
	}
	else if (Input::IsKeyDown(VK_UP)) { //��
		player.y--;
	}
	else if (Input::IsKeyDown(VK_DOWN)) { //�Ʒ�
		player.y++;
	}
	else if (Input::IsKeyDown(VK_ESCAPE)) { //����
		GameQuit = true;
	}
}