#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root; 
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    
    bool searchRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }
    TreeNode* findMin(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            
            if (current->left == nullptr) {
                TreeNode* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                TreeNode* temp = current->left;
                delete current;
                return temp;
            }
            
            TreeNode* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteRecursive(current->right, temp->data);
        }

        return current;
    }

    void clearRecursive(TreeNode* node) {
        if (node != nullptr) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        clear();
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    void clear() {
        clearRecursive(root);
        root = nullptr;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(7);
    bst.insert(12);

    cout << "Searching for elements in the BST:\n";
    cout << "Element 10 " << (bst.search(10) ? "found\n" : "not found\n");
    cout << "Element 6 " << (bst.search(6) ? "found\n" : "not found\n");

    cout << "\nDeleting element 10 from the BST:\n";
    bst.remove(10);
    cout << "Element 10 " << (bst.search(10) ? "found\n" : "not found\n");

    return 0;
}