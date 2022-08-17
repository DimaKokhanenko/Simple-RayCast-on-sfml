#include "included.cpp"
#include "player.h"
#include "raycast.h"

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Pseudo 3d engine");

	player player;
	raycast raycast;
	
	Clock clock;
	
	while (window.isOpen())
	{
		float smooth = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		smooth = smooth / 800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); };

		window.clear(Color(100, 120, 140));

		player.playerMove(smooth);
		raycast.render(window, player);
		
		window.display();
	}
	
	return 0;
}
