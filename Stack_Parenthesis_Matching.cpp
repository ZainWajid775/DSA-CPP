#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class stack
{
    private:
    char* arr;
    int capacity;
    int top;

    public:
    stack(int capacity)
    {
        this->capacity = capacity;
        arr = new char[capacity];
        top = -1;
    }

    ~stack()
    {
        delete[] arr;
    }

    void push(char val)
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
        if(top - 1 == capacity)
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

    char peek()
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

    //Parenthesis Matching 
    bool is_pair(char opening , char closing)
    {
        return(opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
    }

    bool parenthesis_check(const char* exp , stack& stk)
    {
        //Loop retuns until the character array ends
        while(*exp != '\0')
        {
            //Push the opening parenthesis into the stack
            if(*exp == '(' || *exp == '{' || *exp == '[')
            {
                stk.push(*exp);
            }
            //Check if the closing parenthesis matches the opening one
            else if(*exp == ')' || *exp == '}' || *exp == ']')
            {
                //If the parenthesis dont match return false
                if(stk.is_empty() || !is_pair(stk.peek() , *exp))
                {
                    return false;
                }
                //Else remove the matched parenthesis and check the rest of the expression
                else
                {
                    stk.pop();
                }
            }
            //Move to next character
            exp++;
        }
        //If the stack is empty, all parenthesis are matched otherwise there is parenthesis left which is unbalanced
        return stk.is_empty();
    }


};

int main()
{
    try
    {
        stack stk(100);
        char expression[100];
        cout << "Enter the expression : ";
        cin.getline(expression , 100);

        if(stk.parenthesis_check(expression , stk))
        {
            cout << "Balanced\n";
        }
        else
        {
            cout << "Unbalanced\n";
        }
        

    }
    catch(const std::exception& e)
    {
        cerr << e.what() << endl;
    }
    

}