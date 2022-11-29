#include <SFML/Graphics.hpp>

using namespace sf;
const float SC_WIDTH = 800;
const float SC_HEIGHT = 600;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SC_WIDTH, SC_HEIGHT), "SFML Works!");
	float radius = 250.f;
	/*float radius1 = 200.f;
	float radius2 = 150.f;
	float radius3 = 100.f;
	float radius4 = 50.f;*/
	CircleShape c1(radius);
	CircleShape c11(40.f);
	CircleShape c12(40.f);
	/*CircleShape c2(radius1);
	CircleShape c3(radius2);
	CircleShape c4(radius3);
	CircleShape c5(radius4);*/
	c1.move((SC_WIDTH - 2*radius)/2, (SC_HEIGHT - 2* radius)/2);
	c11.move(SC_WIDTH -340, SC_HEIGHT -400 );
	c12.move(SC_WIDTH - 540, SC_HEIGHT - 400);
	/*c2.move((SC_WIDTH - 2 * radius1) / 2, (SC_HEIGHT - 2 * radius1) / 2);
	c3.move((SC_WIDTH - 2 * radius2) / 2, (SC_HEIGHT - 2 * radius2) / 2);
	c4.move((SC_WIDTH - 2 * radius3) / 2, (SC_HEIGHT - 2 * radius3) / 2);
	c5.move((SC_WIDTH - 2 * radius4) / 2, (SC_HEIGHT - 2 * radius4) / 2);*/
	float dx = 100.f;
	RectangleShape rect[5];
	for (int i = 0; i < 5; i++) {
		rect[i].setSize(Vector2f(50.f, 50.f));
		rect[i].move(0,dx * i);
		rect[i].setFillColor(Color { (Uint8)(50 * i),(Uint8)(rand() % 256), (Uint8)(rand() % 256) });
	}
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		
		c11.setFillColor(Color(139, 69, 19));
		c12.setFillColor(Color(139, 69, 19));
		c1.setFillColor(Color(218, 165, 32));
		/*c2.setFillColor(Color(30, 144, 255));
		c3.setFillColor(Color(65, 105, 225));
		c4.setFillColor(Color(0, 0, 255));
		c5.setFillColor(Color(0, 0, 139));
		window.draw(c1);
		window.draw(c2);
		window.draw(c3);
		window.draw(c4);
		window.draw(c1);*/
		/*window.draw(c1);
		window.clear(Color::Blue);
		window.draw(c11);
		window.draw(c12);*/
		for (int i = 0; i < 5; i++) {
			window.draw(rect[i]);
		}
		window.display();
	}

	return 0;
}
