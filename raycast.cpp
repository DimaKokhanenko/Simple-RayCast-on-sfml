// UNDER HEADER RAYCAST FILE
#include "raycast.h"

void raycast::render(RenderWindow& window, player& player)
{
	float rayA = player.playerA - half_fov;

	for (rays = 0; rays < raysMAX; rays++)
	{
		float cos_a = cosf(rayA);
		float sin_a = sinf(rayA);
		for (depth = 0; depth < depthMAX; depth++)
		{
			ray.x = player.playerPos.x + depth * cos_a;
			ray.y = player.playerPos.y + depth * sin_a;

			int mcX = int(ray.x / 64);
			int mcY = int(ray.y / 64);

			if (map.amap[mcX + mcY * map.mapW] == '#')
			{
				depth *= cos(player.playerA - rayA);
				float wallH = (64 * 1485) / depth;
				float wallO = co - wallH / 2;
				color = 200 / (1 + depth * depth * 0.000004f);

				if (Keyboard::isKeyPressed(Keyboard::Up)) { co += 0.1; };
				if (Keyboard::isKeyPressed(Keyboard::Down)) { co -= 0.1; };
				
				RectangleShape wall/*(Vector2f(wallH, 25))*/;
				/*
				VertexArray wall(Lines, 2);
				wall[0].position = Vector2f(rays * 20, wallO);
				wall[1].position = Vector2f(rays * 20, wallH + wallO);*/
				/*
				wall.setPosition(rays * 20, wallO);
				wall.setRotation(90);
				wall.setFillColor(Color::Green);*/

				wall.setSize({ 20, wallH});
				wall.setFillColor(Color(color / 1.2, color / 1.2, color));
				wall.setPosition(rays * 20, wallO);

				window.draw(wall);
				break;
			}
		}
		rayA += fov_a;
	}
}
