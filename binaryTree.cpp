#include <iostream>
using namespace std;

// Node struct
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *minValue(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// inorder, preorder, and postorder traversal
// Inorder Traversal
void traverseInOrder(struct Node *root)
{
    if (root != NULL)
    {
        traverseInOrder(root->left);
        cout << " " << root->data;
        traverseInOrder(root->right);
    }
}
// preorder Traversal
void traversePreOrder(struct Node *root)
{
    if (root != NULL)
    {
        cout << " " << root->data;
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}
// postorder Traversal
void traversePostOrder(struct Node *root)
{
    if (root != NULL)
    {
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << " " << root->data;
    }
}
int main()
{
    Node* root = NULL;

    root = insert(root, 43);
    root = insert(root, 31);
    root = insert(root, 64);
    root = insert(root, 20);
    root = insert(root, 56);
    root = insert(root, 40);
    root = insert(root, 89);
    root = insert(root, 28);
    root = insert(root, 33);
    root = insert(root, 59);
    root = insert(root, 47);

    deleteNode(root,31);


  cout << "Preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);
}