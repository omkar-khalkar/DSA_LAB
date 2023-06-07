/*
A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes. Find the time and space requirements of your method.
*/

#include <iostream>
#include <string.h>
using namespace std;

class node // create a node structure
{
public:
    string label;
    int ch_count;
    node *child[10];
};

class GT
{
    node *root;

public:
    GT()
    {
        root = NULL;
    }
    void create_tree();
    void display();
};

void GT::create_tree()
{
    root = new node;
    cout << "\nEnter The Name Of BOOK:";
    cin >> root->label;
    cout << "\nEnter The No. Of Units:";
    cin >> root->ch_count;
    for (int i = 0; i < root->ch_count; i++)
    {
        root->child[i] = new node;
        cout << "\nEnter The Name Of Unit:";
        cin >> root->child[i]->label;
        cout << "\nEnter The No. Of Chapter:";
        cin >> root->child[i]->ch_count;
        for (int j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "\nEnter The Name Of Chapter:";
            cin >> root->child[i]->child[j]->label;
        }
    }
}
void GT::display()
{
    cout << "\nTHE BOOK IS :" << root->label;

    for (int i = 0; i < root->ch_count; i++)
    {
        cout << "\n\tUNIT :" << root->child[i]->label;
        for (int j = 0; j < root->child[i]->ch_count; j++)
        {
            cout << "\n\t\tChapter :" << root->child[i]->child[j]->label;
        }
    }
}

int main()
{
    GT t;
    t.create_tree();
    t.display();
}