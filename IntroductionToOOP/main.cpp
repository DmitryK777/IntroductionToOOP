#include<iostream>
using namespace std;

class Point       // ������ ��������� 'Point', ������� ����� ��������� ����� �� ���������
{

	double x;
	double y;

public:
	double get_x()const
	{
		return x;
	}

	double get_y()const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}

	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
#if defined STRUCT_POINT
	cout << "Hello OOP" << endl;

	int a;            // ���������� ���������� 'a' ���� int
	Point A;          // ���������� ���������� 'A' ���� Point
	                  // �������� ������� 'A' ��������� 'Point'
					  // �������� ���������� ��������� 'Point'

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
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
}