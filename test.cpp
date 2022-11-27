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
	void update_id(int x)
	{
		id = x;
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
	// fflush(stdin);
	cout << "\n  Enter Employee Name: ";
	cin >> ws;
	getline(cin, name);
	// fflush(stdin);
	cout << "\n  Enter Employee Designation: ";
	// cin >> des;
	getline(cin, des);
	// fflush(stdin);
	cout << "\n  Enter Employee Department: ";
	// cin >> dep;
	getline(cin, dep);
	// fflush(stdin);
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
		// system("clear");
		cout << "\n  1.Add Employee Info.";
		cout << "\n  2.Delete Employee Info.";
		cout << "\n  3.Edit Employee Info";
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
}

// void edit_info()
// {
// 	int id;
// 	cout << " Enter ID to modify : ";
// 	cin >> id;

// 	file.open("data.dat", ios::in | ios::out | ios::binary);
// 		while(file.read((char *)&emp, sizeof(emp)));
// 		{
// 			if(emp.get_id() == id){
// 				//string n;
// 				int id;
// 				cin>>id;
// 				cout<<" Enter New Name : ";
// 			//	cin>>n;
// 				emp.update_id(id);    //update name
// 				int pos = sizeof(emp);
// 				file.seekp(-pos, ios::cur);
// 				file.write((char *)&emp, sizeof(emp));
// 			}

// 		}
// 		file.close();
// }
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
