#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int value) : val(value) , next(nullptr) {}
};

long multiply(Node* list_1 , Node* list_2)
{
    if(list_1 == nullptr || list_2 == nullptr)
    {
        return 0;
    }

    Node* temp_1 = list_1;
    Node* temp_2 = list_2;

    int int_1 = 0;
    int int_2 = 0;

    while(temp_1 != nullptr)
    {
        int_1 = int_1 * 10 + temp_1->val;
        temp_1 = temp_1->next;
    }

    while(temp_2 != nullptr)
    {
        int_2 = int_2 * 10 + temp_2->val;
        temp_2 = temp_2->next;
    }

    return (int_1 * int_2);
}

void display(Node* list_head)
{
    if(list_head == nullptr)
    {
        cout << "List Empty\n";
    }
    else
    {
        Node* temp = list_head;

        cout << "List : ";
        while(temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main()
{
    Node* head_1 = new Node(1);
    head_1->next = new Node(0);

    Node* head_2 = new Node(2);

    long result = multiply(head_1, head_2);
    cout << result << endl;
}