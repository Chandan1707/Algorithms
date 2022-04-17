#include <iostream>
using namespace std;

class Graph{
    private:
        int vertex;
        int edges;
        int **Adj_matrix;
    public:
        int getVertex(){
            return vertex;
        }
        Graph(int v){
            vertex = v;
            createMatrix();
        }
        void createMatrix(){
            Adj_matrix = (int **)malloc(vertex * sizeof(int*));
            for (int i = 0; i < vertex; i ++)
                Adj_matrix[i] = (int *)malloc(vertex * sizeof(int));
            for (int i = 0; i < vertex; i++)
                for(int j = 0; j < vertex; j ++)
                    Adj_matrix[i][j] = 0;
        }
        void deleteEdge(int fromVertex, int toVertex){
            if (Adj_matrix[fromVertex][toVertex]==1){
                vertex --;
                Adj_matrix[fromVertex][toVertex] = Adj_matrix[toVertex][fromVertex] = 0;
            }
        }
        void addVertex(){
            vertex ++;
            int **Adj_matrix = (int **)realloc(Adj_matrix, vertex);
            for (int i = 0; i < vertex; i ++){
                Adj_matrix[i][vertex] = 1;
                Adj_matrix[vertex][i] = 1;
            }
        }
        void addEdge(int fromVertex, int toVertex){
            if (Adj_matrix[fromVertex][toVertex] == 0 && Adj_matrix[toVertex][fromVertex] == 0){
                Adj_matrix[fromVertex][toVertex] = 1;
                Adj_matrix[toVertex][fromVertex] = 1;
            }
        }
        bool isAdjecent(int fromVertex, int toVertex){
            return Adj_matrix[fromVertex][toVertex] == 1 && Adj_matrix[toVertex][fromVertex] == 1;
        }
        void naighbours(int vertex){
            
            for (int i = 0; i < this->vertex; i ++){
                if (Adj_matrix[vertex][i] == 1){
                    cout << vertex << ", " << i << ")" << " , ";
                }
                cout << "\t";
            }
        }
        void showGraph(){
            cout << endl << "<Graph>" << endl;
            for (int i = 0; i < vertex; i++){
                cout << "\t";
                naighbours(i);
                cout << endl;
            }
        }
        ~Graph(){
            for (int i = 0; i < vertex; i++)
                delete[] Adj_matrix[i];
            delete[] Adj_matrix;
        }
};


int main(){
    int vertex;
    int edges;
    int fromVertex, toVertex;
    cout << "Enter no of vertices :";
    cin>> vertex;
    Graph g1(vertex);
    cout << "Enter no of Edges :";
    cin >> edges;
    for (int i = 0; i < edges; i++){
        cout << "Enter Source Vertex :";
        cin >> fromVertex;
        cout << "Enter Destination Vertex :";
        cin >> toVertex;
        g1.addEdge(fromVertex, toVertex);
    }
    g1.naighbours(2);
    g1.showGraph();
}