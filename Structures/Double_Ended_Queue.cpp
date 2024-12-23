#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;

    node(int val) : data(val) , next(nullptr) , prev(nullptr) {}
};

class my_deque
{
    private:
    node* front;
    node* rear;
    int size;

    public:
    my_deque()
    {
        front = rear = nullptr;
        size = 0;
    }

    bool is_empty()
    {
        return size == 0;
    }

    void insert_front(int val)
    {
        node* new_node = new node(val);
        if(is_empty())
        {
            front = rear = new_node;
            size++;
        }
        else
        {
            front->prev = new_node;
            new_node->next = front;
            front = new_node;
            size++;
        }
    }

    void insert_end(int val)
    {
        node* new_node = new node(val);
        if(is_empty())
        {
            front = rear = new_node;
            size++;
        }
        else
        {
            rear->next = new_node;
            new_node->prev = rear;
            rear = new_node;
            size++;
        }
    }

    int get_front()
    {
        if(is_empty())
        {
            return -1;
        }
        else
        {   
            node* temp = front;
            int x = temp->data;
            front = front->next;
            if (front != nullptr) 
            {
                front->prev = nullptr;
            } 
            else 
            {
                rear = nullptr;
            }
            delete temp;
            size--;
            return x;

        }
    }

    int get_rear()
    {
        if(is_empty())
        {
            return -1;
        }
        else
        {
            node* temp = rear;
            int x = temp->data;
            rear = rear->prev;
            if (rear != nullptr) 
            {
                rear->next = nullptr;
            } 
            else 
            {
                front = nullptr;
            }
            delete temp;
            size--;
            return x;
        }
    }

    void print()
    {
        if(is_empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            node* temp = front;
            cout << "Queue : ";
            while(temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
    }

};

int main()
{
    my_deque d;
    d.insert_front(2);
    d.insert_end(4);
    d.insert_end(5);
    d.insert_front(1);
    cout << endl;
    d.print();

}

