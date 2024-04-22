#include<iostream>
#include<math.h>
using namespace std;

class Point       // Создаём структуру 'Point', которая будет описывать точки на плоскости
{
private:
	double x;
	double y;

public:
	double get_x()const { return x; }
	double get_y()const { return y; }

	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }

	double distance(Point point)
	{
		return sqrt(((this->get_x() - point.get_x()) * (this->get_x() - point.get_x())) + ((this->get_y() - point.get_y()) * (this->get_y() - point.get_y())));
	}
};

double distance(Point A, Point B);

//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
#if defined STRUCT_POINT
	cout << "Hello OOP" << endl;

	int a;            // Объявление переменной 'a' типа int
	Point A;          // Объявление переменной 'A' типа Point
	                  // Создание объекта 'A' структуры 'Point'
					  // Создание экземпляра структуры 'Point'

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(Point) << endl;
	cout << sizeof(A) << endl;

	Point* pA = &A;
	cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif

	Point A;
	A.set_x(0);
	A.set_y(0);
	cout << "Координаты текущей точки A:" << endl;
	cout << A.get_x() << "\t" << A.get_y() << endl << endl;

	Point B;
	double input = 0;
	cout << "Введите координату 'x' точки 'B' = "; cin >> input;
	B.set_x(input);
	cout << "Введите координату 'y' точки 'B' = "; cin >> input;
	B.set_y(input);
	cout << "Координаты заданной точки 'B':" << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl << endl;

	cout << "Расстояние от текущей точки 'A' до заданной точки 'B' = " << A.distance(B) << endl << endl;
	cout << "Расстояние между точками 'A' и 'B' = " << distance(A, B) << endl << endl;

}

double distance(Point A, Point B)
{
	return sqrt(((A.get_x() - B.get_x()) * (A.get_x() - B.get_x())) + ((A.get_y() - B.get_y()) * (A.get_y() - B.get_y())));
}