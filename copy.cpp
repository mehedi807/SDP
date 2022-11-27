// C++ program to modify the content
// of a binary file

#include <bits/stdc++.h>
using namespace std;

class abc {
	int roll;
	char name[20];

public:
	void getdata(int, char[]);
	void update(int, int, char[]);
	void testcase1();
	void testcase2();
	void putdata();
};

// Code to display the data of the
// data of the object
void abc::putdata()
{
	cout << "roll no: ";
	cout << roll;
	cout << "\nname: ";
	cout << name;
}

// Code to set the value to the object
void abc::getdata(int a, char str[])
{
	// setting the new roll no
	roll = a;

	// setting new name
	strcpy(name, str);
}

void abc::update(int rno, int r, char str[])
{
	// code to update and modify
	// the content of the binary file
	int pos, flag = 0;

	// rno=9
	fstream fs;
	fs.open("he.dat",
			ios::in | ios::binary | ios::out);

	while (!fs.eof()) {
		// storing the position of
		// current file pointeri.e. at
		// the end of previously read record
		pos = fs.tellg();

		fs.read((char*)this, sizeof(abc));
		if (fs) {

			// comparing the roll no with that
			// of the entered roll number
			if (rno == roll) {
				flag = 1;

				// setting the new (modified )
				// data of the object or new record
				getdata(r, str);

				// placing the put(writing) pointer
				// at the starting of the record
				fs.seekp(pos);

				// writing the object to the file
				fs.write((char*)this, sizeof(abc));

				// display the data
				putdata();
				break;
			}
		}
	}
	fs.close();

	if (flag == 1)
		cout << "\nrecord successfully modified \n";
	else
		cout << "\nrecord not found \n";
}

// Sample input 1
void abc::testcase1()
{
	int rno, r;
	char name[20];

	// roll no to be searched
	rno = 1;

	// new roll no
	r = 11;

	// new name
	strcpy(name, "Geek");

	// call update function with new values
	update(rno, r, name);
}

// Sample input 2
void abc::testcase2()
{
	int rno, r;
	char name[20];

	// roll no to be searched
	rno = 4;

	// new roll no
	r = 14;

	// new name
	strcpy(name, "Geek2");

	// call update function with the new values
	update(rno, r, name);
}

// Driver code
int main()
{
	abc s;

	// sample case 1
	s.testcase1();

	// sample case 2
	s.testcase2();

	return 0;
}
