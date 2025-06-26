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
        currentNode = ROOT;                                                // set currentNode to ROOT
        parent = nullptr;                                                  // Initialize parent to nullptr
        while ((currentNode != nullptr) && (currentNode->info != element)) // looping until the end or found the element
        {
            parent = currentNode; // set parent to currentNode before traversing
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

        // Step 4 : Locate the node which will be the parent of the node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // Step 5 : If parent is NULL (Tree is empty)
        if (parent == nullptr)
        {
            // 5a : Mark the new code as ROOT
            ROOT = newNode;

            // 5b : EXIT
            return;
        }

        // Step 6 : If the value in the data field of new node is less than that of parent
        if (x < parent->info)
        {
            // 6a : Make the left child of parent point to the new node
            parent->leftchild = newNode;

            // 6b : EXIT
            return;
        }

        // step 7 : If the value in the data field of the new node is greater than that of the parent
        else if (x > parent->info)
        {
            // 7a : Make the right child of parent point to the new node
            parent->rightchild = newNode;

            // 7b : EXIT
            return;
        }
    }

    bool isEmpty() // Function to check if the tree is empty
    {
        // Checks if the tree is empty
        return ROOT == nullptr;
    }

    void inorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        {
            return;
        }

        inorder(ptr->leftchild); // Traverse the left child
        cout << ptr->info << " "; // parent
        inorder(ptr->rightchild); // Traverse the right child
    }

    void preorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        {
            return;
        }

        cout << ptr->info << " "; // parent
        preorder(ptr->leftchild); // Traverse the left child
        preorder(ptr->rightchild); // Traverse the right child
    }

    void postorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        {
            return;
        }

        postorder(ptr->leftchild); // Traverse the left child
        postorder(ptr->rightchild); // Traverse the right child
        cout << ptr->info << " "; // parent
    }
};

int main()
{
    BinaryTree tree;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            tree.insert();
            break;
        }
        case '2':
        {
            tree.inorder(tree.ROOT);
            break;
        }
        case '3':
        {

            tree.preorder(tree.ROOT);
            break;
        }
        case '4':
        {

            tree.postorder(tree.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }

}
