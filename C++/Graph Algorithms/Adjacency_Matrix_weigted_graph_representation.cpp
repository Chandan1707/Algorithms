#include <iostream>
#define INF 99999
using namespace std;

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
            if (toVertex > fromVertex)
                adj_matrix[toVertex][fromVertex] = value;
            else
                adj_matrix[fromVertex][toVertex] = value;
        }
        void removeEdge(int toVertex, int fromVertex){
            if (toVertex > fromVertex){
                adj_matrix[toVertex][fromVertex] = INF;
            }
            else
                adj_matrix[fromVertex][toVertex] = INF;
        }
        void showGraph(){
            for (int i = 0; i < vertices; i++){
                for (int j = 0; j < vertices; j++){
                    if (i > j && adj_matrix[i][j] != 99999){
                        cout << "(" << i << "," << j << ")" << "," << adj_matrix[i][j] << "  ";
                    }
                }
            }
            cout << endl;
        }
};

int main(){
    int vertex;
    int edges;
    int value;
    int fromVertex, toVertex;
    cout << "Enter no of vertices :";
    cin >> vertex;
    Graph g1(vertex);
    cout << "Enter no of Edges :";
    cin >> edges;
    for (int i = 0; i < edges; i++){
        cout << "Enter Source Vertex :";
        cin >> fromVertex;
        cout << "Enter Destination Vertex :";
        cin >> toVertex;
        cout << "Enter wieght of edge :";
        cin >> value;
        g1.addEdge(fromVertex, toVertex, value);
    }
    g1.showGraph();
    return 0;
}