#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;

    node (int val) : data(val) , next(nullptr) {}
};

class queue
{
    private:
    node* front;
    node* rear;

    public:
    queue() : front(nullptr) , rear(nullptr) {}

    void enqueue(int val)
    {
        node* new_node = new node(val);

        //If the queue is empty
        if(rear == nullptr)
        {
            front = rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;   
        }
        //Making it ciruclar
        rear->next = front;
    }

    int dequeue()
    {
        if(is_empty())
        {
            cout << "Queue Empty\n";
            return -1;
        }
        else
        {
            node* temp = front;
            int data = temp->data;

            //In case queue is empty
            if(front == rear)
            {
                front = rear = nullptr;
                return data;
            }
            else
            {
                front = front->next;
                //Rear now has to point to the new front 
                rear->next = front;
                delete temp;
                return data;
            }
        }
    }

    bool is_empty()
    {
        return front == nullptr;
    }

    void print()
    {
        if(is_empty())
        {
            cout << "Queue Empty\n";
            return;
        }
        else
        {
            node* temp = front;
            cout << "Queue : ";
            do
            {
                cout << " " << temp->data;
                temp = temp->next;
            }while(temp->next != rear);
            cout << endl;
            return;
        }
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Data : " << q.dequeue() << q.dequeue() << q.dequeue() << endl;
    q.print();
}