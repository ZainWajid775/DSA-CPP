#include <iostream>
using namespace std;

struct node
{
    int data;
    //Contains pointer to next and previous node in list
    node* next;
    node* prev;

    node(int val) : data(val) , next(nullptr) , prev(nullptr) {}
};

class doubly_linked_list
{
    //Head and tail pointers are used 
    private:
    node* head;
    node* tail;

    public:
    doubly_linked_list() : head(nullptr), tail(nullptr) {}  

    void insert_at_start(int val)
    {
        node* new_node = new node(val);
        new_node->prev = nullptr;

        //If the list is not empty, new node points to the previous head and vice versa and head now points to the new node
        if(head != nullptr)
        {
            head->prev = new_node;
            new_node->next = head;

        }
        //If the list is empty, both point to the new node
        else
        {
            tail = new_node;
            new_node->next = nullptr;
        }

        //Regardless of the no of nodes, the head will always point to the new node if it is inserted at the start
        head = new_node;
    }

    void insert_at_end(int val)
    {
        node* new_node = new node(val);
        new_node->next = nullptr;
        //If the list is not empty, new node points to the previous tail
        if(tail != nullptr)
        {
            tail->next = new_node;
            new_node->prev = tail;
        }
        //If the list is empty both point to the new node
        else
        {
            head = new_node;
            new_node->prev = nullptr;
        }
        tail = new_node;
    }

    void insert_at_index(int index , int val)
    {
        if(index == 0)
        {
            insert_at_start(val);
            return;
        }
        else
        {
            node* temp = head;
            int node_count = 0;
            //Check if the index is valid and traverse to the node before the specified index
            for(int i = 0 ; i < index - 1 && temp->next != nullptr ; i++)
            {
                temp = temp->next;
                node_count++;
            }

            //It the node is to be inserted at last index, the node must h=be pointing to a null pointer
            if(temp->next == nullptr && node_count == index - 1)
            {
                insert_at_end(val);
            }

            //else the specified index should be less the the number of nodes
            else if(index < node_count)
            {
                node* new_node = new node(val);
                new_node->prev = temp;
                new_node->next = temp->next;
                temp->next = new_node;
                temp = temp->next;
                temp->prev = new_node;
            }
            else
            {
                cout << "Invalid index\n";
            }

        }
        
    }

    void delete_at_index(int index)
    {
        if(index < 0)
        {
            cout << "Invalid index\n";
        }
        else if(index == 0)
        {
            node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        else
        {
            node* temp = head;
            //Traverse to the node before the one to be deleted
            for(int i = 0 ; i < index && temp != nullptr; i++)
            {
                temp = temp->next;
            }
            //Index out of bounds
            if(temp == nullptr)
            {
                cout << "Invalid index\n";
            }
            else
            {
                //If the list has more than 1 node
                if(temp->prev != nullptr)
                {
                    temp->prev->next = temp->next;
                }
                //If the list has first node deleted
                else
                {
                    head = temp->next;
                }

                //If the list has only 1 node
                if(temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }
                //If the list has last node deleted
                else
                {
                    tail = temp->next;
                }
                delete temp;
            }
        }
    }

    //Printing from the start utilises the head and next to traverse the list
    void print_from_start()
    {
        if(head != nullptr)
        {
            node* temp = head;
            int count = 0;
            while(temp != nullptr)
            {
                cout << "Index : " << count << " Data : " << temp->data << endl;
                count ++;
                temp = temp->next; 
            }
        }
        else
        {
            cout << "Empty list\n";
        }
    }

    //Printing from the end utilises the prev and tail for traversing the list
    void print_from_end()
    {
        if(head != nullptr)
        {
            node* temp = tail;
            int count = 0;
            while(temp != nullptr)
            {
                cout << "Reverse Index : " << count << " Data : " << temp->data << endl;
                count ++;
                temp = temp->prev;
            }
        }
        else
        {
            cout << "Empty list\n";
        }
    }
};

int main()
{
    doubly_linked_list list;
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_start(1);
    list.insert_at_index(3 , 4);
    list.delete_at_index(5);
    list.print_from_start();
}