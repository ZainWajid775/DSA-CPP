#include <iostream>
using namespace std;

struct node
{
    int data;         
    node* next;   

    node(int value) : data(value) , next(nullptr) {}
};

class linked_list
{
    //Start of the list
    private:
    node* head;

    public:
    linked_list() : head(nullptr) {}

    //Insert at start
    void insert_at_start(int value)
    {   
        //New node made the head points to 
        node* new_node = new node(value); 
        new_node->next = head;
        head = new_node;

    }

    //Insert at node index (index + 1)
    void insert_at_index(int index , int value)
    {
        if(index < 1) 
        {
            cout << "Invalid index\n";
            return;
        }
        else if (index  == 1)
        {
            insert_at_start(value);
            return;
        }

        //If the index is greater than the list, error shown
        node* temp = head;
        for(int i = 0 ; i < index -  2 ; i++)
        {
            if(temp == nullptr)
            {
                cout << "Invalid index\n";
                return;
            }
            temp = temp->next;
        }

        //If the last index is given the entire list is traversed and insertion done at end
        //Last node will be null pointer
        if(temp == nullptr)
        {
            insert_at_end(value);
            return;
        }

        //Otherwise new nodes next points to the next node and the previous node now points to the new node
        node* new_node = new node(value);
        new_node->next = temp->next;
        temp->next = new_node;
        return;


    }

    //Insert at end
    void insert_at_end(int value)
    {
        node* new_node = new node(value);
        //If list is empty, the new node becomes the  head
        if (head == nullptr)
        {
            head = new_node;
        }
        //If not empty a temporary node pointer transverses the list till the end and links the new node at the end
        else
        {
            node* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void print()
    {
        //Temp node traverse entire list until the end
        int count = 1;
        node* temp = head;
        while(temp != nullptr)
        {
            cout << "Index : " << count << " Value : " << temp->data << endl;
            temp = temp->next;
            count ++;

        }
        cout << "Nullptr" << endl;

    }

    //Delete a node (index + 1)
    void delete_node (int index)
    {
        //Prevois node is used as well as it has to be linked to the node after the deleted one
        index = index - 1;
        node* temp;
        node* prev = nullptr;
        temp = head;

        //Delete head
        if(index == 0)
        {
            head = head->next;
            delete temp;
            cout << "Deleted\n";
            return;
        }

        //If list is empty
        if(head == nullptr)
        {
            cout << "List empty\n";
            return;
        }

        //Out of rangeindex
        for(int i = 0 ; i < index ; i++)
        {
            prev = temp;
            temp = temp->next;
            if(temp == nullptr)
            {
                cout << "Invalid index\n";
                return;
            }
        }

        //Previous node now stores the node after the one to be deleted 
        prev->next = temp->next;
        //Node deleted
        delete temp;

    }


};


int main()
{
    linked_list list;

    list.insert_at_start(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(4);
    list.insert_at_end(5);
    list.insert_at_index(3 , 100);

    list.print();

    system("read");

    list.delete_node(1);


    list.print();
}