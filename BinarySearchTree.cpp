#include <iostream>
using namespace std;
class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // constructor for the node class
    Node()
    {
        leftchild = nullptr;  // Initialize left child to nullptr
        rightchild = nullptr; // Initialize right child to nullptr
    }
};

class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // Initialize the root of the tree to nullptr
    }
    
};

int main()
{
    
    
}
