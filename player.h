// HEADER PLAYER FILE
#include "included.cpp"
#include "map.h"
#pragma once

struct player
{
	// PLAYER SETTINGS
	CircleShape playerS;
	Vector2f playerPos;
	Vector2f moving;
	Vector2f movingR;
	float playerA = 0.0f;
	float playerDX = cosf(playerA);
	float playerDY = sinf(playerA);
	mapc map;

	player()
	{
		playerS.setRadius(5.0f);
		playerS.setPosition(250.0f, 300.0f);
		playerS.setFillColor(Color::Magenta);
		playerS.setOutlineThickness(5.0f);
		playerS.setOutlineColor(Color::Cyan);

		playerPos = playerS.getPosition();
	}

	void playerMove(float smooth);

};

