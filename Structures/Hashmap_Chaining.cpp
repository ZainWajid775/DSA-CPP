#include <iostream>
#include <list>
using namespace std;


class Hash_Table
{
    private:
        int table_size;
        list<int>* table;

    public:
        Hash_Table(int size)
        {
            table_size = size;
            table = new list<int>[size];
        }

        int hash_function(int key)
        {
            return key % table_size;
        }

        void insert(int val)
        {
            int index = hash_function(val);
            table[index].push_back(val);
        }

        void del(int val)
        {
            int index = hash_function(val);

            list<int>::iterator i;

            for(i = table[index].begin() ; i != table[index].end() ; i++)
            {
                if(*i == val)
                {
                    break;
                }
            }

            if(i != table[index].end())
            {
                table[index].erase(i);
            }
        }

        void display()
        {
            for (int i = 0 ; i < table_size ; i++)
            {
                cout << i << " ";
    
                for (auto x : table[i])
                {
                    cout << " --> " << x;
                }
                cout << endl;
            }
        }
};

int main()
{
    Hash_Table t(5);

    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);

    t.display();
}