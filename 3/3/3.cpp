#include <iostream>
#include <conio.h>
#include<TCHAR.H>

class Point {//создаю класс
protected:
	int x, y;
public:
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
	void move(int dx, int dy) {//реализация метода в определении 
		x = x + dx;
		y = y + dy;
	}
	void reset();//определение метода

};
void Point::reset() {// реализация метода после определения
	x = 0;
	y = 0;

}
class Point3D : public Point{//создаю класс
protected:
	int z;
public:
	Point3D() {// конструктор
		printf("Point3D()\n");// отладочный вывод
		z = 0;

	}

	Point3D(int x, int y, int z) {//конструктор с парамметрами
		printf("Point3D(int x,int y, int z)\n");
		this->z = z;

	}

	Point3D(const Point3D& p) {// копирующий конструктор
		printf("(const Point3D &p)\n");
		x = p.x;
		y = p.y;
		z = p.z;

	}
	~Point3D() {// деструктор
		printf("%d, %d, %d\n", x, y, z);
		printf("~Point3D()\n");
	}
	void moveZ(int dz) {
		z = z + dz;
	}
	

};

int _tmain(int argc, _TCHAR* argv[])
{
	Point3D* p = new Point3D;
	Point* p1 = new Point3D;
	

	delete p;
	delete p1;
	return 0;
}