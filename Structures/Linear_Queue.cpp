#include <iostream>

using namespace std;

class Queue
{
    private:
    int front;
    int rear;
    int* arr;
    int capacity;

    public:
    Queue(int cap) : capacity(cap) , front(0) , rear(0) , arr(new int [cap]) {}

    ~Queue()
    {
        delete[] arr;
    }

    bool is_full()
    {
        return (rear == capacity);
    }

    bool is_empty()
    {
        return (rear == front);
    }

    void enqueue(int val)
    {
        if(is_full())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear++] = val;
        }
    }

    int dequeue()
    {
        if(is_empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front++];
        }
    }

    void print()
    {
        if(is_empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for(int i = front ; i < rear ; i++)
            {
                cout << "Index : " << i << " Data : " << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print();

}