#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    int val;

    Node(int value) : val(value) , next(nullptr) {}
};

Node* reversal(Node* list_head)
{
    //Operations to be performed on curret node
    Node* current = list_head;

    //Stores the one behind current
    Node* prev = nullptr;

    //Stores the one after current
    //Ensures next pointer address is saved after currents next is made null
    Node* next = nullptr;

    while(current != nullptr)
    {
        //1. Store next nodes address
        next = current->next;

        //Change current nodes next to the node behindit (Null in case of head)
        current->next = prev;

        //Update previous to current node and current moves to next one
        prev = current;
        current = next;
    }

    //Return new head
    return prev;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = reversal(head);

    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}