#include <iostream>
using namespace std;

class circular_queue
{
    private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

    public:
    circular_queue(int s)
    {   
        capacity = s;
        arr = new int[capacity];
        size = 0;  
        front = 0;
        rear = -1;
    }

    ~circular_queue()
    {
        delete[] arr;
    }

    bool is_full()
    {
        return (size == capacity);
    }

    bool is_empty()
    {
        return (size == 0);
    }

    void check_size()
    {
        if(is_empty()) 
        {
            cout << "Queue Empty\n";
            return;
        }
        else
        {
            cout << "Size : " << size << endl;
        }
    }

    void enqueue(int val)
    {
        if(is_full())
        {
            cout << "Queue Full\n";
            return;
        }
        else
        {
            //Mod used to loop rear back to 0 if capacity is exceeded
            rear = (rear + 1) % capacity;
            arr[rear] = val;
            size++;
        }
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
            //Mod used to loop front back to 0 if capacity is exceeded
            int item = arr[front];
            front = (front + 1) % capacity;
            size --;
            return item;
        }
    }

    int peek()
    {
        if(is_empty())
        {
            cout << "Queue Empty\n";
            return -1;
        }
        else
        {
            return arr[front];
        }
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
            cout << "Queue : " ;
            for(int i = 0 ; i < size ; i++)
            {
                cout << arr[(front + i) % capacity] << " " ;
            }
            cout << endl;
        }
    }


};

int main()
{
    circular_queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.check_size();
}