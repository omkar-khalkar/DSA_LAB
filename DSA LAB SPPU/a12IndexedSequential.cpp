#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class employee
{
    struct emp
    {
        char name[20];
        int emp_id;
        int salary;
    };

    struct index
    {
        int emp_id;
        int position;
    };
    emp erec;
    index irec;

public:
    void create();
    void display();
    // void search();
    void delet();
};

void employee::create()
{
    int i = 0;
    fstream empfile;
    fstream indexfile;
    empfile.open("emp.txt", ios::in | ios::out | ios::app | ios::binary);
    indexfile.open("index.txt", ios::in | ios::out | ios::app | ios::binary);
    char c = 'y';
    while (c == 'y' || c == 'Y')
    {
        cout << "\nEnter name : ";
        cin >> erec.name;
        cout << "Enter emp_id : ";
        cin >> erec.emp_id;
        cout << "Enter salary : ";
        cin >> erec.salary;

        empfile.write((char *)&erec, sizeof(emp)) << flush;
        irec.emp_id = erec.emp_id;
        irec.position = i;
        indexfile.write((char *)&irec, sizeof(index)) << flush;
        i++;
        cout << "Do you want to add more record(Y/N) : ";
        cin >> c;
    }
    empfile.close();
    indexfile.close();
}

void employee::display()
{

    fstream empfile;
    fstream indexfile;
    empfile.open("emp.txt", ios::in | ios::out | ios::app | ios::binary);
    indexfile.open("index.txt", ios::in | ios::out | ios::app | ios::binary);
    empfile.seekg(0, ios::beg);
    indexfile.seekg(0, ios::beg);

    int offset = 0;
    while (indexfile.read((char *)&irec, sizeof(index)))
    {
        offset = irec.position * sizeof(erec);
        empfile.seekg(offset, ios::beg);

        empfile.read((char *)&erec, sizeof(emp));
        if (erec.emp_id != -1)
        {
            cout << "\nName : " << erec.name << flush;
            cout << "\nEmp_Id: " << erec.emp_id << flush;
            cout << "\nSalary : " << erec.salary << flush;
            cout << endl;
        }
    }
    empfile.close();
    indexfile.close();
}

void employee::delet()
{
    int id;
    int pos;
    cout << "Enter Emp-Id to be deleted : ";
    cin >> id;
    fstream empfile;
    fstream indexfile;
    empfile.open("emp.txt", ios::in | ios::out | ios::binary);
    indexfile.open("index.txt", ios::in | ios::out | ios::binary);
    empfile.seekg(0, ios::beg);
    indexfile.seekg(0, ios::beg);
    pos = -1;

    while (indexfile.read((char *)&irec, sizeof(index)))
    {
        if (id == irec.emp_id)
        {
            pos = irec.position;
            irec.emp_id = -1;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Record not found!!!";
        return;
    }

    int offset = pos * sizeof(emp);
    empfile.seekp(offset);
    strcpy(erec.name, "");
    erec.emp_id = -1;
    erec.salary = -1;
    empfile.write((char *)&erec, sizeof(emp)) << flush;

    offset = pos * sizeof(index);
    indexfile.seekp(offset);
    irec.emp_id = -1;
    irec.position = pos;
    indexfile.write((char *)&irec, sizeof(index));
    empfile.seekg(0);
    indexfile.close();
    empfile.close();
    cout << "Record deleted !!";
}
int main()
{
    employee obj;
    int ch, key;
    char ans = 'y';
    do
    {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Exit";
        cout << "\n\tEnter Your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.delet();
            break;
        case 4:
            cout << "Program ended";
            return -1;
            break;
        }
    } while (ans == 'y' || ans == 'Y');
    return 0;
}