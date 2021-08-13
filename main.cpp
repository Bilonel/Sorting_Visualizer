#include "Algorithms_Functions.h"
#include <string>

//#include "Algorithm.h"


using namespace std;

int main()
{
	srand(time(NULL));
	
	int arr[350];
	sf::RectangleShape rect[350];
	int size;

	sf::RenderWindow window(sf::VideoMode(lenght, height), "Sort Algorithm Visualezer");
	
	sf::Texture texture;
	texture.loadFromFile("res/texture.png");
	sf::Sprite sprite(texture);
	sprite.setPosition(0, height-sprite.getTexture()->getSize().y);

	Button buttons[10];
	for(int k=0;k<3;k++)
		buttons[k] = Button(sf::Vector2f(540+k*192, height - 103), 135, 32); //merge,quick,bubble
	buttons[3] = Button(sf::Vector2f(1113, height - 103), 180, 32); // Create New Array
	for(int i=0;i<4;i++)
		buttons[4+i] = Button(sf::Vector2f(330+39*i, height - 97), 39, 20); // 50,100,200,300

	sf::RectangleShape line(sf::Vector2f(30, 2));

	bool flagBubble = 0;
	bool flag = true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (buttons[4].isClicked(window))
			{
				size = 50;
				line.setPosition(333, height - 77);
			}
			else if (buttons[5].isClicked(window))
			{
				size = 100;
				line.setPosition(371, height - 77);
			}
			else if (buttons[6].isClicked(window))
			{
				size = 200;
				line.setPosition(411, height - 77);
			}
			else if (buttons[7].isClicked(window))
			{
				size = 300;
				line.setPosition(452, height - 77);
			}
			else if (buttons[3].isClicked(window))
			{
				CreateArray(arr, size, rect);
				flag = false;
				flagBubble = 0;
			}
		}
		
		if (!flag)
		{
			if (flagBubble)
				flag = bubbleSort(rect, window, size,sprite);
			else if (buttons[0].isClicked(window))
				flag = mergeSort(rect, 0, size - 1, size, window,sprite);
			else if (buttons[1].isClicked(window))
				flag = quickSort(rect, 0, size - 1, window, size,sprite);
			else if (buttons[2].isClicked(window))
				flagBubble = true;
			else
			{
				window.clear(sf::Color(155, 155, 155));

				for (int k = 0; k < size; k++)
				{
					rect[k].setPosition(sf::Vector2f(10 + k * (window.getSize().x - 20) / size, height-113));
					window.draw(rect[k]);
				}
				window.draw(sprite);
				window.draw(line);
				window.display();
			}
		}	
		
		else
		{
			window.clear(sf::Color(155, 155, 155));
			for (int k = 0; k < size; k++)
			{
				rect[k].setPosition(sf::Vector2f(10 + k * (window.getSize().x - 20) / size, height - 113));
				rect[k].setFillColor(sf::Color::White);
				window.draw(rect[k]);
			}				
			window.draw(sprite);
			window.draw(line);
			window.display();
		}
	}

	return 0;
}