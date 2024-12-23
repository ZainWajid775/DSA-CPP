#include <iostream>
#include <vector>
using namespace std;

class Hash_Table
{
    private:
        int table_size;
        vector<int> table;

    public:
        Hash_Table(int size)
        {
            table_size = size;
            table.resize(table_size , -1);
        }

        int hash_function(int val)
        {
            return val % table_size;
        }

        void insert(int val)
        {
            int index = hash_function(val);
            int original_index = index;

            while(table[index] != -1)
            {
                index = (index + 1) % table_size;

                if(index == original_index)
                {
                    return;
                }
            }

            table[index] = val;
            
        }

        void remove(int val)
        {
            int index = hash_function(val);
            int original_index = index;

            while(table[index] != -1)
            {
                if(table[index] == val)
                {
                    table[index] = -1;
                    return;
                }

                index = (index + 1) % table_size;

                if(index == original_index)
                {
                    return;
                }
            }
        }

        void display()
        {
            for(int i = 0 ; i < table_size ; i++)
            {
                cout << table[i] << endl;
            }
        }

};

int main()
{
    Hash_Table h(5);

    h.insert(541);
    h.insert(541);
    h.insert(541);
    h.insert(541);
    h.insert(541);
    h.insert(20);

    h.display();
    
}