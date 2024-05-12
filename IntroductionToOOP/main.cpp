#include<iostream>
//#include<math.h>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------------\n"

namespace MySpace
{
	int a = 22;
}

struct AnyPoint
{
	double x;
	double y;
};

class Point       
{
private:
	double x;
	double y;
	
public:
	double get_x()const { return x; }
	double get_y()const { return y; }

	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }
	
	// Constructors
	/*
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	*/

	/*
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}
	*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	// Methods
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		//other.y *= 10;
		//this->y *= 10;
		double distance = sqrt(x_distance* x_distance + y_distance* y_distance);

		return distance;
		//return sqrt(((this->get_x() - other.get_x()) * (this->get_x() - other.get_x())) + ((this->get_y() - other.get_y()) * (this->get_y() - other.get_y())));
	}

	void Print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);

	return distance;
	//return sqrt(((A.get_x() - B.get_x()) * (A.get_x() - B.get_x())) + ((A.get_y() - B.get_y()) * (A.get_y() - B.get_y())));
}

//#define STRUCT_ANY_POINT
//#define DISTANCE_CHECK
//#define LIFETIME
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello OOP" << endl << endl;

#if defined STRUCT_ANY_POINT
	int a;		//Объявление переменной 'a' типа 'int'
	AnyPoint A;	//Объявление переменной 'A' типа 'Point'
	//Создание объекта 'A' структуры 'Point'
	//Создание экземпляра структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(Point) << endl;
	cout << sizeof(A) << endl;

	AnyPoint* pA = &A;
	cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_ANY_POINT

#if defined DISTANCE_CHECK
	Point A;          

	A.set_x(2);
	A.set_y(3);
	cout << "Координаты текущей точки A:" << endl;
	cout << A.get_x() << "\t" << A.get_y() << endl << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "Координаты точки B:" << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl << endl;

	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками  'А' и 'В': " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками  'B' и 'A': " << distance(B, A) << endl;
	cout << delimiter << endl;
	/*
	double input = 0;
	cout << "Введите координату 'x' точки 'B' = "; cin >> input;
	B.set_x(input);
	cout << "Введите координату 'y' точки 'B' = "; cin >> input;
	B.set_y(input);
	cout << "Координаты заданной точки 'B':" << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl << endl;

	cout << "Расстояние от текущей точки 'A' до заданной точки 'B' = " << A.distance(B) << endl << endl;
	cout << "Расстояние между точками 'A' и 'B' = " << distance(A, B) << endl << endl;
	*/


#endif // DISTANCE_CHECK

#if defined LIFETIME
	for (int i = 0; i < 10; i++)
	{
		cout << i << '\t';
	}
	cout << endl;
	int a = 2;
	{
		int a = 3;
	}
	cout << MySpace::a << endl;
#endif // LIFITIME

#if defined CONSTRUCTORS_CHECK
	Point A;
	A.Print();

	Point B = 5;
	//Point B(5);
	B.Print();

	Point C(2, 3);
	C.Print();

	Point D = C;
	D.Print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	//Point A(2, 3);
	//Point B = A; // CopyConstructor
	//Point B;
	//B = A; // CopyAssignment

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.Print();
	B.Print();
	C.Print();
	/*
	Point(2, 3); здесь явно вызывается конструктор и создаётся временный безымянный объект
	*/
#endif
}





