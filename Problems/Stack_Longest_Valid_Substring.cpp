#include <iostream>
using namespace std;

class Stack
{
    private:
    int top;
    char* arr;
    int capacity;

    public:
    Stack(int size)
    {
        capacity = size;
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

    void push(char val)
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

    char pop()
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

    char peek()
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

    int max_length(const string& str)
    {
        int max_len = 0;

        for(int i = 0 ; i < str.length() ; i++)
        {
            //Push any opening bracket into stack
            if((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
            {
                push(str[i]);
            }
            else
            {
                //Pop if the curret char is not a opening bracket
                pop();

                //If stack is now empty, push the next bracket
                if(is_empty())
                {
                    push(str[i]);
                }
                else
                {   
                    //Check if the new maximum calculated is greater than the older one
                    max_len = max(max_len , i - top + 1);
                }
            } 
        }

        return max_len;
    }



};

int main()
{
    Stack stk(100);
    cout << stk.max_length("{{{{{}}}}}");

}

