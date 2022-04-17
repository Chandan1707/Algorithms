#include<iostream>
#define INF 999999
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
            
            adj_matrix[toVertex][fromVertex] = value;
            adj_matrix[fromVertex][toVertex] = value;
        }
        void removeEdge(int toVertex, int fromVertex){
            
            adj_matrix[toVertex][fromVertex] = INF;
            adj_matrix[fromVertex][toVertex] = INF;
        }
        void showGraph(){
            for (int i = 0; i < vertices; i++){
                for (int j = 0; j < vertices; j++){
                    if (i > j && adj_matrix[i][j] != INF){
                        cout << "(" << i << "," << j << ")" << "," << adj_matrix[i][j] << "  ";
                    }
                }
            }
            cout << endl;
        }
};



int minFind(bool visited[], int distance[], int n){
    int index = -1;
    int value = INF;
    for (int i = 0; i < n; i++){
        if (visited[i] == false && distance[i] < value){
            value = distance[i];
            index = i;
        }
    }
    return index;
}

void Djkstra(Graph graph, int index){
    int min;
    bool *visited = (bool*)malloc(graph.vertices * sizeof(bool));
    int *distance = (int *)malloc(graph.vertices * sizeof(int));

    for(int i = 0; i < graph.vertices; i ++){
        visited[i] = false;
        distance[i] = INF;
    }
    distance[index] = 0;

    for (int i = graph.vertices; i > 0; i--){
        min = minFind(visited, distance, graph.vertices);
        visited[min] = true;  
        for (int j = 0; j < graph.vertices; j++){
            if (distance[min] + graph.adj_matrix[min][j] < distance[j]){
                distance[j] = distance[min] + graph.adj_matrix[min][j];
                
            }
        }
    }
    cout << "Min Distance List :"<< endl;
    for (int i = 0; i < graph.vertices; i ++){
        cout << distance[i] << " ";
    }
    cout << endl;
}

int main(){
/*
    int graph[6][6] = {
        {0, 10, INF, INF, INF, 2},
        {10, 0,  2,  INF, INF, 5},
        {INF, 2,  0,  12,  4,  8},
        {INF, INF, 12, 0, 3, INF},
        {INF, INF,  4,  3, 0, 15},
        {2,  5,  8, INF,  15,  0}
        };
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    */
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
    Djkstra(g1, 0);
    return 0;
}