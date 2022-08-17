// HEADER RAYCAST FILE
#include "included.cpp"
#include "player.h"
#include "map.h"
#pragma once

class raycast
{
private:
	mapc map;
	int raysMAX = 160;
	int rays;
	float fov = 3.14596f / 3.0f;
	float half_fov = fov / 2.0f;
	float depthMAX = 1350.0f;
	float depth;
	float fov_a = fov / raysMAX;
	float co = 540;
	float color = 1;
	Vector2f ray;
	
public:

	void render(RenderWindow& window, player& player);
	
};
