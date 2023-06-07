#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

struct node
{
    node *left;
    node *right;
    char data;
};

class et
{
    char prefix[20];

public:
    node *top;

    void expression(char[]);
    void postorder(node *);
};

void et::expression(char prefix[])
{
    char c;
    stack<node *> s;
    node *t1;
    node *t2;
    int len, i;
    len = strlen(prefix);
    for (i = len - 1; i >= 0; i--)
    {
        top = new node;
        top->left = NULL;
        top->right = NULL;
        if (isalpha(prefix[i]))
        {
            top->data = prefix[i];
            s.push(top);
        }
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/')
        {
            t2 = s.top();
            s.pop();
            t1 = s.top();
            s.pop();

            top->data = prefix[i];
            top->left = t2;
            top->right = t1;
            s.push(top);
        }
    }
    top = s.top();
    s.pop();
}
void et::postorder(node *top)
{
    stack<node *> s1, s2;
    node *T = top;
    s1.push(T);
    cout<<endl;
    while (!s1.empty())
    {
        T = s1.top();
        s1.pop();
        s2.push(T);
        if (T->left != NULL)

            s1.push(T->left);

        if (T->right != NULL)

            s1.push(T->right);
    }
    while (!s2.empty())
    {
        top = s2.top();
        s2.pop();
        cout << top->data;
    }
}

int main()
{
    char exp[20];
    et t;
    cout << "Expression :";
    cin >> exp;
    cout << "EXPRESSION IS :" << exp;
    t.expression(exp);
    t.postorder(t.top);
}
