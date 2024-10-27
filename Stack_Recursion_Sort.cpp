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
            cout << "Top : " << top << endl;
        }
        else
        {
            cout << "Stack Overflow\n";
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

    void insert_sorted(int val)
    {
        //Check if stack is empty or value is bigger than one on top
        if(is_empty() || arr[top] < val)
        {
            push(val);   
        }
        //If value is smaller, pop the values in stack and then insert them in order
        else
        {
            //Temp is made seperately for every time function is called recursively
            int temp = pop();

            //Now check if value is at correct place
            insert_sorted(val);

            //When the value is pushed, all the temps are pushed in order they were popped
            push(temp);
        }
    }

    void sort()
    {
        //Pop each integer and then insert them using insert_sorted   
        if(!is_empty())
        {
            int temp = pop();
            sort();
            //Will run when stack becomes empty, then the previous recursive calls will start from here
            insert_sorted(temp);
        }
    }


};

struct Node
{
    int val;
    Node* next;

    Node(int value) : val(value) , next(nullptr) {}
};

class Stack_Linked_List
{
    private:
    Node* head;

    public:
    Stack_Linked_List() : head(nullptr) {}

    bool is_empty()
    {
        return (head == nullptr);
    }

    void push(int value)
    {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;

    }

    int pop()
    {
        if(!is_empty())
        {
            Node* temp = head;
            int return_val = temp->val;
            head = head->next;
            delete temp;
            return return_val;        
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
            return (head->val);
        }
        else
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    void display()
    {
        if(!is_empty())
        {
            Node* temp = head;
            cout << "Stack : ";

            while(temp != nullptr)
            {
                cout<< temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Stack Empty\n";
        }

    }

    void insert_sorted(int value)
    {
        if(is_empty() || value > head->val)
        {
            push(value);
        }
        else
        {
            int temp = pop();
            insert_sorted(value);
            push(temp);
        }
    }

    void sort()
    {
        if(!is_empty())
        {
            int temp = pop();
            sort();
            insert_sorted(temp);
        }
    }

};

int main()
{
    Stack_Linked_List stk;
    stk.push(10);
    stk.push(9);
    stk.push(8);
    stk.sort();
    stk.display();

}