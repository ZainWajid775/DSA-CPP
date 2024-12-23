#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
    private:
    int* arr;
    int capacity;
    int top;

    public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int val)
    {
        if(is_full())
        {
            throw std::overflow_error("Stack Overflow");
        }
        else
        {
            arr[++top] = val;
        }
    }

    int pop()
    {
        if(is_empty())
        {
            throw std::underflow_error("Stack Underflow");
        }
        else
        {
            return arr[top--];
        }
    }

    bool is_full()
    {
        if(top == capacity)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool is_empty()
    {
        if(top == - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void print()
    {
        if(is_empty())
        {
            throw std::underflow_error("Stack Underflow");
        }
        else
        {
            for(int i = 0 ; i != top + 1 ; i++)
            {
                cout << "Index : " << capacity - i << " Data : " << arr[i] << endl;
            }
        }
    }

    void size()
    {
        cout << "Stack size : " << top + 1 << endl;
    }

    void clear()
    {
        top = - 1;
    }

    int peek()
    {
        if(is_empty())
        {
            throw std::underflow_error("Stack Underflow");
        }
        else
        {
            return arr[top];
        }
    }


};

int main()
{
    
    Stack stack(1);
    stack.push(1);
    stack.size();
    stack.print();

    

}