#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* next;
    Node* prev;

    Node(char val) : data(val) , next(nullptr) , prev(nullptr) {}
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
        return (head == nullptr);
    }

    void insert(char val)
    {
        Node* new_node = new Node(val);

        if(is_empty())
        {
            head = tail = new_node;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }

    }

    void display(char direction)
    {
        if(!is_empty())
        {
            cout << "Linked List : ";
            Node* temp = (direction == 'f') ? head : tail;

            while(temp != nullptr)
            {
                cout << temp->data << " ";
                temp = (direction == 'f') ? temp->next : temp->prev;
            }
            cout << endl;
        }
    }

    void rotate(int index)
    {
        if(index == 0 || is_empty())
        {
            return;
        }
        
        Node* temp = head;

        for(int i = 0 ; i != index ; i++)
        {
            if(temp == nullptr)
            {
                return;
            }
            temp = temp->next;
        }

        tail->next = head;
        head->prev = tail;

        temp->prev->next = nullptr;
        tail = temp->prev;
        temp->prev = nullptr;
        head = temp;
    }
};

int main()
{
    Doubly_Linked_List list;
    list.insert('E');
    list.insert('D');
    list.insert('C');
    list.insert('B');
    list.insert('A');

    list.rotate(4);

    list.display('f');
}