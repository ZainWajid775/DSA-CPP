#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node* prev;

    Node(int value) : next(nullptr) , prev(nullptr) , val(value) {}
};

class Doubly_Linked_List
{
    private:
    Node* head;
    Node* tail;

    public:
    Doubly_Linked_List() : head(nullptr) , tail(nullptr) {}

    bool is_empty()
    {
        return head == nullptr;
    }

    void display(char direction)
    {   
        Node* temp = (direction == 'f') ? head : tail;

        int count = 0;
        while(temp != nullptr)
        {
            cout << "Index : " << count++ << " Value : " << temp->val << endl;
            temp = (direction == 'f') ? temp->next : temp->prev;
        }

    }

    void insertion(int value , int index)
    {
        Node* new_node = new Node(value);

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
            Node* temp = head;
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

        Node* temp = head;

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
        Node* temp = head;
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
        Node* temp = head;

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

int main()
{
    Doubly_Linked_List list;
    list.insertion(1,0);
    list.insertion(2,1);
    list.insertion(3,2);
    list.insertion(4,3);
    list.insertion(5,4);
    list.update(10 , 5);
    list.display('f');
}