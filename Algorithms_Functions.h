#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
const int maxValue = 1000;
const float lenght = 1600;
const float height = 1200;

void CreateArray(int arr[], int n, sf::RectangleShape rect[]);
void swap(sf::RectangleShape *a, sf::RectangleShape *b);
bool quickSort(sf::RectangleShape rect[], int low, int high, sf::RenderWindow& window, int size, sf::Sprite& sprite);
bool bubbleSort(sf::RectangleShape rect[], sf::RenderWindow& window, int size, sf::Sprite& sprite);
bool mergeSort(sf::RectangleShape rect[], int const begin, int const end, int size, sf::RenderWindow& window, sf::Sprite& sprite);
void merge(sf::RectangleShape rect[], int const left, int const mid, int const right, int size, sf::RenderWindow& window, sf::Sprite& sprite);


class Button
{
private:
	sf::FloatRect collider;	
public:
	Button(){}
	Button(sf::Vector2f pos, int w, int h)
	{
		collider = sf::FloatRect(pos, sf::Vector2f(w,h));
		
	}
	bool isClicked(sf::RenderWindow& window)
	{
		sf::Vector2i mspos = sf::Mouse::getPosition(window);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && collider.contains(sf::Vector2f(mspos.x, mspos.y)))
			return true;
		return false;
	}
};
