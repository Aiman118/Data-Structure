#include <iostream>

using namespace std;

class Employee {
public:
    int number;
    string name;
    double salary;

    Employee(int num, string name, double salary) {
        this->number = num;
        this->name = name;
        this->salary = salary;
    }
};

class Node {
public:
    Employee* data;
    Node* left;
    Node* right;

    Node(Employee* employee) {
        this->data = employee;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(Employee* newEmployee) {
        root = insertRec(root, newEmployee);
    }

    Node* insertRec(Node* root, Employee* newEmployee) {
        if (root == nullptr) {
            return new Node(newEmployee);
        }

        if (newEmployee->number < root->data->number) {
            root->left = insertRec(root->left, newEmployee);
        } else if (newEmployee->number > root->data->number) {
            root->right = insertRec(root->right, newEmployee);
        }

        return root;
    }

    Employee* search(int number) {
        return searchRec(root, number);
    }

    Employee* searchRec(Node* root, int number) {
        if (root == nullptr || root->data->number == number) {
            return root->data;
        }

        if (number < root->data->number) {
            return searchRec(root->left, number);
        } else {
            return searchRec(root->right, number);
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int number) {
        if (root == nullptr) {
            return root;
        }

        if (number < root->data->number) {
            root->left = deleteNode(root->left, number);
        } else if (number > root->data->number) {
            root->right = deleteNode(root->right, number);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data->number);
        }
        return root;
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << "Number: " << root->data->number << ", Name: " << root->data->name << ", Salary: " << root->data->salary << endl;
            inorderTraversal(root->right);
        }
    }

    void preorderTraversal(Node* root) {
        if (root != nullptr) {
            cout << "Number: " << root->data->number << ", Name: " << root->data->name << ", Salary: " << root->data->salary << endl;
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void postorderTraversal(Node* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << "Number: " << root->data->number << ", Name: " << root->data->name << ", Salary: " << root->data->salary << endl;
        }
    }
};

int main() {
    BST bst;

    bst.insert(new Employee(10, "Aiman", 50000));
    bst.insert(new Employee(5, "Shezy", 30000));
    bst.insert(new Employee(15, "Inuu", 60000));
    bst.insert(new Employee(3, "Ibi", 20000));
    bst.insert(new Employee(8, "Yafi", 40000));

    cout << "In-order Traversal:\n";
    bst.inorderTraversal(bst.root);

    cout << "\nPre-order Traversal:\n";
    bst.preorderTraversal(bst.root);

    cout << "\nPost-order Traversal:\n";
    bst.postorderTraversal(bst.root);

    Employee* foundEmployee = bst.search(15);
    if (foundEmployee != nullptr) {
        cout << "\nFound Employee: " << foundEmployee->name << endl;
    } else {
        cout << "\nEmployee not found." << endl;
    }

    bst.deleteNode(bst.root, 10);
    cout << "\nAfter deleting employee with number 10:\n";
    bst.inorderTraversal(bst.root);

    return 0;
}