#include "Algorithms_Functions.h"
#include <iostream>
#include <Windows.h>

using namespace std;
int i = 0;
int j = 0;

void CreateArray(int arr[], int n,sf::RectangleShape rect[])
{
	float x = ((lenght - 20) / n) - 4;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
		float y = -(arr[i] + 5)* (height - 150) / maxValue;
		rect[i].setSize(sf::Vector2f(x, y));
	}
}

void swap(sf::RectangleShape *a, sf::RectangleShape *b)
{
	float x = a->getSize().x;
	float by = b->getSize().y;
	float ay = a->getSize().y;
	a->setSize(sf::Vector2f(x, by));
	b->setSize(sf::Vector2f(x, ay));
}

bool quickSort(sf::RectangleShape rect[], int low, int high, sf::RenderWindow& window, int size, sf::Sprite& sprite)
{
	int pivot = rect[high].getSize().y;
	rect[high].setFillColor(sf::Color(90, 80, 210));
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (rect[j].getSize().y < pivot)
		{
			i++;
			swap(rect[i], rect[j]);
			rect[i].setFillColor(sf::Color(0, 240, 160));
			rect[j].setFillColor(sf::Color(0, 220, 120));
		}
		else
		{
			rect[i].setFillColor(sf::Color(230, 80, 90));
			rect[j].setFillColor(sf::Color(80, 100, 190));
		}
		window.clear(sf::Color(155, 155, 155));

		for (int k = 0; k < size; k++)
		{
			rect[k].setPosition(sf::Vector2f(10 + k * (window.getSize().x - 20) / size, window.getSize().y - 113));
			window.draw(rect[k]);
			if (!(k > low && k <= high))
				rect[k].setFillColor(sf::Color::White);
		}
		window.draw(sprite);
		window.display();
		Sleep(25 / (size / 10));
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
	}
	swap(rect[i + 1], rect[high]);
	rect[i + 1].setFillColor(sf::Color::Yellow);
	rect[high].setFillColor(sf::Color::Yellow);

	int pi = (i + 1);
	if (low < pi - 1)
		quickSort(rect, low, pi - 1, window, size, sprite);
	if (pi + 1 < high)
		quickSort(rect, pi + 1, high, window, size, sprite);

	return 1;
}

bool bubbleSort(sf::RectangleShape rect[], sf::RenderWindow & window, int size, sf::Sprite& sprite)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			rect[j].setFillColor(sf::Color(80, 100, 190));
			rect[j + 1].setFillColor(sf::Color(230,80,90));
			if (rect[j].getSize().y > rect[j + 1].getSize().y)
			{
				swap(&rect[j], &rect[j + 1]);
				rect[j + 2].setFillColor(sf::Color(0, 220, 130));
			}
			Sleep(100/(size));
			window.clear(sf::Color(155, 155, 155));
			for (int t = 0; t < size; t++)
			{
				if (t > size - i - 1)
					rect[t].setFillColor(sf::Color(0, 240, 160));
				rect[t].setPosition(sf::Vector2f(10 + t * (window.getSize().x - 20) / size, window.getSize().y - 113));
				window.draw(rect[t]);
				rect[t].setFillColor(sf::Color::White);
			}
			window.draw(sprite);
			window.display();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
			}
		}
	}
	
	return true;
}

bool mergeSort(sf::RectangleShape rect[], int const begin, int const end,int size,sf::RenderWindow& window, sf::Sprite& sprite)
{
	if (begin >= end)
		return 0;

	auto mid = (end + begin) / 2;
	mergeSort(rect, begin, mid, size, window, sprite);
	mergeSort(rect, mid + 1, end, size, window, sprite);
	merge(rect, begin, mid, end, size, window,sprite);


	return 1;
}
void merge(sf::RectangleShape rect[], int const left, int const mid, int const right,int size, sf::RenderWindow& window, sf::Sprite& sprite)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	auto *leftArray = new sf::RectangleShape[subArrayOne],
		*rightArray = new sf::RectangleShape[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = rect[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = rect[mid + 1 + j];

	auto indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;


	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne].getSize().y <= rightArray[indexOfSubArrayTwo].getSize().y) {
			rect[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			rect[indexOfMergedArray].setFillColor(sf::Color(0, 230, 150));
		}
		else {
			rect[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			rect[indexOfMergedArray].setFillColor(sf::Color(0, 230, 150));
		}
		indexOfMergedArray++;
		rect[left].setFillColor(sf::Color(230, 80, 90));
		rect[right].setFillColor(sf::Color(230, 80, 90));
		rect[mid].setFillColor(sf::Color(80, 100, 190));
		window.clear(sf::Color(155, 155, 155));

		for (int t = 0; t < size; t++)
		{
			rect[t].setPosition(sf::Vector2f(10 + t * (window.getSize().x - 20) / size, window.getSize().y - 113));
			window.draw(rect[t]);
		}
		window.draw(sprite);
		window.display();
		Sleep(25 / (size / 10));
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
	}

	while (indexOfSubArrayOne < subArrayOne) {
		rect[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
		rect[indexOfMergedArray].setFillColor(sf::Color::Yellow);
		while (indexOfSubArrayTwo < subArrayTwo) {
			rect[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
			rect[indexOfMergedArray].setFillColor(sf::Color::Yellow);
		}
	}
	rect[left].setFillColor(sf::Color(230, 80, 90));
	rect[right].setFillColor(sf::Color(230, 80, 90));
	rect[mid].setFillColor(sf::Color(80, 100, 190));
	window.clear(sf::Color(155, 155, 155));

	for (int t = 0; t < size; t++)
	{
		rect[t].setPosition(sf::Vector2f(10 + t * (window.getSize().x - 20) / size, window.getSize().y - 113));
		window.draw(rect[t]);
		rect[t].setFillColor(sf::Color::White);
	}
	window.draw(sprite);
	window.display();
	Sleep(10);
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
	}
}


