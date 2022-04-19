#include<iostream>
#include<string>
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
class Queue{
    private:
        Node <d_type>*front;
        Node <d_type>*rear;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        void enqueue(d_type info){
            Node <d_type>*temp = new Node<d_type>(info);
            if (front == NULL && rear == NULL){
                front = rear = temp;
            }
            else{
                rear->next = temp;
                rear = rear->next;
            }
        }
        d_type dequeue(){
            Node <d_type>*temp;
            if (front == NULL)
                exit(0);
            if(front == rear){
                temp = front;
                front = rear = NULL;
            }
            else{
                temp = front;
                front = front->next;
            }
            d_type temp_info = temp->info;
            delete temp;
            return temp_info;
        }
        bool isEmpty(){
            bool result = false;
            if (front == NULL && rear == NULL){
                result = true;
            }
            return result;
        }
};


template <class d_type>
class visited{
    public:
        d_type info;
        bool visit;

        void set_visited(d_type info, bool visit){
            this->info = info;
            this->visit = visit;
        }
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
        Vertex<Name>* search_value(Name info){
            Vertex <Name>*temp = adj_list;
            Vertex <Name>*ptr = NULL;
            while (temp){
                if (temp->info == info){
                    ptr = temp;
                    break;
                }
                temp = temp->down;
            }
            return ptr;
        }
        void set_visit_val(visited <Name>vs[], Name info, bool val){
            for (int i = 0; i < vertex; i++){
                if (vs[i].info == info)
                    vs[i].visit = val;
            }
        }
        bool get_visit_val(visited <Name>vs[], Name info){
            bool result = false;
            for (int i = 0; i < vertex; i++){
                if (vs[i].info == info)
                    result = vs[i].visit;
            }
            return result;
        }
        void DFS(Name start){
            Queue <Name> q;
            int i = 0;
            Vertex <Name>*temp = adj_list;
            Name temp1;
            Edge <Name>*edge = NULL;
            cout << "BFS traversal : \n\t";
            q.enqueue(start);
            visited <Name> *vs = new visited<Name>[vertex];
            while (temp){
                vs[i].visit = false;
                vs[i].info = temp->info;
                i ++;
                temp = temp->down;
            }
            set_visit_val(vs, start, true);
            
            while (!q.isEmpty()){
                temp1 = q.dequeue();
                cout << temp1 << ", ";
                temp = search_value(temp1);
                edge = temp->next;
                while (edge){
                    if (get_visit_val(vs, edge->info) == false){
                        q.enqueue(edge->info);
                        set_visit_val(vs, edge->info, true);
                    }
                    edge = edge->next;
                }
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
    g.DFS(v1);
}