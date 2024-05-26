// String
#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;


class String
{
private:
	int size; // Размер строки в байтах
	char* str; // Адрес строки в динамической памяти

public:

	const char* get_str()const
	{
		return str;
	}

	char* get_str()
	{
		return str;
	}

	int get_size()const
	{
		return this->size;
	}
	
	// Constructors
	explicit String(int size = 80):size(size), str(new char[size]{})
	{
		//this->size = size;
		//this->str = new char[size]{};
		cout << "DefaultConstructor:\t" << this << endl;
	}

	String(const char* str): size(strlen(str)+1), str(new char[size]{})
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size];
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		cout << "1ArgConstructor:\t" << this << endl;
	}

	String(const String& other):size(other.size), str(new char[size]{})
	{
		//this->size = other.size;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	String(String&& other):size(other.size), str(other.str)
	{
		// Shallow Copy
		//this->size = other.size;
		//this->str = other.str;
		//MoveConstructor работает противоположно CopyConstructor

		other.str = nullptr;
		other.size = 0;
		cout << "MoveConstructor:\t" << this << endl;

	}

	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}

	// Methods
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << this << endl;
	}
	
	// Operators
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	char operator[](int i) const
	{
		return str[i];
	}

	char& operator[](int i)
	{
		return str[i];
	}

	/*
	String operator=(char* other)
	{
		int count = 0;
		while (other[count]) { count++; }

		char* line = new char[count + 1] {};
		for (int i = 0; i < count; i++) line[i] = other[i];
		line[count] = '\0';

		this->set_string(line);

		delete[] line;
		
		return *this;
	}

	std::ostream& print(std::ostream& os = std::cout)const
	{
		if (line) os << line;
		else os << " ";
		os << endl;
		return os;
	}
	*/

};


String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + left.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
	}
		
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i+left.get_size() - 1] = right[i];
	}

	return cat;
}



std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os<<obj.get_str();
}

/*
std::istream& operator>>(std::istream& is, String& obj)
{
	const int SIZE = 256;
	char buffer[SIZE]{};
	is >> buffer;
	
	int count = 0;
	while (buffer[count]) { count++; }

	char* line = new char[count+1]{};
	for (int i = 0; i < count; i++) line[i] = buffer[i];
	line[count] = '\0';

	obj.set_string(line);

	delete[] line;
	return is;
}
*/

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#if defined CONSTRUCTORS_CHECK
	String str; // DefaultConstructor
	str.print();

	String str1 = "Hello"; // 1ArgConstructor
	cout << str1 << endl;
	
	String str2 = str1; // CopyConstructor
	cout << str2 << endl;

	String str3; // DefaultConstructor
	str3 = str2; // CopyAssignment
	cout << str3 << endl;
#endif


	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	str1 = str1;
	cout << str1 << endl;

	String str3; 
	str3 = str1 + str2;
	cout << str3 << endl;

}