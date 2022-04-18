
#include<iostream>
#include<string>
using namespace std;
#define INF 999999;

template <class Name>
class Visited_and_Distance{
    public:
        Name info;
        bool viseted;
        int distance;

        // Visited_and_Distance(Name name, int distance = INF){
        //     info = name;
        //     viseted = false;
        //     this->distance = distance;
        // }
};

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
                    if (edge && edge->info == toVertex){
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
            if (temp && temp->info == vertexName){
                vertex --;
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
            if (temp && temp->info == vertexName){
                cout << "Naighbour of " << vertexName << " : " << endl;
                edge = temp->next;
                while (edge){
                    cout << "\t<" << edge->info << " > " << "-- " << edge->weight <<endl;
                    edge = edge->next;
                }
            }
        }

        int find_min_value(Visited_and_Distance <Name>vistied_and_distance[]){

            int index = -1;
            int val = INF;
            for (int i = 0; i < vertex; i++){
                if (vistied_and_distance[i].viseted == false && vistied_and_distance[i].distance < val){
                    index = i;
                    val = vistied_and_distance[i].distance;
                }
            }

            return index;
        }
        
        void updated_visited_distance(Visited_and_Distance <Name>vistied_and_distance[], Name name, int distance){
            for (int i = 0; i < vertex; i ++){
                if (vistied_and_distance[i].info == name){
                    vistied_and_distance[i].distance = distance;
                    
                }
                    
            } 
        }
        int get_distance(Visited_and_Distance <Name>vistied_and_distance[], Name name){
            int distance = 0;
            for (int i = 0; i < vertex; i ++){
                if (vistied_and_distance[i].info == name)
                    distance = vistied_and_distance[i].distance;
            }   
            return distance;
        }

        void djkstra(Name start_point){
            
            Visited_and_Distance <Name>*visited_and_distance = new Visited_and_Distance<Name>[vertex];
            Vertex <Name>*temp = adj_list;
            Edge <Name>*edge = NULL;
            int i = 0;
            while (temp){
                visited_and_distance[i].viseted = false;
                visited_and_distance[i].info = temp->info;
                visited_and_distance[i].distance = INF;
                temp = temp->down;
                i ++;
            }
            // visited_and_distance[start_point].visted = true;
            updated_visited_distance(visited_and_distance, start_point, 0);
            
            
            for (i = vertex; i > 0; i --){
                int min = find_min_value(visited_and_distance);
                visited_and_distance[min].viseted = true;
                temp = adj_list;
                while (temp && temp->info != visited_and_distance[min].info){
                    temp = temp->down;
                }
                if (temp->info == visited_and_distance[min].info){
                    
                    edge = temp->next;
                    while (edge){
                        int distance = visited_and_distance[min].distance;
                        if (distance + edge->weight < get_distance(visited_and_distance, edge->info)){
                            distance = distance + edge->weight;
                            updated_visited_distance(visited_and_distance, edge->info, distance);
                        }
                        edge = edge->next;
                    }
                }

            }
            cout << "Shortest distance from "<< start_point << "(Djkstra) :"<< endl ;
            for (i = vertex-1; i >= 0; i--){
                cout << "\t< " << visited_and_distance[i].info << " , " << visited_and_distance[i].distance << " >" << endl;
            }
            cout << endl;
        }
};

int main(){
    string v1 = "v1";
    string v2 = "v2";
    string v3 = "v3";
    string v4 = "v4";
    string v5 = "v5";
    string v6 = "v6";
    

    Graph <string>g;
    g.addVertex(v1);
    g.addVertex(v2);
    g.addVertex(v3);
    g.addVertex(v4);
    g.addVertex(v5);
    g.addVertex(v6);
    
    g.add_edge(v1, v2, 10);
    g.add_edge(v1, v6, 2);
    g.add_edge(v2, v6, 5);
    g.add_edge(v2, v3, 2);
    g.add_edge(v3, v6, 8);
    g.add_edge(v5, v6, 15);
    g.add_edge(v3, v5, 4);
    g.add_edge(v3, v4, 12);
    g.add_edge(v4, v5, 3);
    
    g.showGraph();

    g.naighbour(v4);
    g.naighbour("v7");

    cout << endl;
    bool res = g.is_adjacent(v1, v3);
    if (res)
        cout << "Edge < " << v1 << "," << v3 << " >" << " -- True" << endl;
    else
        cout << "Edge < " << v1 << "," << v3 << " >" << " -- false" << endl;
    
    res = g.is_adjacent(v1, v6);
    if (res)
        cout << "Edge < " << v1 << "," << v6 << " >" << " -- True" << endl;
    else
        cout << "Edge < " << v1 << "," << v6 << " >" << " -- false" << endl;
    cout << endl;

    // g.remove_vertex("kolkata");
    // g.remove_edge("Delhi", "Mumbai");

    // g.showGraph();

    g.djkstra(v1);
    return 0;
}
