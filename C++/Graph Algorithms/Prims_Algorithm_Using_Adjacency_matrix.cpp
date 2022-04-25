#include <iostream>
#define INF 99999
using namespace std;
class mst_edge{
    public:
        int v1;
        int v2;
        int weight;
};

class Graph{
    public:
        int vertices;
        int **adj_matrix;
    
    
        Graph(int v){
            vertices = v;
            createGraph();
        }
        int getVertex(){
            return vertices;
        }
        void createGraph(){
            
            adj_matrix = (int **)malloc(vertices * sizeof(int*));
            for (int i = 0; i < vertices; i++)
                adj_matrix[i] = (int *)malloc(vertices * sizeof(int));
            
            for (int i = 0; i < vertices; i ++)
                for (int j = 0; j < vertices; j++){
                    if (i == j)
                        adj_matrix[i][j] = 0;
                    else
                        adj_matrix[i][j] = INF;
                        adj_matrix[j][i] = INF;
                }
            
        }
        void addEdge(int toVertex, int fromVertex, int value){
            adj_matrix[toVertex][fromVertex] = value;
            adj_matrix[fromVertex][toVertex] = value;
        }
        void removeEdge(int toVertex, int fromVertex){
            adj_matrix[toVertex][fromVertex] = INF;
            adj_matrix[fromVertex][toVertex] = INF;
        }
        bool isAdjecent(int fromVertex, int toVertex){
            return adj_matrix[fromVertex][toVertex] == 1 && adj_matrix[toVertex][fromVertex] == 1;
        }
        void naighbours(int vertex){
            cout << "Naighbour of " << vertex << endl << "\t";
            for (int i = 0; i < vertices; i ++){
                if (adj_matrix[i][vertex] != INF && adj_matrix[i][vertex] != 0)
                    cout << "< " << i << " > " << ",";
            }
            cout << endl;
        }
        void showGraph(){
            cout << endl << "<Graph>" << endl;
            for (int i = 0; i < vertices; i++){
                cout << "Vertex " << i << endl;
                for (int j = 0; j < vertices; j ++){
                    if (adj_matrix[i][j] != INF && adj_matrix[i][j] != 0)
                        cout << "\t< " << i << " to " << j << " > -- " << adj_matrix[i][j] << endl;
                }
                cout << endl;
            }
        }

        void prims(int start_vertex){
            bool visited[vertices];
            for (int i = 0; i < vertices; i++){
                visited[i] = false;
            }
            mst_edge mst_list[vertices-1];
            visited[start_vertex] = true;
            int cost = 0;
            int source = start_vertex;
            int destination = 0;
            int cnt = 0;
            int min_cost = INF;
            while (cnt < vertices-1){
                min_cost = INF;
                for (int i = 0; i < vertices; i++){
                    if (visited[i] == true){
                        for (int j = 0; j < vertices; j ++){
                            if (visited[j] == false && adj_matrix[i][j] != 0 && adj_matrix[i][j] != INF && adj_matrix[i][j] < min_cost){
                                source = i;
                                destination = j;
                                min_cost = adj_matrix[source][destination];
                            }
                        }
                    }
                }
                visited[destination] = true;
                cost += min_cost;
                mst_list[cnt].v1 = source;
                mst_list[cnt].v2 = destination;
                mst_list[cnt].weight = min_cost;
                cnt ++;
            }
            cout << endl << "Prims Algorithm : " << endl;
            cout << "Consider Edges : " << endl;
            for (int i = 0; i < vertices-1; i ++){
                cout << "\t< " << mst_list[i].v1 << " , " << mst_list[i].v2 << "> -- " << mst_list[i].weight << endl;
            }
            cout << "cost of mst : " << cost << endl;
        }
};



int main(){

    int vertex ;
    int edges;
    int value;
    int fromVertex, toVertex;
    // cout << "Enter no of vertices :";
    // cin >> vertex;
    vertex = 6;
    Graph g1(vertex);

    g1.addEdge(0, 1, 10);
    g1.addEdge(0, 5, 2);
    g1.addEdge(1, 5, 5);
    g1.addEdge(4, 5, 15);
    g1.addEdge(2, 5, 8);
    g1.addEdge(1, 2, 2);
    g1.addEdge(2, 4, 4);
    g1.addEdge(2, 3, 12);
    g1.addEdge(3, 4, 3);
    // cout << "Enter no of Edges :";
    // cin >> edges;
    // for (int i = 0; i < edges; i++){
    //     cout << "Enter Source Vertex :";
    //     cin >> fromVertex;
    //     cout << "Enter Destination Vertex :";
    //     cin >> toVertex;
    //     cout << "Enter wieght of edge :";
    //     cin >> value;
    //     g1.addEdge(fromVertex, toVertex, value);
    // }
    g1.naighbours(0);
    g1.showGraph();
    g1.prims(1);
    return 0;

    // int graph[6][6] = {
    //     {0, 10, INF, INF, INF, 2},
    //     {10, 0,  2,  INF, INF, 5},
    //     {INF, 2,  0,  12,  4,  8},
    //     {INF, INF, 12, 0, 3, INF},
    //     {INF, INF,  4,  3, 0, 15},
    //     {2,  5,  8, INF,  15,  0}
    //     };
    // int edge_count = 9;
    // int cnt = 0;
    // for (int i = 0; i < 6; i++){
    //     for (int j = 0; j < 6; j++)
    //         cout << graph[i][j] << " ";
    //     cout << endl;
    // }
    // Kruskal(graph);
}