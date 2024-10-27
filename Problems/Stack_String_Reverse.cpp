#include <iostream>
using namespace std;

class Stack
{
    private:
    int top;
    char* arr;
    int capacity;

    public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new char[capacity];
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

    void push(char data)
    {
        if(!is_full())
        {
            arr[++top] = data;
        }
        else
        {
            cout << "Stack Overflow\n";
        }
    }

    char pop()
    {
        if(!is_empty())
        {
            return (arr[top--]);
        }
        else
        {
            cout << "Stack Underflow\n";
            return '-';
        }
    }

    char peek()
    {
        if(!is_empty())
        {
            return (arr[top]);
        }
        else
        {
            cout << "Stack Empty\n";
            return '-';
        }
    }

    string reverse(string str)
    {
        for(int i = 0 ; i < str.length() ; i++)
        {
            push(str[i]);
        }

        string reversed = "";
        while(!is_empty())
        {
            reversed = reversed + pop();
        }

        return reversed;
    }
};

int main()
{
    Stack stk(100);

    cout << stk.reverse("I am eating");
}