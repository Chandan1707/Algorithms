#include <iostream>

using namespace std;

template <class d_type>
class Node{
    public:
        d_type info;
        Node <d_type>*next;
    
    Node(d_type info){
        this->info = info;
        next = NULL;
    }
};

template <class d_type>
class Stack{
    private:
        Node <d_type>*head;
    public:
        Stack(){
            head = NULL;
        }
        void push(d_type info){
            Node <d_type>*temp = new Node<d_type>(info);
            temp->next = head;
            head = temp;
        }

        d_type pop(){
            Node <d_type>*temp;
            d_type val;
            if (temp){
                temp = head;
                head = head->next;
                val = temp->info;
                delete temp;
            }
            else
                exit;
            return val;
        }

        bool isEmpty(){
            bool res = false;
            if (head == NULL)
                res = true;
            return res;
        }
};

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
                Adj_matrix[fromVertex][toVertex] = Adj_matrix[toVertex][fromVertex] = 0;
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
            cout << "Naighbour of " << vertex << endl << "\t";
            for (int i = 0; i < this->vertex; i ++){
                if (Adj_matrix[i][vertex] == 1)
                    cout << "< " << i << " > " << ",";
            }
            cout << endl;
        }
        void showGraph(){
            cout << endl << "<Graph>" << endl;
            for (int i = 0; i < vertex; i++){
                cout << "Vertex " << i << endl;
                for (int j = 0; j < vertex; j ++){
                    if (Adj_matrix[i][j] == 1)
                        cout << "\t< " << i << " to " << j << " > " << endl;
                }
                cout << endl;
            }
        }
        void DFS(int start){
            Stack <int>stack;
            int v;
            int size = vertex;
            bool visited[size];
            for (int i = 0; i < size; i++){
                visited[i] = false;
            }
            stack.push(start);
            visited[start] = true;
            cout << "DFS traversal is :\n\t";
            while (!stack.isEmpty()){
                v = stack.pop();
                cout << v << ", ";
                for (int i = 0; i < size; i++){
                    if (Adj_matrix[v][i] == 1 && visited[i] == false){
                        stack.push(i);
                        visited[i] = true;
                    }
                }
            }
            cout << endl;
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
    // cout << "Enter no of vertices :";
    // cin>> vertex;
    Graph g1(6);
    // cout << "Enter no of Edges :";
    // cin >> edges;
    g1.addEdge(0, 1);
    g1.addEdge(0, 5);
    g1.addEdge(1, 5);
    g1.addEdge(4, 5);
    g1.addEdge(2, 5);
    g1.addEdge(1, 2);
    g1.addEdge(2, 4);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    // for (int i = 0; i < edges; i++){
    //     cout << "Enter Source Vertex :";
    //     cin >> fromVertex;
    //     cout << "Enter Destination Vertex :";
    //     cin >> toVertex;
    //     g1.addEdge(fromVertex, toVertex);
    // }
    g1.naighbours(2);
    g1.showGraph();
    g1.DFS(0);
    return 0;
}
