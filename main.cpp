#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class employee
{
	int id;
	string name;
	string des;
	string dep;

public:
	void get_info();
	void put_info();

	int get_id()
	{
		return id;
	}
	void update_name(string n)
	{
		name = n;
	}
	void update_des(string d)
	{
		des = d;
	}
	void update_dep(string de)
	{
		dep = de;
	}
}; // Class End

void employee ::get_info(void)
{

	cout << "\n  Enter Employee ID: ";
	cin >> id;
	cout << "\n  Enter Employee Name: ";
	cin >> ws;
	getline(cin, name);
	cout << "\n  Enter Employee Designation: ";
	getline(cin, des);
	cout << "\n  Enter Employee Department: ";
	getline(cin, dep);
}
void employee ::put_info(void)
{

	cout << "\n Showing Employee Info\n";
	cout << "\n Employee ID : " << id;
	cout << "\n Name        : " << name;
	cout << "\n Designation : " << des;
	cout << "\n Department  : " << dep << endl;
}

void add_info(void);
void delete_info(void);
void edit_info(void);
void search_info(void);
void show_info(void);

employee emp;
fstream file;

int main()
{
	int coh = 0;
	while (coh != 6)
	{
		cout << "\n  1.Add Employee Info.";
		cout << "\n  2.Delete Employee Info.";
		cout << "\n  3.Modify Employee Info";
		cout << "\n  4.Search Employee Info.";
		cout << "\n  5.Display Employee Info. ";
		cout << "\n  6.Exit Program. \n";

		cout << "\n  Enter Your Choice: ";
		cin >> coh;
		switch (coh)
		{

		case 1:
		{
			system("clear");
			add_info();
			break;
		}
		case 2:
		{
			system("clear");
			delete_info();
			break;
		}
		case 3:
		{
			system("clear");
			edit_info();
			break;
		}

		case 4:
		{
			system("clear");
			search_info();

			break;
		}

		case 5:
		{
			system("clear");
			show_info();
			break;
		}
		case 6:
		default:
		{
			system("clear");
			cout << "   #### Invalid Choice ####" << endl;
			break;
		}
		}
	}
	// remove("date.dat");
	return 0;
}
void add_info()
{
	file.open("data.dat", ios::app | ios::binary);
	emp.get_info();
	file.write((char *)&emp, sizeof(emp));

	file.close();
}
void delete_info()
{
	int id;
	cout << "Enter Id to Delete : ";
	cin >> id;
	ofstream file2;
	file2.open("dtemp.dat", ios::out | ios::binary);
	file.open("data.dat", ios::in | ios::binary);

	file.read((char *)&emp, sizeof(emp));
	while (!file.eof())
	{
		if (id != emp.get_id())
		{
			file2.write((char *)&emp, sizeof(emp));
		}
		file.read((char *)&emp, sizeof(emp));
	}
	
	file2.close();
	file.close();
	remove("date.dat");
	rename("dtemp.dat", "data.dat");
	cout << " Info Deleted Successfully" << endl;
}

void edit_info()
{
	int id, flag = 0;
	file.open("data.dat", ios::in | ios::binary | ios::out);
	cout << "Enter Id to Modify : ";
	cin >> id;
	file.read((char *)&emp, sizeof(emp));
	while (!file.eof())
	{
		if (id == emp.get_id())
		{
			flag = 1;
			cout << " Edit Name? (Y/N): ";
			char c;
			cin >> c;
			if (c == 'Y' or c == 'y')
			{
				string n;
				cout << " Enter New Name : ";
				cin >> ws;
				cin >> n;
				emp.update_name(n);
				file.seekp(-sizeof(emp), ios::cur);
				file.write((char *)&emp, sizeof(emp));
			}
			cout << " Edit Designation? (Y/N): ";
			char ch;
			cin >> ch;
			if (ch == 'Y' or ch == 'y')
			{
				string n;
				cout << " Enter New Designation : ";
				cin >> ws;
				cin >> n;
				emp.update_des(n);
				file.seekp(-sizeof(emp), ios::cur);
				file.write((char *)&emp, sizeof(emp));
			}
			cout << " Edit Depertment? (Y/N): ";
			char che;
			cin >> che;
			if (che == 'Y' or che == 'y')
			{
				string n;
				cout << " Enter New Depertment : ";
				cin >> ws;
				cin >> n;
				emp.update_dep(n);
				file.seekp(-sizeof(emp), ios::cur);
				file.write((char *)&emp, sizeof(emp));
			}
			break;
		}
		file.read((char *)&emp, sizeof(emp));
	}
	if (flag == 0)
	{
		cout << " Employee Info Not Found " << endl;
	}
	file.close();
}
void search_info()
{
	int id, flag = 0;
	file.open("data.dat", ios::in | ios::binary);
	cout << "Enter Id to search : ";
	cin >> id;
	file.read((char *)&emp, sizeof(emp));
	while (!file.eof())
	{
		if (id == emp.get_id())
		{
			flag = 1;
			emp.put_info();
			file.read((char *)&emp, sizeof(emp));
			break;
		}
		file.read((char *)&emp, sizeof(emp));
	}
	if (flag == 0)
	{
		cout << " Employee Info Not Found " << endl;
	}
	file.close();
}
void show_info()
{
	file.open("data.dat", ios::in | ios::binary);
	file.read((char *)&emp, sizeof(emp));
	while (!file.eof())
	{
		emp.put_info();
		file.read((char *)&emp, sizeof(emp));
	}
	file.close();
}
