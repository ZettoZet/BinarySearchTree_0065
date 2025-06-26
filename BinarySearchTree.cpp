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
    void search(int element, Node *&parent, Node *&currentNode)
    {
        // This function searches the currentNode of the specified Node as well as the currentNode's parent.
        currentNode = ROOT; // set currentNode to ROOT
        parent = nullptr; // Initialize parent to nullptr
        while ((currentNode != nullptr) && (currentNode->info != element)) // looping until the end or found the element
        {
            parent = currentNode;// set parent to currentNode before traversing
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void insert()
    {
        int x;
        cout << "Masukkan nilai: ";
        cin >> x;

        // step 1 : Allocate memory for the new code
        Node *newNode = new Node();

        // Step 2: Assign value to the data field of new node
        newNode->info = x;

        // Step 3 : Make the left and right child of the new node point to NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        
    }

    
};

int main()
{
    
    
}
