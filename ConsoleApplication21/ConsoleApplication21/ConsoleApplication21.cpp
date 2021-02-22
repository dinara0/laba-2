#include <iostream>


class Point {//создаю класс
public:
	int x, y;
	Point() {// конструктор
		printf("Point()\n");// отладочный вывод
		x = 0;
		y = 0;
	}

	Point(int x, int y) {//конструктор с парамметрами
		printf("Point(int x,int y)\n");
		this->x = x;
		this->y = y;

	}

	Point(const Point &p) {// копирующий конструктор
		printf("(const Point &p)\n");
		x = p.x;
		y = p.y;

	}
	~Point() {// деструктор
		printf("%d, %d\n", x, y);
		printf("~Point()\n");
	}
};

int main()
{
	{//статические объекты
		Point p;//вызывает конструктор без параметров
		Point p2(1, 2);//вызывает конструктор с параметрами
		Point p3(p2);//вызывает копирующий конструктор
		}
	return 0;
	

}
