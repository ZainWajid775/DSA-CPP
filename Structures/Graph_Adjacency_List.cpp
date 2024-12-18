#include <iostream>
#include <list>
using namespace std;

class Graph
{
    private:
        int vertices;
        list<int> *adj_list;

    public:

        Graph(int size)
        {
            vertices = size;
            adj_list = new list<int>[size];
        }

        void add_edge(int v1 , int v2)
        {
            // For directed (One way)
            adj_list[v1].push_back(v2);

            // For undirected (Two way)
            //adj_list[v2].push_back(v1);
        }

        void remove_edge(int v1 , int v2)
        {
            adj_list[v1].remove(v2);
        }

        void print_list(int source)
        {
            for(auto x : adj_list[source])
            {
                cout << x << " ";
            }
            cout << endl;
        }

        void print()
        {
            for(int i = 0 ; i < vertices ; i++)
            {
                cout << "Adjacency List of " << i << " is: ";
                for(auto x : adj_list[i])
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }

        void bfs(int source)
        {
            bool *visited = new bool[vertices];
            for(int i = 0 ; i < vertices ; i++)
            {
                visited[i] = false;
            }

            list<int> queue;
            list<int>:: iterator i;

            visited[source] = true;
            queue.push_back(source);

            while(!queue.empty())
            {
                int current = queue.front();
                cout << current << " ";

                queue.pop_front();

                for(i = adj_list[current].begin() ; i != adj_list[current].end() ; i++)
                {
                    if(!visited[*i])
                    {
                        queue.push_back(*i);
                        visited[*i] = true;
                    }
                }
            }

            delete[] visited;
        }



};

int main()
{
    Graph g(10);

    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(0, 5);
    g.add_edge(1, 2);
    g.add_edge(5, 0);
    g.add_edge(3, 4);
    g.add_edge(4, 5);

    g.print();

    g.bfs(0);
}