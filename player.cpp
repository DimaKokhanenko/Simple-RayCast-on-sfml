// UNDER HEADER PLAYER FILE
#include "player.h"

void player::playerMove(float smooth)
{
	int forcollisionX = int(playerPos.x + playerDX) / 64;
	int forcollisionY = int(playerPos.y + playerDY) / 64;
	int forcollisionXR = int(playerPos.x + -playerDX) / 64;
	int forcollisionYR = int(playerPos.y + -playerDY) / 64;

	if (map.amap[forcollisionX + forcollisionY * map.mapW] == '#') 
	{
		moving.x = 0;
		moving.y = 0;
		//playerPos.x -= 1;
		//playerPos.y -= 1;
	}
	else
	{
		moving.x = playerDX * smooth / 4.0f;
		moving.y = playerDY * smooth / 4.0f;
	}

	if (map.amap[forcollisionXR + forcollisionYR * map.mapW] == '#') 
	{
		movingR.x = 0;
		movingR.y = 0;
		playerPos.x -= -(playerDX * smooth / 4.0f) * 2;
		playerPos.y -= -(playerDY * smooth / 4.0f) * 2;
	}
	else
	{
		movingR.x = -(playerDX * smooth / 4.0f);
		movingR.y = -(playerDY * smooth / 4.0f);
	}
	
	if (Keyboard::isKeyPressed(Keyboard::A)) { playerA -= 0.006f * smooth; playerDX = cosf(playerA); playerDY = sinf(playerA); };
	if (Keyboard::isKeyPressed(Keyboard::D)) { playerA += 0.006f * smooth; playerDX = cosf(playerA); playerDY = sinf(playerA); };
	if (Keyboard::isKeyPressed(Keyboard::W)) { playerS.move(moving);playerPos = playerS.getPosition(); };
	if (Keyboard::isKeyPressed(Keyboard::S)){ playerS.move(movingR); playerPos = playerS.getPosition(); };
}
