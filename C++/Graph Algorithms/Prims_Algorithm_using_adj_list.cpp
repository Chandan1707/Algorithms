#include<iostream>
#include<string>
using namespace std;
template <class d_type>
class mst_edge{
    public:
        d_type v1;
        d_type v2;
        int weight;
};

template <class d_type>
class visited{
    public:
        d_type info;
        bool visit;
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
            if (temp && temp->info == fromVertex){
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
        Vertex<Name>* get_vertex_from_name(Name name){
            Vertex <Name>*temp = adj_list;
            while (temp){
                if (temp->info == name){
                    break;
                }
                temp = temp->down;
            }
            return temp;
        }
        bool get_visited_info(visited <Name>visited_list[], Name info){
            bool result = false;
            for (int i = 0; i < vertex; i ++){
                if (visited_list[i].info == info){
                    result = visited_list[i].visit;
                    break;
                }
            }
            return result;
        }
        void set_visited_info(visited <Name>visited_list[], Name info, bool value){
            for (int i = 0; i < vertex; i ++){
                if (visited_list[i].info == info){
                    visited_list[i].visit = value;
                    break;
                }
            }
        }

        void Prims(Name start_point){
            visited <Name> visited_list[vertex];
            Vertex <Name>*temp = adj_list;
            Edge <Name>*edge;
            Name source;
            Name destination;
            mst_edge <Name>mst_list[vertex-1];
            int cnt = 0;
            while (temp){
                visited_list[cnt].info = temp->info;
                visited_list[cnt].visit = false;
                temp = temp->down;
                cnt ++;
            }
            int cost = 0;
            int temp_cost = 999999;
            set_visited_info(visited_list, start_point, true);
            cnt = 0;
            while (cnt < vertex-1){
                temp_cost = 999999;
                for (int i = 0; i < vertex; i ++){
                    if (get_visited_info(visited_list, visited_list[i].info)){
                        temp = get_vertex_from_name(visited_list[i].info);
                        edge = temp->next;
                        while (edge){
                            if (!get_visited_info(visited_list, edge->info) && edge->weight < temp_cost){
                                source = temp->info;
                                destination = edge->info;
                                temp_cost = edge->weight;
                            }
                            edge = edge->next;
                        }
                    }
                }
                
                set_visited_info(visited_list, destination, true);
                mst_list[cnt].v1 = source;
                mst_list[cnt].v2 = destination;
                mst_list[cnt].weight = temp_cost;
                cost += temp_cost;
                // cout << source << " ";
                // cout << destination << " ";
                // cout << temp_cost << " ";
                // cout << endl;
                cnt ++;
            }
            cout << "Prims Algorithm : " << endl;
            cout << "Consider Edge :" << endl;
            for (int i = 0; i < vertex-1; i++){
                cout << "\t< " << mst_list[i].v1 << " , " << mst_list[i].v2 << " > -- " << mst_list[i].weight;
                cout << endl;
            }
            cout << "Mst cost : " << cost;
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
    g.Prims(v1);
    return 0;
}
