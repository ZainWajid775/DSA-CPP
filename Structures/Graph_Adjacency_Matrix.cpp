#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    private:
        //2D vector for adjacency matrix
        vector<vector<int> > adj_matrix;
        int num_vertices;

    public:
        Graph(int vertices)
        {
            num_vertices = vertices;

            //Initialise all values to 0
            adj_matrix.resize(num_vertices , vector<int>(num_vertices , 0));
        }

        void add_edge(int u , int v , int weight = 1)
        {
            if(u >=0 && u < num_vertices && v>= 0 && v <num_vertices)
            {
                adj_matrix[u][v] = weight;  //For directed (One way)
                adj_matrix[v][u] = weight;  //For undirected (Two way)
            }
            else
            {
                cout << "Invalid\n";
            }
        }

        void remove_edge(int u , int v)
        {
            if(u >=0 && u < num_vertices && v>= 0 && v <num_vertices)
            {
                adj_matrix[u][v] = 0;
                adj_matrix[v][u] = 0;
            }
            else
            {
                cout << "Invalid\n";
            }
        }

        bool has_edge(int u , int v)
        {
            if(u >=0 && u < num_vertices && v>= 0 && v <num_vertices)
            {
                return adj_matrix[u][v] != 0;
            }
            return false;
        }

        void display_matrix()
        {
            for(int i = 0 ; i < num_vertices; i++)
            {
                for(int j = 0; j < num_vertices; j++)
                {
                    cout << adj_matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

};

int main() 
{
    Graph g(5); // Graph with 5 vertices

    // Add edges
    g.add_edge(0, 1);
    g.add_edge(0, 4, 2);
    g.add_edge(1, 2);
    g.add_edge(1, 3, 3);
    g.add_edge(1, 4);

    cout << "Adjacency Matrix:\n";
    g.display_matrix();
}