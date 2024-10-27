#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;

    node(int val) : data(val) , next(nullptr) {}
};

class circular_linked_list
{
    private:
    node* head;

    public:
    //Constructor
    circular_linked_list() : head(nullptr) {}

    //Insert at start
    void insert_at_start(int val)
    {
        node* new_node = new node(val);

        //If list is empty node is inserted 
        if(head == nullptr)
        {
            head = new_node;
            new_node->next = head;
        }

        //otherwise the newnode is inserted at the start but a temp node is used to link the last node to the new head
        else
        {
            node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            new_node->next = head;
            head = new_node;
            temp->next = new_node;
        }
    }

    //Insert at index
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

            //Traverse entire list till the end and if we reach the head, index is invalid
            //i < index used as we need to check the last nodes next
            for(int i = 0 ; i < index - 1  ; i ++)
            {
                temp = temp->next;
                if(temp->next == head)
                {
                    cout << "Invalid index\n";
                    return;
                }
            }

            node* new_node = new node(val);
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    //Insert at end
    void insert_at_end(int val)
    {
        node* temp = head;

        //If list is empty
        if(head == nullptr)
        {
            insert_at_start(val);
        }

        //Traverse list till last node
        while(temp->next != head)
        {
            temp = temp->next;
        }

        node* new_node = new node(val);
        temp->next = new_node;
        new_node->next = head;
    }

    //Delete at index
    void delete_at_index(int index)
    {
        if(index < 0 || head == nullptr)
        {
            cout << "Invalid index\n";
            return;
        }

        //Deleting node at index 0
        if(index == 0)
        {
            //If only one node exists, list is deleted
            node* temp = head;
            if(temp->next == head)
            {
                delete temp;
                return;
            }

            //Incase nodes are more than 1 and deleting at index 0
            else
            {
                node* last = head;
                while(last->next != head)
                {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
                delete temp;
                return;
            }
        }

        //Deleting at specified index
        node* temp = head;
        node* prev;
        for(int i = 0 ; i < index ; i ++)
        {
            prev = temp;
            temp = temp->next;
            if(temp->next == head)
            {
                cout <<"Invalid index\n";
                return;
            }
        }

        prev->next = temp->next;
        delete temp;
        return;

    }

    //Print entire list
    void print()
    {
        if(head == nullptr)
        {
            cout << "List empty\n";
        }
        else
        {
            //Temp node traverse entire list until the end
            int count = 1;
            node* temp = head;

            //Do while used to ensure last node is also printed
            do
            {
                cout << "Index : " << count << " Value : " << temp->data << endl;
                temp = temp->next;
                count ++;

            }while(temp != head);
            cout << "Nullptr" << endl;
        }
    }




};

int main()
{
    circular_linked_list list;

    list.insert_at_start(1);
    list.insert_at_start(2);
    list.insert_at_start(3);
    list.insert_at_end(10);
    list.insert_at_index(3,4);
    list.print();

    list.delete_at_index(0);
    list.print();

    list.delete_at_index(4);
    list.print();


}