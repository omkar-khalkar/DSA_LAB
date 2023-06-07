#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class file
{

    struct stud
    {
        int roll;
        char name[10];
        char div;
        char add[10];
    } rec;

    // stud rec;
public:
    void create();
    void del();
    int search();
    void display();
};

void file::create()
{
    ofstream fout;
    char ch;
    fout.open("practice.txt", ios::out);
    
    do
    {
        cout << "\n--- Add Student Record ---\n";
        cout << "Roll No: ";
        cin >> rec.roll;
        cout << "Name: ";
        cin >> rec.name;
        cout << "Division: ";
        cin >> rec.div;
        cout << "Address: ";
        cin >> rec.add;

        fout.write((char *)&rec, sizeof(stud));

        cout << "Record added successfully!\n";
        cout << "Do you want to add another record? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    
    fout.close();
}


void file::display()
{
    ifstream fin;
    fin.open("practice.txt", ios::in);
    fin.seekg(0, ios::beg);

    while (fin.read((char *)&rec, sizeof(stud)))
    {
        if (rec.roll != -1)
        {
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
        }
    }

    fin.close();
}

void file::del()
{
    fstream f;
    int r;
    f.open("practice.txt", ios::in | ios::out);

    f.seekg(0, ios::beg);

    cout << "\n\nEnter roll no to delete: ";
    cin >> r;
    int i = 0;
    while (f.read((char *)&rec, sizeof(stud)))
    {
        if (r == rec.roll)
        {
            break;
        }
        i++;
    }

    int off;
    off = i * sizeof(rec);
    f.seekp(off);
    rec.roll = -1;
    strcpy(rec.name, "NULL");
    strcpy(rec.add, "NULL");
    rec.div = 'N';

    cout << "\nRecord deleted!!" << endl;

    f.write((char *)&rec, sizeof(rec));

    f.close();
}

int file::search()
{
    fstream f;
    int r;
    bool flag = false;
    f.open("practice.txt", ios::in | ios::out);

    f.seekg(0, ios::beg);

    cout << "\nEnter roll no : ";
    cin >> r;

    while (f.read((char *)&rec, sizeof(stud)))
    {

        if (r == rec.roll)
        {
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            flag = true;
        }
    }

    if (flag == false)
    {
        cout << "\nrecord not found";
    }
}

int main()
{
    file obj;
    int choice;

    do
    {
        cout << "\n----- Menu -----\n";
        cout << "1. Create records\n";
        cout << "2. Display records\n";
        cout << "3. Search record\n";
        cout << "4. Delete record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                obj.create();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.search();
                break;
            case 4:
                obj.del();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
