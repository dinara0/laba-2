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
	void move(int dx, int dy) {
		x = x + dx;
		y = y + dy;
	}
	void reset();

};
void Point::reset() {
	x = 0;
	y = 0;

}
class Point3D : public Point {//создаю класс
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
	void moveZ(int dx, int dy, int dz) {
		z = z + dz;
	}
	

};

class Section {//создаю класс
protected:
	Point* p1;//указатели на переменные типа Point
	Point* p2;

public:
	Section() {// конструктор
		printf("Section()\n");// отладочный вывод
		p1 = new Point;
		p2 = new Point;
	}

	Section(int x1, int x2, int y1, int y2) {//конструктор с парамметрами
		printf("Section(int x1, int x2, int y1, int y2)\n");
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);


	}

	Section(const Section& s) {// копирующий конструктор
		printf("(const Section &p)\n");
		p1 = new Point(*s.p1);
		p2 = new Point(*s.p2);


	}
	~Section() {// деструктор
		//printf("%d, %d\n", x, y);
		delete p1;
		delete p2;
		printf("~Section()\n");
	}
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	Section* s1 = new Section;
	Section* s2 = new Section(*s1);

	

	delete s1;
	delete s2;

	return 0;
}