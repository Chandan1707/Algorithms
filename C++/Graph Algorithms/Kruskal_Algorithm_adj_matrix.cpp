#include<iostream>
using namespace std;
#define INF 999999
class edges{
    public:
        int source;
        int destination;
        int weight;
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

void Kruskal(int graph[][6]){
    int x, y;
    int cnt = 0;
    int edge_count = 9;
    int parent_set[6];
    int vertex = 6;
    for (int i = 0; i < vertex; i++)
        parent_set[i] = i;
    int cost = 0;

    edges *list_edges = new edges[edge_count];
    edges *mst_edge = new edges[vertex-1];
    for (int i = 0; i < 6; i ++){
        for (int j = 0; j < 6; j ++){
            if (i>j && graph[i][j] != 0 && graph[i][j] != INF){
                list_edges[cnt].source = i;
                list_edges[cnt].destination = j;
                list_edges[cnt].weight = graph[i][j];
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

    int graph[6][6] = {
        {0, 10, INF, INF, INF, 2},
        {10, 0,  2,  INF, INF, 5},
        {INF, 2,  0,  12,  4,  8},
        {INF, INF, 12, 0, 3, INF},
        {INF, INF,  4,  3, 0, 15},
        {2,  5,  8, INF,  15,  0}
        };
    int edge_count = 9;
    // edges *list_edges = new edges[edge_count];
    int cnt = 0;


    
    
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    Kruskal(graph);
    // for (int i = 0; i < cnt; i++){
    //     cout << list_edges[i].source << " ";
    //     cout << list_edges[i].destination << " ";
    //     cout << list_edges[i].weight << " ";
    //     cout << endl;
    // }
    
    // for (int i = 0; i < cnt; i++){
    //     cout << list_edges[i].source << " ";
    //     cout << list_edges[i].destination << " ";
    //     cout << list_edges[i].weight << " ";
    //     cout << endl;
    // }
    int vertex;
    int edges;
    int value;
    int fromVertex, toVertex;
    // cout << "Enter no of vertices :";
    // cin >> vertex;
    // Graph g1(vertex);
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
    // g1.showGraph();
    // Djkstra(g1, 0);
    // return 0;
}