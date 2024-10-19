#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;

    Node (int value) : val(value) , next(nullptr) {} 
};

class Linked_List
{
    private:
    Node* head;

    public:
    Linked_List() : head(nullptr) {};

    bool is_empty()
    {
        return (head == nullptr);
    }

    void insertion(int value , int index)
    {
        Node* new_node = new Node(value);
    
        Node* temp = head;
        if(index == 0 || is_empty())
        {
            new_node->next = head;
            head = new_node;
            cout << "Node added with value : " << value << endl;
            return;
        }
        for(int i = 0 ; i < index - 1 ; i++)
        {
            if(temp->next == nullptr)
            {
                delete new_node;
                cout << "Index out of bounds\n";
                return;
            }
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;

        cout << "Node added with value : " << value << endl;
        return;
    }

    void deletion(int index)
    {
        if(!is_empty())
        {
            Node* temp = head;
            if(index == 0)
            {
                head = head->next;
                delete temp;
                cout << "Head Deleted\n";
                return;
            }
            
            for(int i = 0 ; i < index - 1 ; i++)
            {
                temp = temp->next;
                if(temp == nullptr || temp->next == nullptr)
                {
                    cout << "Out of range\n";
                    return;
                }
            }

            Node* del_node = temp->next;
            temp->next = temp->next->next;
            
            delete del_node;        

        }
        else
        {
            cout << "List empty\n";
        }
    }

    void display()
    {
        Node* temp = head;
        int count = 0;
        while(temp != nullptr)
        {
            cout << "Index : " << count++ << " Value : " << temp->val << endl;
            temp = temp->next;
        }
    }


};

class Circular_Linked_List
{
    private:
    Node* head;

    public:
    Circular_Linked_List() : head(nullptr) {};

    bool is_empty()
    {
        return (head == nullptr);
    }

    void insertion(int value , int index)
    {
        Node* new_node = new Node(value);
    
        if(is_empty())
        {
            head = new_node;
            new_node->next = head;
            
            cout << "Node added with value : " << value << endl;
            return;
        }

        if(index == 0)
        {
            new_node->next = head;
            Node* last = head;

            while(last->next != head)
            {
                last = last->next;
            }
            last->next = new_node;
            head = new_node;

            cout << "Node added with value : " << value << endl;
            return;
        }

        Node* temp = head;
        for(int i = 0 ; i < index - 1 ; i++)
        {
            if(temp->next == head)
            {
                delete new_node;
                cout << "Index out of bounds\n";
                return;
            }
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;

        cout << "Node added with value : " << value << endl;
        return;
    }

    void deletion(int index)
    {
        if(is_empty())
        {
            cout << "List Empty\n";
            return;
        }
        
        if(index == 0)
        {
            if(head->next == head)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node* last = head;
                Node* temp = head;

                while(last->next != head)
                {
                    last = last->next;
                }

                head = head->next;
                last->next = head;
                delete temp;
            }
        }
        else
        {
            Node* temp = head;

            for(int i = 0 ; i < index - 1 ; i++)
            {
                temp = temp->next;
                if(temp->next == head)
                {
                    cout<< "Invalid Index\n";
                    return;
                }
            }

            Node* del_node = temp->next;
            temp->next = del_node->next;
            delete del_node;

            cout << "Node Deleted\n";

        }


       
    }



    void display()
    {
        if(!is_empty())
        {
            Node* temp = head;
            int count = 0;
            do
            {
                cout << "Index : " << count++ << " Value : " << temp->val << endl;
                temp = temp->next;
            }while(temp != head);
        }
        else
        {
            cout << "List Empty\n";
        }
    }
};

struct Double_Node
{
    int val;
    Double_Node* next;
    Double_Node* prev;

    Double_Node(int value) : next(nullptr) , prev(nullptr) , val(value) {}
};

class Doubly_Linked_List
{
    private:
    Double_Node* head;
    Double_Node* tail;

    public:
    Doubly_Linked_List() : head(nullptr) , tail(nullptr) {}

    bool is_empty()
    {
        return head == nullptr;
    }

    void display(char direction)
    {   
        Double_Node* temp = (direction == 'f') ? head : tail;

        int count = 0;
        while(temp != nullptr)
        {
            cout << "Index : " << count++ << " Value : " << temp->val << endl;
            temp = (direction == 'f') ? temp->next : temp->prev;
        }

    }

    void insertion(int value , int index)
    {
        Double_Node* new_node = new Double_Node(value);

        //List empty 
        if(is_empty())
        {
            head = tail = new_node;

            cout << "Node inserted at start due to list being empty\n";
            return;
        }

        //Insertion at start
        else if(index == 0)
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;

            cout << "Node inserted at start\n";
            return;
        }
        else
        {
            Double_Node* temp = head;
            for(int i = 0 ; i < index - 1 ; i++)
            {
                temp = temp->next;
                if(temp == nullptr)
                {
                    cout << "Index out of range\n";
                    delete new_node;
                    return;
                }
            }

            new_node->next = temp->next;
            new_node->prev = temp;

            if(temp->next)
            {
                temp->next->prev = new_node;
            }
            else
            {
                tail = new_node;
            }

            temp->next = new_node;
            cout << "Node inserted\n";
            return;
        }

    }

    void deletion(int index)
    {   
        //List empty
        if(is_empty())
        {
            cout << "List empty\n";
            return;
        }

        Double_Node* temp = head;

        //First node deletion
        if(index == 0)
        {
            //1 node only
            if(head == tail)
            {
                delete temp;
                cout << "Node deleted list empty\n";
                return;
            }
            //More than 1 node
            else
            {
                head = head->next;
                head->prev = nullptr;
                delete temp;
                cout << "First node deleted\n";
                return;
            }
        }

        for(int i = 0 ; i < index ; i++)
        {
            temp = temp->next;

            if(temp == nullptr)
            {
                cout << "Invalid index\n";
                delete temp;
                return;
            }
        }

        temp->prev->next = temp->next;

        //Middle node deletion
        if(temp->next)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Node deleted\n";
        return;
    }

    int search(int value)
    {
        Double_Node* temp = head;
        int index = 0;

        while(temp != nullptr)
        {
            if(temp->val == value)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }

        cout << "Value not found\n";
        return -1;
    }

    void update(int value , int index)
    {
        Double_Node* temp = head;

        for(int i = 0 ; i < index ; i++)
        {
            if(temp == nullptr)
            {
                cout << "Invalid index\n";
                delete temp;
                return;
            }
            temp = temp->next;
        }

        if(temp == nullptr)
        {
            cout << "Invalid Index\n";
            return;
        }

        temp->val = value;
        cout << "Value Updated\n";
    }
};


class stack
{
    private:
    int* arr;
    int capacity;
    int top;

    public:
    stack(int size) : capacity(size) , top(-1)
    {
        arr = new int[capacity];
    }

    ~stack()
    {
        delete[] arr;
    }

    bool is_full()
    {
        return (top - 1 == capacity);
    }

    bool is_empty()
    {
        return (top == -1);
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

    int pop()
    {
        if(!is_empty())
        {
            return arr[top--]; 
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
            return arr[top];
        }
        else
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    void clear()
    {
        delete [] arr;
        arr = new int[capacity];
        top = -1;
    }



};

struct Stack_Node
{
    int val;
    Stack_Node* next;

    Stack_Node(int value) : val(value) , next(nullptr) {}
};

class Stack_Linked_List
{
    private:
    Stack_Node* top;

    public:
    Stack_Linked_List() : top(nullptr) {}

    bool is_empty()
    {
        return (top == nullptr);
    }

    void push(int value)
    {
        Stack_Node* new_node = new Stack_Node(value);

        new_node->next = top;
        top = new_node;
    }

    int pop()
    {
        if(!is_empty())
        {
            Stack_Node* temp = top;
            int pop_val = top->val;
            top = top->next;
            delete temp;
            return pop_val;
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
            return top->val;
        }
        else
        {
            cout << "Stack Underflow\n";
            return -1;
        }
    }
    
    void clear()
    {
        while(top != nullptr)
        {
            Stack_Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

class Queue
{
    private:
    int* arr;
    int capacity;
    int front;
    int rear;

    public:
    Queue (int size) 
    {
        capacity = size;
        arr = new int [capacity];
        front = 0;
        rear = 0;
    }

    bool is_full()
    {
        return(rear == capacity);
    }

    bool is_empty()
    {
        return(front == rear);
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
            arr[rear++] = val;
            cout << val << " enqueued\n";
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
            return arr[front++];
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
            int temp = front;

            cout << "Queue : ";
            while(temp != rear)
            {
                cout << arr[temp++] << " ";
            }     
            cout << endl;
        }
    }
};

struct Queue_Node
{
    int val;
    Queue_Node* next;

    Queue_Node(int value) : val(value) , next(nullptr) {}
};

class Queue_Linked_List
{
    private:
    Queue_Node* head;
    Queue_Node* tail;

    public:
    Queue_Linked_List() : head(nullptr) , tail(nullptr) {}

    bool is_empty()
    {
        return (head == nullptr);
    }

    void enqueue(int value)
    {
        Queue_Node* new_node = new Queue_Node(value);

        if(is_empty())
        {
            head = tail = new_node;
            cout << value << " Enqueued\n";
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
            cout << value << " Enqueued\n";
        }
    }

    int dequeue()
    {
        if(is_empty())
        {
            cout << "Queue Empty\n";
            return -1;
        }
        
        int d_val = head->val;
        head = head->next;
        return d_val;
    }

    void print()
    {
        if(is_empty())
        {
            cout << "Queue Empty\n";
            return;
        }

        Queue_Node* temp = head;

        cout << "Queue : ";
        while(temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        delete temp;
        cout << endl;
    }
};



int main()
{
    cout << "Running\n";
    Circular_Linked_List temp;
    temp.insertion(0,0);
    temp.insertion(1,0);
    temp.insertion(2,0);
    temp.deletion(3);
    temp.display();

}

