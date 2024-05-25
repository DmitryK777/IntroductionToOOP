// String
#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;


class String
{
private:
	const char* line;

public:
	const char* get_string()const { return line; }
	void set_string(const char* arr) { this->line = line; }
	void set_string(char* line) { this->line = line; }
	

	// Constructors
	String()
	{
		const int SIZE = 80;
		this->line[80];
	}
	
	String(const char* line)
	{
		this->line = line;
	}
	
	String(char* line)
	{
		this->line = line;
	}
	
	// Operators

	String operator=(const char* other)
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
};

String operator+(const String& left_str, const String& right_str)
{
	const char* left = left_str.get_string();
	const char* right = right_str.get_string();

	int count_left = 0;
	int count_right = 0;

	while (left[count_left]) { count_left++; }
	while (right[count_right]) { count_right++; }

	char* line = new char[count_left + count_right + 2];
	for (int i = 0; i < count_left; i++) line[i] = left[i];
	line[count_left] = ' ';
	for (int i = 0; i < count_right; i++) line[count_left + 1 + i] = right[i];
	line[count_left + count_right + 1] = '\0';
	
	String buffer(line);
	//delete[] line;
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return obj.print(os);
}

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

void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;

	delete[] str3.get_string();
}