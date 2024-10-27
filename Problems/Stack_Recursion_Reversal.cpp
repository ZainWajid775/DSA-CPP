#include <iostream>
using namespace std;

class Stack
{
    private:
    int top;
    int* arr;
    int capacity;

    public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    bool is_empty()
    {
        return (top == -1);
    }

    bool is_full()
    {
        return (top == capacity - 1);
    }

    void push(int val)
    {
        if(!is_full())
        {
            arr[++top] = val;
        }
        else
        {
            cout << "Stack Overflow\n";
        }
    }

    void insert_at_bottom(int val)
    {
        //If stack is empty push the value at bottom
        if(is_empty())
        {
            push(val);
        }

        //Otherwise pop all the values recursively
        else
        {
            int temp = pop();

            //First push value at the bottom and then push the rest of the values in the same order
            insert_at_bottom(val);
            push(temp);
        }
    }

    int pop()
    {
        if(!is_empty())
        {
            return (arr[top--]);
        }
        else
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int peek()
    {
        if(!is_empty())
        {
            return (arr[top]);
        }
        else
        {
            return -1;
        }
    }

    void display()
    {
        if(!is_empty())
        {
            cout << "Stack : ";
            for(int i = 0 ; i <= top ; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Stack Empty\n";
        }
    }

    void reversal()
    {
        int temp;

        //If loops until all values from stackhavebeen popped
        if(!is_empty())
        {
            //Each time the popped value is stored in temp
            temp = pop();

            //Call fucntion again to either continue till the end or start recursively inserting values
            reversal();

            //The popped value is inserted at the bottom of the stack
            insert_at_bottom(temp);
        }
    }


};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.reversal();
    s.display();

}

