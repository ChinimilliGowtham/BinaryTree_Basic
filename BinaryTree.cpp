#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
private:
    vector<int> tree;
public:
    BinaryTree(int size) {
        tree.resize(size, -1); // Initialize tree with -1 (assuming -1 is not a valid node value)
    }

    void insert(int value, int index = 0) {
        if (tree[index] == -1) {
            tree[index] = value;
        }
        else {
            if (value < tree[index]) {
                insert(value, 2*index + 1);
            }
            else {
                insert(value, 2*index + 2);
            }
        }
    }

    void inorderTraversal(int index = 0) {
        if (index < tree.size() && tree[index] != -1) {
            inorderTraversal(2*index + 1);
            cout << tree[index] << " ";
            inorderTraversal(2*index + 2);
        }
    }

    void preorderTraversal(int index = 0) {
        if (index < tree.size() && tree[index] != -1) {
            cout << tree[index] << " ";
            preorderTraversal(2*index + 1);
            preorderTraversal(2*index + 2);
        }
    }

    void postorderTraversal(int index = 0) {
        if (index < tree.size() && tree[index] != -1) {
            postorderTraversal(2*index + 1);
            postorderTraversal(2*index + 2);
            cout << tree[index] << " ";
        }
    }
};

int main() {
    BinaryTree tree(10); // Create a binary tree with a maximum of 10 nodes

    // Insert nodes
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Perform traversals
    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorderTraversal();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorderTraversal();
    cout << endl;

    return 0;
}
