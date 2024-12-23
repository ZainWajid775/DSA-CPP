#include <iostream>

using namespace std;

struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) : data(val) , height(1) , left(nullptr) , right(nullptr) {}
};

int height(Node* node)
{
    if(node != nullptr)
    {
        return node->height;
    }
    return 0;
}

int balance_factor(Node* node)
{
    if(node != nullptr)
    {
        return (height(node->left) - height(node->right));
    }
    return 0;
}

Node* right_rotate(Node* node)
{
    Node* new_root = node->left;
    Node* temp = new_root->right;

    new_root->right = node;
    node->left = temp;

    node->height = max(height(node->left) , height(node->right)) + 1;
    new_root->height = max(height(new_root->left) , height(new_root->right)) + 1;

    return new_root;
}

Node* left_rotate(Node* node)
{
    Node* new_root = node->right;
    Node* temp = node->left;

    new_root->left = node;
    node->right = temp;

    node->height = max(height(node->left) , height(node->right)) + 1;
    new_root->height = max(height(new_root->left) , height(new_root->right)) + 1;
    
    return new_root;
}

Node* insert(Node* root , int val)
{
    if(root == nullptr)
    {
        return new Node(val);
    }

    if(val < root->data)
    {
        root->left = insert(root->left , val);
    }
    else if(val > root->data)
    {
        root->right = insert(root->right , val);
    }
    else
    {
        return root;
    }

    root->height = max(height(root->left) , height(root->right)) + 1;

    int bf = balance_factor(root);

    if(bf > 1 && val < root->left->data)
    {
        return right_rotate(root);
    }

    if(bf > 1 && val > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if(bf < -1 && val > root->right->data)
    {
        return left_rotate(root);
    }

    if(bf < -1 && val < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

Node* min(Node* node)
{
    Node* current = node;

    while(current->left)
    {
        current = current->left;
    }

    return current;
}

Node* del_node(Node* root , int key)
{
    if(root == nullptr)
    {
        return root;
    }

    if(key < root->data)
    {
        root->left = del_node(root->left , key);
    }
    else if(key > root->data)
    {
        root->right = del_node(root->right , key);
    }
    else
    {
        if(!root->left || !root->right)
        {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else
        {
            Node* temp = min(root->right);
            root->data = temp->data;
            root->right = del_node(root->right , temp->data);
        }
    }

    if(!root)
    {
        return nullptr;
    }

    root->height = 1 + max(height(root->left) , height(root->right));
    int bf = balance_factor(root);

    if(bf > 1 && balance_factor(root->left) >= 0)
    {
        return right_rotate(root);
    }
    if(bf > 1 && balance_factor(root->left) < 0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(bf < -1 && balance_factor(root->right) <= 0)
    {
        return right_rotate(root);
    }
    if(bf < -1 && balance_factor(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void bfs(Node* source)
{
    if(source == nullptr)
    {
        return;
    }

    queue<Node*>q;
    q.push(source);

    while(!q.empty())
    {
        Node* top = q.front();
        cout << top->data << " ";
        q.pop();

        if(top->left != nullptr)
        {
            q.push(top->left);
        }

        if(top->right != nullptr)
        {
            q.push(top->right);
        }
    }
}

int main()
{
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    root = del_node(root , 30);


    bfs(root);

}