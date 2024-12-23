#include <iostream>
using namespace std;

//Allows for dynamic memory allocation, no need to check stack size or if its full

struct node
{
    int data;
    node* next;

    node(int val) : data(val) , next(nullptr) {}
};

class Stack
{
    private:
    node* top;

    public:
    Stack() : top(nullptr) {}

    void push(int val)
    {
        
        node* new_node = new node(val);
        new_node->next = top;
        top = new_node;
    } 

    int pop()
    {
        if(is_empty())
        {
            return -1;
        }
        else
        {
            node* temp = top;
            int value = top->data;
            top = top->next;
            delete temp;
            return value;
        }
    }

    int peek()
    {
        if(is_empty())
        {
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool is_empty()
    {
        if(top == nullptr)
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
            cout << "Stack Underflow\n";
        }
        else
        {
            node* temp = top;
            int count = 0;
            do
            {
                cout << "Index : " << count << " Data : " << temp->data << endl;
                temp = temp->next;
                count ++;
            }while(temp != nullptr);
        }
    }


};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.peek() << endl;
    stack.print();

}