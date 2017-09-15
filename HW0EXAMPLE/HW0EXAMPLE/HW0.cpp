//connor harber
//9/15/2017
//this code shows an example of how copy and move constructors can be used..
// Provided code for copy constructor below given by geeks for geeks.com 
//Url:http://www.geeksforgeeks.org/copy-constructor-in-cpp/
//changed information to make it more understandable for me, and closely resemble my way of "thinking".
#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
	char *stri;
	int size;
public:
	String(const char *str = NULL); //  Object constructor
	~String() { delete[] stri; }// Object destructor
	String(const String&); // copy constructor
	String(String&&); // move constructor
	void print() { cout << stri << endl; } // Function to print string
	void change(const char *);  // Function to change
};

int main()
{
	String str1("This is the original info");
	String str2 = str1; // sets str2 to str1
	

	str1.print(); //Prints original string 1
	str2.print(); //Prints original string 2

	String&& str3 = move(str1);  //"should" remove info from str1 into str3 by calling move
	str2.change("This is new A");
	str1.print();
	str2.print();
	str3.print();

	
	return 0;
}


String::String(const char *str) // Constructor
{
	size = strlen(str);
	stri = new char[size + 1];
	strcpy(stri, str);
}

void String::change(const char *str)//Changes the data from given string to new info
{
	delete[] stri;
	size = strlen(str);
	stri = new char[size + 1];
	strcpy(stri, str);
}

String::String(const String& old_str) // Copies but keeps old String
{
	size = old_str.size;
	stri = new char[size + 2];
	strcpy(stri, old_str.stri);
}

String::String(String&& old_str) //Copies the information then deletes the information from old object(this case the "Old String")
{
	size = old_str.size;
	stri = new char[size + 2];
	strcpy(stri, old_str.stri);
	memset(&old_str, 0, sizeof(old_str));
}