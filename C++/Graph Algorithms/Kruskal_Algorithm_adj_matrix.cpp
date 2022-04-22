#include <iostream>
#define INF 99999
using namespace std;

class edges{
    public:
        int source;
        int destination;
        int weight;
};

class Graph{
    public:
        int edge_count;
        int vertices;
        int **adj_matrix;
    
    
        Graph(int v){
            vertices = v;
            edge_count = 0;
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
            edge_count ++;
            if (toVertex > fromVertex)
                adj_matrix[toVertex][fromVertex] = value;
            else
                adj_matrix[fromVertex][toVertex] = value;
        }
        void removeEdge(int toVertex, int fromVertex){
            edge_count --;
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


void sort_by_weight(edges edge_list[], int n){
    edges temp;
    for (int i = 0; i < n-1; i ++){
        for (int j = 0; j < n-i-1; j ++){
            if (edge_list[j].weight > edge_list[j+1].weight){
                temp = edge_list[j];
                edge_list[j] = edge_list[j + 1];
                edge_list[j + 1] = temp;
            }
        }
    }
}

void set_union(int parent_set[], int a, int b, int size){
    int temp = parent_set[b];
    for (int i = 0; i < size; i++){
        if (parent_set[i] == temp){
            parent_set[i] = parent_set[a];
        }
    }
}

int find_parent_set(int parent[], int n){
    return parent[n];
}

void Kruskal(Graph graph){
    int x, y;
    int cnt = 0;
    int vertex = graph.vertices;
    int edge_count = graph.edge_count;
    
    int parent_set[vertex];
    for (int i = 0; i < vertex; i++)
        parent_set[i] = i;
    int cost = 0;

    edges *list_edges = new edges[edge_count];
    edges *mst_edge = new edges[vertex-1];


    for (int i = 0; i < 6; i ++){
        for (int j = 0; j < 6; j ++){
            if (i>j && graph.adj_matrix[i][j] != 0 && graph.adj_matrix[i][j] != INF){
                list_edges[cnt].source = i;
                list_edges[cnt].destination = j;
                list_edges[cnt].weight = graph.adj_matrix[i][j];
                cnt ++;
            }
        }
    }
    cnt = 0;
    sort_by_weight(list_edges, edge_count);
    for (int i = 0; i < edge_count; i ++){
        x = find_parent_set(parent_set, list_edges[i].source);
        y = find_parent_set(parent_set, list_edges[i].destination);
        if (x != y){
            cost = cost + list_edges[i].weight;
            set_union(parent_set, x, y, vertex);
            mst_edge[cnt ++] = list_edges[i];
        }
    }
    cout << endl << "Cost :" << cost << endl;
    for (int i = 0; i < vertex-1; i++){
        cout << mst_edge[i].source << " ";
        cout << mst_edge[i].destination << " ";
        cout << mst_edge[i].weight << " ";
        cout << endl;
    }
}

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
    g1.showGraph();

    Kruskal(g1);
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