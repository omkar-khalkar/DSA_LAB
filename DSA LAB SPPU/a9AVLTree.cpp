/*
 * C++ program to Implement AVL Tree
 */
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
// #define pow2(n) (1 << (n))
using namespace std;

/*
  Node Declaration
 */

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root;
/*
 * Class Declaration
 */
class avlTree
{
    node* root;
public:
    int height(node *);
    int diff(node *);
    node *rr_rotation(node *);
    node *ll_rotation(node *);
    node *lr_rotation(node *);
    node *rl_rotation(node *);
    node *balance(node *);
    node *insert(node *, int);
    void display(node *, int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    avlTree()
    {
        root = NULL;
    }
};

/*
 * Main Contains Menu
 */
int main()
{
    int choice, item;
    avlTree avl;
    while (1)
    {
        cout << "\n---------------------" << endl;
        cout << "AVL Tree Implementation" << endl;
        cout << "\n---------------------" << endl;
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.Display Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.display(root, 1);
            break;
        case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(root);
            cout << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}

/*
 * Height of AVL Tree
 */
int avlTree::height(node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/*
 * Height Difference
 */
int avlTree::diff(node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

/*
 * Right- Right Rotation
 */
node *avlTree::rr_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
node *avlTree::ll_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
node *avlTree::lr_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

/*
 * Right- Left Rotation
 */
node *avlTree::rl_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

/*
 * Balancing AVL Tree
 */
node *avlTree::balance(node *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

/*
  Insert Element into the tree
 */
node *avlTree::insert(node *root, int value)
{
    if (root == NULL)
    {
        root = new node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance(root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
}

/*
 * Display AVL Tree
 */
void avlTree::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout << "Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout << "        ";
        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}

/*
 * Inorder Traversal of AVL Tree
 */
void avlTree::inorder(node *tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    cout << tree->data << "  ";
    inorder(tree->right);
}
/*
 * Preorder Traversal of AVL Tree
 */
void avlTree::preorder(node *tree)
{
    if (tree == NULL)
        return;
    cout << tree->data << "  ";
    preorder(tree->left);
    preorder(tree->right);
}

/*
 * Postorder Traversal of AVL Tree
 */
void avlTree::postorder(node *tree)
{
    if (tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << "  ";
}

// H  I  J  B  A  E  C  F  D  G  K  L
// 8  9 10  2  1  5  3  6  4  7 11 12