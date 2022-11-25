#include <iostream>
using namespace std;
class employee
{
    //Done
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
    employee(int a, string s, string sa, string sb)
    {
        id = a;
        name = s;
        desg = sa;
        dept = sb;
    }
    void display()
    {
        cout << "\n Showing Employee Info\n";
        cout << "\n Employee ID : " << id;
        cout << "\n Name        : " << name;
        cout << "\n Designation : " << desg;
        cout << "\n Department  : " << dept << endl;
    }
    int getid()
    {
        return id;
    }
    //if modified
    void setename(string nm)
    {
        name = nm;
    }
    void setdes(string des)
    {
        desg = des;
    }
};
class node
{
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

class company
{
    node *start;

public:
    company()
    {
        start = NULL;
    }
    // Add Employee
    void addemp(employee e)
    {
        node *temp = new node(e);
        temp->setnext(start);
        start = temp;
    }

    // Display Employee Info

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
    // Search
    void search(int id)
    {
        node *p = start;
        while (p != NULL)
        {
            employee e1 = p->getdata();
            if (e1.getid() == id)
            {
                cout << "\n Employee Found ...";
                e1.display();
                return;
            }
            p = p->getnext();
        }
        cout << "\n Employee not Found ..."<<endl;
    }
    // Delete
    void Remove(int id)
    {
        if (start == NULL)
        {
            cout << "\nNo employee data is here \n";
            return;
        }
        node *p = start;
        if (id == p->getdata().getid())
        {
            start = start->getnext();
            p->getdata().display();
            cout << "\n This employee is deleted ...";
            delete p;
            return;
        }
        if (p->getnext() == NULL)
        {
            cout << "\n Not Found ";
            return;
        }
    }
    // Modify
    void editinfo(int id)
    {
        if (start == NULL)
        {
            cout << "\n No Employee is here";
            return;
        }
        node *p = start;
        while (p != NULL)
        {
            employee e = p->getdata();
            if (p->getdata().getid() == id)
            {
                employee e = p->getdata();
                char ans;
                string name, des, dep;

                cout << "\n Do you wan change name : (Y/N)";
                cin >> ans;
                if (ans == 'Y' || ans == 'y')
                {
                    cout << "\n Enter New Name : ";
                    cin >> name;
                    e.setename(name);
                }
                cout << "\n Do you wan change Designation : (Y/N)";
                cin >> ans;
                if (ans == 'Y' || ans == 'y')
                {
                    cout << "\n Enter new Designation : ";
                    cin >> des;
                    e.setdes(des);
                }
                p->setdata(e);
                return;
            }
            p = p->getnext();
        }

        cout << "\n Employee not Found ";
    }
};
int main()
{
    company ob;
    int coh = 0;
    while (coh != 6)
    {
        cout << "\n  1.Add Employee.";
        cout << "\n  2.Display Employee Info.";
        cout << "\n  3.Search info.";
        cout << "\n  4.Delete.";
        cout << "\n  5.Edit Employee data. ";
        cout << "\n  6.Exit Program. \n";

        cout << "\n  Enter Your Choice: ";
        cin >> coh;
        switch (coh)
        {

        case 1:
        {
            int id;
            string name;
            string desg;
            string dept;
            cout << "\n  Enter Employee ID: ";
            cin >> id;
            cout << "\n  Enter Employee Name: ";
            cin >> name;
            cout << "\n  Enter Employee Designation: ";
            cin >> desg;
            cout << "\n  Enter Employee Department: ";
            cin >> dept;
            employee emp1(id, name, desg, dept);
            ob.addemp(emp1);
        }
        break;
        case 2:
            ob.DisplayallEmp();
            break;
        case 3:
        {
            int id;
            cout << "\nEnter the id to search : ";
            cin >> id;
            ob.search(id);
        }
        break;
        case 4:
        {
            int id;
            cout << "\nEnter the id to Delete  : ";
            cin >> id;
            ob.Remove(id);
        }
        break;
        case 5:
        {
            int id;
            cout << "\n Enter id to edit info : ";
            cin >> id;
            ob.editinfo(id);
        }
        break;
        case 6:
        break;
        default:
            cout<<"     ##### Invalid Choice #####";
            break;
        }
    }
    return 0;
}
