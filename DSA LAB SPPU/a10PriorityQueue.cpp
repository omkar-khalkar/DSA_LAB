
/*
Consider a scenario for Hospital to cater services to different kinds of patients as Serious (top priority),
 b) non-serious (medium priority),
 c) General Checkup (Least priority).
Implement the priority queue to cater services to the patients.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class node
{
public:
    int priority;
    char name[10];
    node *next;
} *front = NULL;

void insert()
{
    node *temp, *ptr;
    int  ip;

    temp = new node;

    cout << "\n ENTER NAME: ";
    cin >> temp->name;

    cout << "\n\nENTER THE PRIORITY \n1 for emergency\n2 for visiting\n3 for regulsr checkup \n4 for medicine\n ENTER : ";
    cin >> ip;

    temp->priority = ip;

    if (front == NULL || ip < front->priority)
    {
        temp->next = front;
        front = temp;
    }
    else
    {
        ptr = front;
        while (ptr->next != NULL && ptr->next->priority <= ip)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delet()
{
    struct node *temp;
    if (front == NULL)
    {
        cout << "\n\nNO MORE PATIENTS\n";
    }
    else
    {
        temp = front;
        cout << "\n\nDELETED TOKEN NUMBER  %d\n", temp->name;
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        cout << "\n\nLIST IS EMPTY,NO PATIENTS\n";
    }
    else
    {
        cout << "PRIORITY\tNAME\n\n";
        while (ptr != NULL)
        {
            cout <<ptr->priority<<"\t\t "<< ptr->name<<" \n\n ";
            ptr = ptr->next;
        }
    }
}
int main()
{
    int choice;

    while (1)
    {
        cout << "\n\n--------------------------- HOSPITAL TOKEN MANAGEMENT SYSTEM-------------------------------------\n\n";
        cout << "1.ADMISSION BASED ON PRIORITY\n\n";
        cout << "2.REMOVE VISITED PATIENT\n\n";
        cout << "3.DISPLAY THE LIST ALONG WITH THEIR PRIORITY\n\n";
        cout << "4.EXIT.\n\n";
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delet();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "INVALID CHOICE TRY AGAIN\n";
        }
    }
}