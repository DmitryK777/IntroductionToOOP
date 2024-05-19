// Fraction
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;



class Fraction
{
private:
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const { return integer; }
	int get_numerator()const { return numerator; }
	int get_denominator()const { return denominator; }

	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) 
	{ 
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	// Costructors
	Fraction()
	{
		integer = 0 ;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "3ArgConstructor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator++() // Preffix increment
	{
		if (this->integer == 0 && this->numerator < 0) this->numerator = this->denominator - this->numerator;
		else ++this->integer;
		return *this;
	}

	Fraction& operator++(int) // Suffix increment
	{
		Fraction old = *this;

		if (this->integer == 0 && this->numerator < 0) this->numerator = this->denominator - this->numerator;
		else this->integer++;

		return old;
	}

	Fraction& operator--() // Preffix increment
	{
		if (this->integer == 0 && this->numerator > 0) this->numerator -= this->denominator;
		else --this->integer;
		if (this->integer < 0 && this->numerator < 0) this->numerator *= (-1);
		return *this;
	}

	Fraction& operator--(int) // Suffix increment
	{
		Fraction old = *this;

		if (this->integer == 0 && this->numerator > 0) this->numerator -= this->denominator;
		else this->integer--;
		if (this->integer < 0 && this->numerator < 0) this->numerator *= (-1);
		return old;
	}

	Fraction& operator+=(const Fraction& other)
	{
		int denominator = 1;
		int numerator = 0;
		int integer = 0;

		int numerator_left = 0;
		int numerator_right = 0;

		if (this->get_integer() >= 0) numerator_left = (this->get_integer() * this->get_denominator() + this->get_numerator());
		else numerator_left = (this->get_integer() * this->get_denominator() - this->get_numerator());
		if (other.get_integer() >= 0) numerator_right = (other.get_integer() * other.get_denominator() + other.get_numerator());
		else numerator_right = (other.get_integer() * other.get_denominator() - other.get_numerator());
		
		denominator = this->get_denominator() * other.get_denominator();
		
		numerator_left *= other.get_denominator();
		numerator_right *= this->get_denominator();
		numerator = numerator_left + numerator_right;

		integer = numerator / denominator;
		numerator %= denominator;
		if (numerator < 0) numerator *= (-1);

		int max_comon_divider = 1;
		for (int i = 1; i <= numerator; i++)
		{
			if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
		}

		numerator /= max_comon_divider;
		denominator /= max_comon_divider;

		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);

		return *this;
	}

	Fraction& operator-=(const Fraction& other)
	{
		int denominator = 1;
		int numerator = 0;
		int integer = 0;

		int numerator_left = 0;
		int numerator_right = 0;

		if (this->get_integer() >= 0) numerator_left = (this->get_integer() * this->get_denominator() + this->get_numerator());
		else numerator_left = (this->get_integer() * this->get_denominator() - this->get_numerator());
		if (other.get_integer() >= 0) numerator_right = (other.get_integer() * other.get_denominator() + other.get_numerator());
		else numerator_right = (other.get_integer() * other.get_denominator() - other.get_numerator());
		denominator = this->get_denominator() * other.get_denominator();
		numerator_left *= other.get_denominator();
		numerator_right *= this->get_denominator();

		numerator = numerator_left - numerator_right;
		integer = numerator / denominator;
		numerator %= denominator;
		if (numerator < 0) numerator *= (-1);

		int max_comon_divider = 1;
		for (int i = 1; i <= numerator; i++)
		{
			if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
		}

		numerator /= max_comon_divider;
		denominator /= max_comon_divider;

		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);

		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		int denominator = 1;
		int numerator = 0;
		int integer = 0;

		int numerator_left = 0;
		int numerator_right = 0;

		if (this->get_integer() >= 0) numerator_left = (this->get_integer() * this->get_denominator() + this->get_numerator());
		else numerator_left = (this->get_integer() * this->get_denominator() - this->get_numerator());
		if (other.get_integer() >= 0) numerator_right = (other.get_integer() * other.get_denominator() + other.get_numerator());
		else numerator_right = (other.get_integer() * other.get_denominator() - other.get_numerator());

		numerator = numerator_left * numerator_right;
		denominator = this->get_denominator() * other.get_denominator();
		integer = numerator / denominator;
		numerator %= denominator;
		if (numerator < 0) numerator *= (-1);

		int max_comon_divider = 1;
		for (int i = 1; i <= numerator; i++)
		{
			if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
		}

		numerator /= max_comon_divider;
		denominator /= max_comon_divider;

		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);

		return *this;
	}

	Fraction& operator/=(const Fraction& other)
	{
		int denominator = 1;
		int numerator = 0;
		int integer = 0;

		int numerator_left = 0;
		int numerator_right = 0;
		if (this->get_integer() >= 0) numerator_left = (this->get_integer() * this->get_denominator() + this->get_numerator());
		else numerator_left = (this->get_integer() * this->get_denominator() - this->get_numerator());
		if (other.get_integer() >= 0) numerator_right = (other.get_integer() * other.get_denominator() + other.get_numerator());
		else numerator_right = (other.get_integer() * other.get_denominator() - other.get_numerator());

		int denominator_left = this->get_denominator();
		int denominator_right = other.get_denominator();

		numerator = numerator_left * denominator_right;
		denominator = denominator_left * numerator_right;
		integer = numerator / denominator;
		numerator %= denominator;
		if (numerator < 0) numerator *= (-1);

		int max_comon_divider = 1;
		for (int i = 1; i <= numerator; i++)
		{
			if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
		}

		numerator /= max_comon_divider;
		denominator /= max_comon_divider;

		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);

		return *this;
	}

	// Methods
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	int denominator = 1;
	int numerator = 0;
	int integer = 0;

	int numerator_left = 0;
	int numerator_right = 0;

	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());
	denominator = left.get_denominator() * right.get_denominator();
	numerator_left *= right.get_denominator();
	numerator_right *= left.get_denominator();

	numerator = numerator_left + numerator_right;
	integer = numerator / denominator;
	numerator %= denominator;
	if (numerator < 0) numerator *= (-1);

	int max_comon_divider = 1;
	for (int i = 1; i <= numerator; i++)
	{
		if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
	}

	numerator /= max_comon_divider;
	denominator /= max_comon_divider;
	
	result.set_integer(integer);
	result.set_numerator(numerator);
	result.set_denominator(denominator);
	
	return result;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	int denominator = 1;
	int numerator = 0;
	int integer = 0;

	int numerator_left = 0;
	int numerator_right = 0;

	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());
	denominator = left.get_denominator() * right.get_denominator();
	numerator_left *= right.get_denominator();
	numerator_right *= left.get_denominator();

	numerator = numerator_left - numerator_right;
	integer = numerator / denominator;
	numerator %= denominator;
	if (numerator < 0) numerator *= (-1);

	int max_comon_divider = 1;
	for (int i = 1; i <= numerator; i++)
	{
		if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
	}

	numerator /= max_comon_divider;
	denominator /= max_comon_divider;

	result.set_integer(integer);
	result.set_numerator(numerator);
	result.set_denominator(denominator);

	return result;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;

	int denominator = 1;
	int numerator = 0;
	int integer = 0;

	int numerator_left = 0;
	int numerator_right = 0;

	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());

	numerator = numerator_left * numerator_right;
	denominator = left.get_denominator() * right.get_denominator();
	integer = numerator / denominator;
	numerator %= denominator;
	if (numerator < 0) numerator *= (-1);

	int max_comon_divider = 1;
	for (int i = 1; i <= numerator; i++)
	{
		if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
	}

	numerator /= max_comon_divider;
	denominator /= max_comon_divider;

	result.set_integer(integer);
	result.set_numerator(numerator);
	result.set_denominator(denominator);

	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;

	int denominator = 1;
	int numerator = 0;
	int integer = 0;

	int numerator_left = 0;
	int numerator_right = 0;
	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());

	int denominator_left = left.get_denominator();
	int denominator_right = right.get_denominator();

	numerator = numerator_left * denominator_right;
	denominator = denominator_left * numerator_right;
	integer = numerator / denominator;
	numerator %= denominator;
	if (numerator < 0) numerator *= (-1);

	int max_comon_divider = 1;
	for (int i = 1; i <= numerator; i++)
	{
		if (numerator % i == 0 && denominator % i == 0) max_comon_divider = i;
	}

	numerator /= max_comon_divider;
	denominator /= max_comon_divider;

	result.set_integer(integer);
	result.set_numerator(numerator);
	result.set_denominator(denominator);

	return result;
}

bool operator==(const Fraction& left, const Fraction& right)
{
	return (left.get_integer() == right.get_integer() && left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator());
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	if ((left.get_integer() != right.get_integer() || left.get_numerator() != right.get_numerator() || left.get_denominator() != right.get_denominator()))
	{
		return true;
	}
	else return false;
}

bool operator>(const Fraction& left, const Fraction& right)
{
	int numerator_left = 0;
	int numerator_right = 0;

	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());
	
	numerator_left *= right.get_denominator();
	numerator_right *= left.get_denominator();

	return (numerator_left > numerator_right);
}

bool operator<(const Fraction& left, const Fraction& right)
{
	int numerator_left = 0;
	int numerator_right = 0;

	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());

	numerator_left *= right.get_denominator();
	numerator_right *= left.get_denominator();

	return (numerator_left < numerator_right);
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	int numerator_left = 0;
	int numerator_right = 0;

	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());

	numerator_left *= right.get_denominator();
	numerator_right *= left.get_denominator();

	return (numerator_left >= numerator_right);
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	int numerator_left = 0;
	int numerator_right = 0;

	if (left.get_integer() >= 0) numerator_left = (left.get_integer() * left.get_denominator() + left.get_numerator());
	else numerator_left = (left.get_integer() * left.get_denominator() - left.get_numerator());
	if (right.get_integer() >= 0) numerator_right = (right.get_integer() * right.get_denominator() + right.get_numerator());
	else numerator_right = (right.get_integer() * right.get_denominator() - right.get_numerator());

	numerator_left *= right.get_denominator();
	numerator_right *= left.get_denominator();

	return (numerator_left <= numerator_right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer() && obj.get_numerator())
	{
		return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")" << endl;
	}
	else if (obj.get_integer() == 0 && obj.get_numerator())
	{
		return os << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")" << endl;
	}
	else if (obj.get_integer() == 0 && obj.get_numerator() == 0)
	{
		return os << 0 << endl;
	}
	cout << endl;
}


std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;

	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);

	return is;
}

//#define CHECK_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#if defined CHECK_CONSTRUCTORS
	Fraction A; // Default constructor
	A.print();

	Fraction B = 5; // Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D; // Copy constructor
	E.print();

	Fraction F;
	F = E;          // Copy assignment
	F.print(); 
#endif // CHECK_CONSTRUCTORS

	// Сложение
	Fraction A(-2, 3, 5);
	Fraction B(-5, 6, 7);
	Fraction C = A + B;
	C.print();

	// Вычитание
	Fraction D(5, 7, 9);
	Fraction E(3, 1, 3);
	Fraction F = D - E;
	F.print();

	// Умножение
	Fraction H(5, 3, 4);
	Fraction I(7, 1, 7);
	Fraction J = H * I;
	J.print();

	// Деление
	Fraction K(7, 2, 3);
	Fraction L(2, 1, 8);
	Fraction M = K / L;
	M.print();

	// ++
	++K;
	K.print();
	L++;
	L.print();

	// --
	Fraction N(1, 3);
	--N;
	N.print();
	N--;
	N.print();

	// +=
	A += B;
	A.print();

	// ==
	Fraction O(5, 3, 4);
	cout << (O == H) << endl;

	// cin
	Fraction P;
	cout << "Введите целое, числитель и знаминатель дробного числа: "; cin >> P;
	cout << endl;
	cout << P;
} 