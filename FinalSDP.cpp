#include<iostream>
using namespace std;
class employee{
    int id;
    int salary;
    string name;
public:
    employee()
    {
        id = 00;
        name = "Null";
        salary = 00;
    }
    employee(int a, string s, int sal)
    {
        id = a;
        name = s;
        salary = sal;
    }
};
int main()
{
    int coh = 0;
    while(coh!=6)
    {
        cout << "\n  1.Add Employee.";
        cout << "\n  2.Display Employee Info.";
        cout << "\n  3.Search info.";
        cout << "\n  4.Delete.";
        cout << "\n  5.Edit Employee data. \n";
        cout<<"\n  Enter Your Choice: ";
        cin>>coh;
        switch(coh)
        {
            case 1:
            {
                int id;
                string name;
                int salary;
                cout<<"\n  Enter Employee ID: ";
                cin>>id;
                cout<<"\n  Enter Employee Name: ";
                cin>>name;
                cout<<"\n  Enter Employee Salary: ";
                cin>>salary;
                employee emp1(id, name, salary);
            }
            break;
            case 2:
                display();
                break;
            case 3:
            {
                
            }
            break;
            case 4:
            {
                
            }
            break;
            case 5:
            {
                
            }
            break;
        }
            
    }
    return 0;
    
}