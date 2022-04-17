#include<iostream>
using namespace std;
class Node{
    public:
        int vertex;
        int distance;
        Node *next;

        Node(int vertex, int distance){
            this->vertex = vertex;
            this->distance = distance;
            next = NULL;
        }
};

class Graph{
    private:
        int vertices;
        Node **adj_list;
        void createGraph(){
            adj_list = new Node*[vertices];
        }

        void addEdge(int fromVertex, int toVertex, int value){
            Node *ptr=NULL;
            Node *temp = new Node(toVertex, value);
            
            ptr = adj_list[fromVertex];
            if (adj_list[fromVertex] == NULL){
                adj_list[fromVertex] = temp;
            }
            else{
                while (ptr->next){
                    ptr = ptr->next;
                }
                ptr->next = temp;
            }
        }
        void removeEdge(int fromVertex, int toVertex){
            Node *temp, *prev;
            if (adj_list[fromVertex] == NULL)
                return;
            else{
                prev = NULL;
                temp = adj_list[fromVertex];
                while(temp->next != NULL){
                    if (temp->vertex == toVertex)
                        break;
                    prev = temp;
                    temp = temp->next;
                }
                if (temp->vertex == toVertex){
                    if(prev == NULL){
                        adj_list[fromVertex] = temp->next;
                    }
                    else{
                        prev->next = temp->next;
                    }
                    delete temp;
                }
            }
        }
    public:
        Graph(int v){
            vertices = v;
            createGraph();
        }
        void showGraph(){
            Node *temp;
            for (int i = 0; i < vertices; i++){
                temp = adj_list[i];
                cout << i << endl;
                while (temp){
                    cout << "(" << "(" << i << "," << temp->vertex << ") -> " << temp->distance <<")" <<",";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
        void remove_Edge(int fromVertex, int toVertex){
            removeEdge(fromVertex, toVertex);
            removeEdge(toVertex, fromVertex);
        }
        void add_Edge(int fromVertex, int toVertex, int value){
            addEdge(fromVertex, toVertex, value);
            addEdge(toVertex, fromVertex, value);
        }
};
int main(){
    Graph graph(6);
    graph.add_Edge(0, 1, 10);
    graph.add_Edge(0, 5, 2);
    graph.add_Edge(1, 5, 5);
    graph.add_Edge(1, 2, 2);
    graph.add_Edge(5, 2, 8);
    graph.add_Edge(5, 4, 15);
    graph.add_Edge(2, 3, 12);
    graph.add_Edge(2, 4, 4);
    graph.add_Edge(3, 4, 3);

    graph.showGraph();

    graph.remove_Edge(5, 4);
    graph.showGraph();
    return 0;
}