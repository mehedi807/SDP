#include<iostream>
using namespace std;
class employee{
   int id;
   string desg;
   string name;
   string dept;
public:
   employee()
   {
       id = 00;
       name = "Null";
       desg = "Null";
       dept = "Null";
   }
   employee(int a, string s,string sa,string sb)
   {
       id = a;
       name = s;
       desg = sa;
       dept = sb;
   }
   void display()
   {
       cout<<"\n Showing Employee Info\n";
       cout<<"\n Employee ID : "<<id;
       cout<<"\n Name        : "<<name;
       cout<<"\n Designation : "<<desg;
       cout<<"\n Department  : \n"<<dept;
   }

};
class node{
    employee data;
    node *next;

    public:
    node(employee dd)
    {
        data = dd;
        next = NULL;
    }
    employee getdata()
    {
        return data;
    }
    node *getnext()
    {
        return next;
    }

    void setdata(employee dd)
    {
        this->data = dd;
    }
    void setnext(node *n)
    {
        this->next = n;
    }
};

class company{
    node *start;

    public:
    company()
    {
        start = NULL;
    }
//Add Employee
    void addemp(employee e)
    {
        node *temp = new node(e);
        temp->setnext(start);
        start = temp;
    }

//Display Employee Info

    void DisplayallEmp()
    {
        if (start == NULL)
        {
            cout << "\n\n No employee data found \n\n";
            return;
        }
        node *p = start;
        while (p != NULL)
        {
            p->getdata().display();
            p = p->getnext();
        }
    }

};
int main()
{
    company ob;
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
               string desg;
               string dept;
               cout<<"\n  Enter Employee ID: ";
               cin>>id;
               cout<<"\n  Enter Employee Name: ";
               cin>>name;
               cout<<"\n  Enter Employee Designation: ";
               cin>>desg;
               cout<<"\n  Enter Employee Department: ";
               cin>>dept;
               employee emp1(id, name, desg, dept);
               ob.addemp(emp1);
           }
           break;
           case 2:
               ob.DisplayallEmp();
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
