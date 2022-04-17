#include<iostream>
#include<string>
using namespace std;

template  <class name>
class Edge{
    public:
        name info;
        int weight;
        Edge <name>*next;
    public:
        Edge(name val, int wt){
            info = val;
            weight = wt;
            next = NULL;
        }
};

template <class name>
class Vertex{
    public:
        name info;
        Edge <name>*next;
        Vertex <name>*down;
    public:
        Vertex(name val){
            info = val;
            next = NULL;
            down = NULL;
        }
};

template <class Name>
class Graph{
    private:
        int vertex;
        Vertex <Name>*adj_list;
        
        void addEdge(Name fromVertex, Name toVertex, int weight){
            Edge <Name>*new_edge = new Edge<Name>(toVertex, weight);
            Vertex <Name>*temp = adj_list;
            while (temp != NULL && temp->info != fromVertex){
                temp = temp->down;
            }
            new_edge->next = temp->next;
            temp->next = new_edge;
        }

        void removeEdge(Name fromVertex, Name toVertex){
            Vertex <Name>*temp = adj_list;
            Edge <Name>*edge = NULL;
            Edge <Name>*edge_prev = NULL;
            while (temp != NULL && temp->info != fromVertex){
                temp = temp->down;
            }
            if (temp){
                edge = temp->next;
                if (edge == NULL)
                    return;
                else{
                    while (edge && edge->info != toVertex){
                        edge_prev = edge;
                        edge = edge->next;
                    }
                    if (edge->info == toVertex){
                        if (edge_prev == NULL)
                            temp->next = edge->next;
                        else
                            edge_prev->next = edge->next;
                        delete edge;
                    }
                }
            }
        }

    public:

        Graph(){
            this->vertex = 0;
            adj_list = NULL;
        }

        void addVertex(Name name){
            vertex ++;
            
            Vertex <Name>*newVertex = new Vertex<Name>(name); 
            newVertex->down = adj_list;
            adj_list = newVertex;
        }

        void remove_vertex(Name vertexName){
            Vertex <Name>*temp = adj_list;
            Vertex <Name>*prev = NULL;
            Edge <Name>*edge = NULL;
            Edge <Name>*edge_temp = NULL;
            
            while (temp && temp->info != vertexName){
                prev = temp;
                temp = temp->down;
            }
            if (temp->info == vertexName){
                if (prev == NULL)
                    adj_list = temp->down;
                else
                    prev->down = temp->down;
                edge = temp->next;
                delete temp;
                while (edge){
                    edge_temp = edge;
                    edge = edge->next;
                    delete edge_temp;
                }
                temp = adj_list;
                while (temp){
                    removeEdge(temp->info, vertexName);
                    temp = temp->down;
                }
            }
        }

        void add_edge(Name fromVertex, Name toVertex, int weight){
            addEdge(fromVertex, toVertex, weight);
            addEdge(toVertex, fromVertex, weight);
        }
        void remove_edge(Name fromVertex, Name toVertex){
            removeEdge(fromVertex, toVertex);
            removeEdge(toVertex, fromVertex);
        }
        void showGraph(){
            Vertex <Name>*temp = adj_list;
            Edge <Name>*edge = NULL;
            while (temp){
                edge = temp->next;
                cout << "Vertex : <" << temp->info << ">" << endl;
                while (edge){
                    cout << "\t<" << temp->info << " to " << edge->info << " > " << "-- " << edge->weight <<endl;
                    edge = edge->next;
                }
                temp = temp->down;
                cout << endl;
            }
            
        }

        bool is_adjacent(Name fromVertex, Name toVertex){
            bool result = false;

            Vertex <Name>*temp = adj_list;
            Edge <Name>*edge = NULL;

            while (temp && temp->info != fromVertex)
                temp = temp->down;
            if (temp->info == fromVertex){
                edge = temp->next;
                while (edge){
                    if (edge->info == toVertex){
                        result = true;
                        break;
                    }
                    edge = edge->next;
                }
            }
            return result;
        }

        void naighbour(Name vertexName){
            Vertex <Name>*temp = adj_list;
            Edge <Name>*edge = NULL;

            while (temp && temp->info != vertexName)
                temp = temp->down;
            if (temp->info == vertexName){
                cout << "Naighbour of " << vertexName << " : " << endl;
                edge = temp->next;
                while (edge){
                    cout << "\t<" << edge->info << " > " << "-- " << edge->weight <<endl;
                    edge = edge->next;
                }
            }
        }
};

int main(){

    Graph <string>g;
    g.addVertex("kolkata");
    g.addVertex("Delhi");
    g.addVertex("Mumbai");
    g.addVertex("Channai");
    
    g.add_edge("Delhi","kolkata",12);
    g.add_edge("Delhi","Mumbai",13);
    g.add_edge("kolkata","Mumbai",17);
    
    g.showGraph();

    g.naighbour("Delhi");
    bool res = g.is_adjacent("Delhi", "kolkata");
    cout << res << endl;
    res = g.is_adjacent("Delhi", "Channai");
    cout << res << endl;

    // g.remove_vertex("kolkata");
    // g.remove_edge("Delhi", "Mumbai");

    // g.showGraph();
    return 0;
}
