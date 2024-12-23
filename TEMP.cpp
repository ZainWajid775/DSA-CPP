#include <iostream>
#include <list>

using namespace std;

void bubble_sort(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size - i ; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[] , int size)
{
    for(int i = 1 ; i < size ; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void selection_sort(int arr[] , int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
    {
        int min_index = i;
        
        for(int j = i ; j < size ; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }       
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void merge(int arr[] , int left , int mid , int right)
{   
    int size_1 = mid - left + 1;
    int size_2 = right - mid;

    int arr_l[size_1];
    int arr_r[size_2];

    for(int i = 0 ; i < size_1 ; i++)
    {
        arr_l[i] = arr[left + i];
    }

    for(int j = 0 ; j < size_2 ; j++)
    {
        arr_r[j] = arr[mid + j + 1];
    }

    int i = 0 ; 
    int j = 0 ; 
    int k = left;

    while(i < size_1 && j < size_2)
    {
        if(arr_l[i] < arr_r[j])
        {
            arr[k] = arr_l[i];
            i++;
        }
        else
        {
            arr[k] = arr_r[j];
            j++;
        }
        k++;
    }

    while(i < size_1)
    {
        arr[k] = arr_l[i];
        i++;
        k++;
    }
    while(j < size_2)
    {
        arr[k] = arr_r[j];
        j++;
        k++;
    }
}   

void merge_sort(int arr[] , int left , int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr , left , mid);
        merge_sort(arr , mid+1 , right);

        merge(arr , left , mid , right);
    }
}

int partition(int arr[] , int left , int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left ; j <= right ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;

    return i;
}

void quick_sort(int arr[] , int left , int right)
{
    if(left < right)
    {
        int mid = partition(arr , left , right);

        quick_sort(arr , left , mid - 1);
        quick_sort(arr , mid + 1 , right);
    }
}

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

Node* insert(Node* root , int val)
{
    if(root == nullptr)
    {
        return new Node(val);
    }

    if(val > root->data)
    {
        root->right = insert(root->right , val);
    }
    else
    {
        root->left = insert(root->left , val);
    }

    return root;
}

Node* min(Node* root)
{
    Node* current = root;
    while(current && current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}

void bfs(Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

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

Node* del_node(Node* root , int val)
{
    if(root == nullptr)
    {
        return root;
    }

    if(val < root->data)
    {
        root->left = del_node(root->left , val);
    }
    else if(val > root->data)
    {
        root->right = del_node(root->right , val);
    }
    else
    {
        if(root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = min(root->right);
        root->data = temp->data;
        root->right = del_node(root->right , temp->data);

    }

    return root;
}

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

struct AVL_Node
{
    int data;
    AVL_Node* left;
    AVL_Node* right;
    int height;

    AVL_Node(int val) : data(val) , left(nullptr) , right(nullptr) , height(0) {}
};

int height(AVL_Node* root)
{
    if(root)
    {
        return root->height;
    }
    return 0;
}

int bf(AVL_Node* root)
{
    if(root)
    {
        return (height(root->left) - height(root->right));
    }
    return 0;
}

AVL_Node* right_rotate(AVL_Node* root)
{
    AVL_Node* new_root = root->left;
    AVL_Node* temp = new_root->right;

    new_root->right = root;
    root->left = temp;

    root->height = max(height(root->left) , height(root->right)) + 1;
    new_root->height = max(height(new_root->left) , height(new_root->right)) + 1;

    return new_root;
}

AVL_Node* left_rotate(AVL_Node* root)
{
    AVL_Node* new_root = root->right;
    AVL_Node* temp = new_root->left;

    new_root->left = root;
    root->right = temp;

    root->height = max(height(root->left) , height(root->right)) + 1;
    new_root->height = max(height(new_root->left) , height(new_root->right)) + 1;

    return new_root;
}

AVL_Node* insert(AVL_Node* root , int val)
{
    if(root == nullptr)
    {
        return new AVL_Node(val);
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
    int balance = bf(root);

    if(balance > 1 && val < root->left->data)
    {
        return right_rotate(root);
    }
    if(balance < -1 && val > root->right->data)
    {
        return left_rotate(root);
    }
    if(balance > 1 && val > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && val < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

AVL_Node* min(AVL_Node* root)
{
    AVL_Node* current = root;
    while(current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

AVL_Node* del_node(AVL_Node* root , int val)
{
    if(root == nullptr)
    {
        return root;
    }

    if(val < root->data)
    {
        root->left = del_node(root->left , val);
    }
    else if(val > root->data)
    {
        root->right = del_node(root->right , val);
    }
    else
    {
        if((root->left == nullptr) || (root->right == nullptr))
        {
            AVL_Node* temp = root->left ? root->left : root->right;

            if(temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }

            delete temp;
        }
        else
        {
            AVL_Node* temp = min(root->right);
            root->data = temp->data;
            root->right = del_node(root->right , temp->data);
        }
    }

    if(root == nullptr)
    {
        return root;
    }

    root->height = 1 + max(height(root->left) , height(root->right));
    int balance = bf(root);

    if(balance > 1 && bf(root->left) >= 0)
    {
        return right_rotate(root);
    }
    if(balance > 1 && bf(root->left) < 0)
    {   
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && bf(root->right) <= 0)
    {
        return left_rotate(root);
    }
    if(balance < - 1 && bf(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void in_order(AVL_Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void bfs(AVL_Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    queue<AVL_Node*> q;
    q.push(root);

    while(!q.empty())
    {
        AVL_Node* top = q.front();
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

class Graph
{
    private:
        int vertices;
        list<int> *adj_list;

    public:

        Graph(int v)
        {
            vertices = v;
            adj_list = new list<int>[v];
        }

        void add_edge(int u , int v)
        {
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        void remove_edge(int u , int v)
        {
            adj_list[u].remove(v);
            adj_list[v].remove(u);
        }

        void print()
        {
            for(int i = 0 ; i < vertices ; i++)
            {
                cout << "List of " << i << " : ";   

                for(auto x : adj_list[i])
                {
                    cout << x << " ";
                }

                cout << endl;
            }
        }

        void bfs(int source)
        {
            bool *visited = new bool[vertices];
            for(int i = 0 ; i < vertices ; i++)
            {
                visited[i] = false;
            }

            list<int> l;
            list<int>::iterator i;

            l.push_back(source);
            visited[source] = true;

            while(!l.empty())
            {
                int temp = l.front();
                cout << temp << " ";

                l.pop_front();

                for(i = adj_list[temp].begin() ; i != adj_list[temp].end() ; i++)
                {
                    if(!visited[*i])
                    {
                        l.push_back(*i);
                        visited[*i] = true;
                    }
                }
            }
        }

        void dfs_helper(bool visited[] , int source)
        {
            visited[source] = true;

            cout << source << " ";

            for(auto x : adj_list[source])
            {
                if(!visited[x])
                {
                    dfs_helper(visited , x);
                }
            }
        }

        void dfs(int source)
        {
            bool *visited  = new bool[vertices];
            for(int i = 0 ; i < vertices ; i++)
            {
                visited[i] = false;
            }

            dfs_helper(visited , source);

            delete[] visited;
        }
};



int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int size = 10;

    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.dfs(0);

}