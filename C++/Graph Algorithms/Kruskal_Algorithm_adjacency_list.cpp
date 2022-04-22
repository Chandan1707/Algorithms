#include<iostream>
#include<string>
using namespace std;

template <class d_type>
class vertex_set{
    public:
        d_type info;
        d_type parent;
};

template <class d_type>
class edges{
    public:
        d_type source;
        d_type destination;
        int weight;
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
        int edge_count;
        Vertex <Name>*adj_list;
        edges <Name>*edges_list = new edges<Name>[20];

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
            edge_count = 0;
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
            edges_list[edge_count].source = fromVertex;
            edges_list[edge_count].destination = toVertex;
            edges_list[edge_count].weight = weight;
            edge_count ++;
            addEdge(fromVertex, toVertex, weight);
            addEdge(toVertex, fromVertex, weight);
        }
        void remove_edge(Name fromVertex, Name toVertex){
            edge_count --;
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

        
        void sort_by_weight(edges <Name>edge_list[], int n){
            edges <Name> temp;
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

    
        Name find_parent_set(vertex_set<Name>vertex_set_list[], Name x, int n){
            Name parent;
            for (int i = 0; i < n; i ++){
                if (vertex_set_list[i].info == x){
                    parent = vertex_set_list[i].parent;
                    break;
                }
            }
            return parent;
        }
        
        void set_union(vertex_set<Name>vertex_set_list[], Name x, Name y, int n){
            Name temp = find_parent_set(vertex_set_list, y, n);
            Name temp1 = find_parent_set(vertex_set_list, x, n);
            for (int i = 0; i < n; i ++){
                if (vertex_set_list[i].parent == temp){
                    vertex_set_list[i].parent = temp1;
                }
            }
        }

        void Kruskal(){
            vertex_set<Name>vertex_set_list[vertex];
            Vertex <Name>*temp = adj_list;
            Name x,y;
            int cnt=0;
            edges <Name>*mst_edges = new edges<Name>[vertex - 1];
            int cost = 0;
            while(temp){
                vertex_set_list[cnt].info = temp->info;
                vertex_set_list[cnt].parent = temp->info;
                temp = temp->down;
                cnt ++;
            }
            cnt = 0;
            sort_by_weight(edges_list, edge_count);
            for (int i = 0; i < edge_count; i++){
                x = find_parent_set(vertex_set_list,edges_list[i].source, vertex);
                y = find_parent_set(vertex_set_list,edges_list[i].destination, vertex);
                if (x != y){
                    mst_edges[cnt]= edges_list[i];
                    cost = cost + edges_list[i].weight;
                    cnt ++;
                    set_union(vertex_set_list, x, y, vertex);
                }
            }
            cout << "\nKruskal Algorithm : \n";
            cout << "Consider Edge :" << endl;
            for (int i = 0; i < vertex - 1; i ++){
                cout << "\t<" << edges_list[i].source << " , " << edges_list[i].destination << "> -- " << edges_list[i].weight << " ";
                cout << endl;
            }
            cout << endl << "Mst Cost : " << cost << endl;
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
    g.Kruskal();
    return 0;
}
