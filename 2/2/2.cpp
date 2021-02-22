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

	Point(const Point& p) {// копирующий конструктор
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
{//создание динамических объектов
	Point* p = new Point;
	Point* p2 = new Point(10, 20);
	Point* p3 = new Point(*p2);

	delete p;//обязательное удаление, 
	delete p2;//так как объекты созданы динамически
	delete p3;
	
	
	return 0;
}