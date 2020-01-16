#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	/*rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);*/

	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setRadius(50);
	circle.setPosition(window->getSize().x * .5, window->getSize().y * .5);

	rect1.setSize(sf::Vector2f(100, 100));
	rect1.setFillColor(sf::Color::Red);
	rect1.setPosition(50, 50);

	rect2.setSize(sf::Vector2f((rect1.getSize().x * .66), (rect1.getSize().y * .66)));
	rect2.setFillColor(sf::Color::Green);
	rect2.setPosition(rect1.getPosition().x + (rect1.getSize().x * (1.0 / 6.0)), rect1.getPosition().y + (rect1.getSize().x * (1.0 / 6.0)));

	rect3.setSize(sf::Vector2f((rect2.getSize().x * .66), (rect2.getSize().y * .66)));
	rect3.setFillColor(sf::Color::Blue);
	rect3.setPosition(rect2.getPosition().x + (rect2.getSize().x * (1.0 / 6.0)), rect2.getPosition().y + (rect2.getSize().x * (1.0 / 6.0)));

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "frik";
	}

	text.setFont(font);
	text.setString("hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Cyan);

};


Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	bottomRect.setSize(sf::Vector2f(20, 20));
	bottomRect.setPosition(window->getSize().x - bottomRect.getSize().x, window->getSize().y - bottomRect.getSize().y);
	bottomRect.setFillColor(sf::Color::Green);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(circle);
	window->draw(text);
	window->draw(bottomRect);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}