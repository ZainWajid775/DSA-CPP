#include <iostream>
using namespace std;

//Value at left of node is smaller
//Value at right of node is bigger
//No duplicate values

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//Recursively calls itself with a new node until it reaches an empty node where value can be inserted
//Return a node pointer which is inserted at the left or right pointers
Node* insert(Node* root , int val)
{
    //Insert new node if position found
    if(root == nullptr)
    {
        return new Node(val);
    }

    //Recursively call itself with a new node until nullptr is found
    if(val < root->data)
    {
        root->left = insert(root->left , val);
    }
    else
    {
        root->right = insert(root->right , val);
    }

    return root;
}

bool search(Node* root , int val)
{
    if(root == nullptr)
    {
        return false;
    }

    //Check value of current node
    if(val == root->data)
    {
        return true;
    }

    //Continue searching left or right depending on value being greater or larger than node data
    if(val < root->data)
    {
        return search(root->left , val);
    }
    else
    {
        return search(root->right , val);
    }
}

//TRAVERSAL

//1. Inorder : Left -> Root -> Right, Sorted Order
//Traverses through left tree first
void in_order(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

//2. Preorder : Root -> Left -> Right
void pre_order(Node* root)
{
    if(root == nullptr) 
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

//3. Postorder : Left -> Right -> Root
void post_order(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

//4. Level order : Breadth First Search(BFS)
void level_order(Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    //Push the current node into a queue
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        //Output the current node and remove it
        Node* current =q.front();
        cout << current->data << " ";
        q.pop();

        //If the node has any children, add them into the queue 

        if(current->left != nullptr)
        {
            q.push (current->left);
        }

        if(current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

Node* min (Node* root)
{
    while(root && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node* delete_node(Node* root , int key)
{
    if(root == nullptr)
    {
        return root;
    }

    //Traverse down the tree until value matches key
    if(key < root->data)
    {
        root->left = delete_node(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = delete_node(root->right , key);
    }

    //Else runs when key matches value, node is one to be deleted
    else
    {
        //Case node has one or no children
        //Replace the node with either its inorder successor or predecessor
        if(root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //Case node has 2 children
        //Find the smallest value on the right subtree
        Node* temp = min(root->right);

        //Change the current nodes data to the smallest value in the right subtree
        root->data = temp->data;

        //Delete inorder successor
        root->right = delete_node(root->right , temp->data);
    }

    return root;
}

int main()
{
    Node* root = nullptr;
    root = insert(root , 5);
    root = insert(root , 1);
    root = insert(root , 3);
    root = insert(root , 4);
    root = insert(root , 2);
    root = insert(root , 7);

    in_order(root);
    cout << endl;

    if(search(root , 4))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    delete_node(root , 3);
    in_order(root);
    cout << endl;

    return 0;
}



