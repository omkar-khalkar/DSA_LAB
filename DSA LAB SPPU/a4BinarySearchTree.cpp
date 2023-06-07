#include <iostream>
using namespace std;

struct node {
    node* left = NULL;
    node* right = NULL;
    int data;
};

class bst {
public:
    bool flag;
    node* root = NULL;
    void add();
    void insert(node* root, node* n);  // Added function declaration
    void display(node* root);
    void minmax(node* root);
    void search(node* root, int key);
    void mirror(node* root);
    int height(node* root);
    void check(bool flag);
};

void bst::add() {
    int value;
    cout << "Enter data: ";
    cin >> value;
    node* n = new node;
    n->data = value;
    if (root == NULL) {
        root = n;
    } else {
        insert(root, n);
    }
}

void bst::insert(node* root, node* n) {
    if (n->data < root->data) {
        if (root->left == NULL) {
            root->left = n;
        } else {
            insert(root->left, n);
        }
    } else {
        if (root->right == NULL) {
            root->right = n;
        } else {
            insert(root->right, n);
        }
    }
}

void bst::display(node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

void bst::minmax(node* root) {
    node* temp;
    temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    cout << "\nMinimum Element: " << temp->data << endl;
    temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    cout << "Maximum Element: " << temp->data << endl;
}

void bst::mirror(node* root) {
    if (root != NULL) {
        node* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
}

void bst::search(node* root, int key) {
    flag = false;
    if (root != NULL) {
        if (key == root->data) {
            flag = true;
            return;
        } else if (key < root->data) {
            search(root->left, key);
        } else {
            search(root->right, key);
        }
    } else {
        return;
    }
}

void bst::check(bool flag) {
    if (flag == true) {
        cout << "Element found!!\n";
    } else {
        cout << "Element not found!!\n";
    }
}

int bst::height(node* root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

int main() {
    bst b;
    int ch;
    char ctn = 'y';
    do {
        cout << "1. To add\n2. To display\n3. To minMax\n4. To search\n5. To mirror\n6. Height\n0. To exit\n";
        cout << "Enter your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                while (ctn == 'y') {
                    b.add();
                    cout << "Do you want to continue (y/n): ";
                    cin >> ctn;
                }
                break;
            case 2:
                b.display(b.root);
                cout << endl;
                break;
            case 3:
                b.minmax(b.root);
                cout << endl;
                break;
            case 4:
                int ele;
                cout << "Enter the element to be searched: ";
                cin >> ele;
                b.search(b.root, ele);
                b.check(b.flag);
                cout << endl;
                break;
            case 5:
                b.mirror(b.root);
                b.display(b.root);
                cout << endl;
                break;
            case 6:
                cout << "Height is " << b.height(b.root) << endl;
                break;
        }
    } while (ch != 0);
}
