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
            int i = 0;

            while(table[index] != -1)
            {
                if(table[index] == val)
                {
                    return;
                }

                i++;
                index = (original_index + i * i) % table_size;

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
            int i = 0;

            while(table[index] != -1)
            {
                if(table[index] == val)
                {
                    table[index] = -1;
                    return;
                }

                i++;
                index = (original_index + i * i) % table_size;

                if(index == original_index)
                {
                    return;
                }
            }
        }

        void search(int val)
        {
            int index = hash_function(val);
            int original_index = index;
            int i = 0;

            while(table[index] != -1)
            {
                if(table[index] == val)
                {
                    cout << "Found\n";
                    return;
                }

                i++;
                index = (original_index+i*i) % table_size;

                if(index == original_index)
                {
                    break;
                }
            }

            cout << "Npt\n";
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
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(2);

    h.display();
    h.search(541);
    h.search(15);
}