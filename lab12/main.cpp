#include <iostream>

using namespace std;

struct node {
    int key;
    node* parent;
    node* left;
    node* right;
};

node* make_node(int value) {
    auto* n = new node;
    n->key = value;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;

    return n;
}

void add_node(node*& root, int value) {
    if (root == nullptr) {
        root = make_node(value);
        return;
    }

    node* temp = root;
    while (true) {
        if (temp->key > value) {
            if (temp->left == nullptr) {
                temp->left = make_node(value);
                temp->left->parent = temp->left;
                return;
            }
            else {
                temp = temp->left;
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = make_node(value);
                temp->right->parent = temp->right;
                return;
            }
            else {
                temp = temp->right;
            }
        }
    }
}

void preorder(node *root)
{
    if(root != nullptr)
    {
        cout << root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key<<" ";
    }
}

void inorder(node* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

node* find_node(node* root, int value) {
    node* temp = root;
    while (temp != nullptr) {
        if (temp->key == value) {
            return temp;
        } else if (temp->key > value) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return nullptr;
}

node* find_successor(node* n) {
    if (n->right != nullptr) {
        n = n->right;
        while (n->left != nullptr) {
            n = n->left;
        }

        return n;
    }

    node* temp = n->parent;
    while (temp != nullptr && temp->left != n) {
        n = temp;
        temp = temp->parent;
    }

    return temp;
}

void delete_node(node*& root, node* n) {
    node* temp1 = nullptr;
    node* temp2 = nullptr;

    if (n->left == nullptr || n->right == nullptr) {
        temp1 = n;
    } else {
        temp1 = find_successor(n);
    }


    if (temp1->left != nullptr) {
        temp2 = temp1->left;
    } else {
        temp2 = temp1->right;
    }

    if (temp2 != nullptr) {
        temp2->parent = temp1->parent;
    }

    if (temp1->parent == nullptr) {
        root = temp2;
    } else {
        if (temp1 == temp1->parent->left) {
            temp1->parent->left = temp2;
        } else {
            temp1->parent->right = temp2;
        }
    }

    if (temp1 != n) {
        n->key = temp1->key;
    }

    delete temp1;
}

int main()
{
    node* tree = nullptr;

    int choice;
    do {
        cout << "Menu:"<<endl
             << "1. Sprawdz czy drzewo jest puste"  <<endl
             << "2. Dodaj element do drzewa"        <<endl
             << "3. Sprawdz czy element istnieje"   <<endl
             << "4. Wyswietl drzewo preorder"       <<endl
             << "5. Wyswietl drzewo inorder"        <<endl
             << "6. Wyswietl drzewo postorder"      <<endl
             << "7. Usun element z drzewa"          <<endl
             << "8. Usun cale drzewo"               <<endl
             << "9. Wyjdz z programu"               <<endl;
        cin >> choice;

        int value;
        node* element;

        switch (choice) {
            case 1:
                if (tree == nullptr) {
                    cout << "Drzewo jest puste." << endl;
                } else {
                    cout << "Drzewo nie jest puste." << endl;
                }
                continue;

            case 2:
                cout << "Podaj wartosc: ";
                cin >> value;

                cout << "Drzewo przed dodaniem: ";
                inorder(tree);
                cout << endl;

                add_node(tree, value);
                cout << "Drzewo po dodaniu: ";
                inorder(tree);
                cout << endl;
                continue;

            case 3:
                cout << "Podaj szukana wartosc: ";
                cin >> value;
                element = find_node(tree, value);
                if (element != nullptr) {
                    cout << "Element istnieje" << endl;
                } else {
                    cout << "Element nie istnieje." << endl;
                }
                continue;

            case 4:
                preorder(tree);
                cout << endl;
                break;


            case 5:
                inorder(tree);
                cout << endl;
                break;


            case 6:
                postorder(tree);
                cout << endl;
                break;

            case 7:
                cout << "Podaj wartosc: ";
                cin >> value;

                element = find_node(tree, value);
                if (element == nullptr) {
                    cout << "Dany element nie istnieje." <<endl;
                } else {
                    cout <<"Przed usunieciem: "<<endl;
                    inorder(tree);
                    delete_node(tree, element);
                    cout <<endl<<"Po usunieciu: "<<endl;
                    inorder(tree);
                    cout <<endl<<endl;
                }
                break;


            case 8:
                while(tree != nullptr)
                {
                    element = find_node(tree, value);
                    delete_node(tree,element);
                }
                break;


            case 9:
                break;

        }
    } while (choice != 9);

    return 0;
}