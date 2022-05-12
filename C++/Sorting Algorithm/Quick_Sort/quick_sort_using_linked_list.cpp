#include <iostream>
using namespace std;
template <class d_type>
class Node{
    public:
        d_type info;
        Node<d_type>*next;

        Node(d_type info){
            this->info = info;
            next = NULL;
        }
};
template <class node_data>
class Linked_List{
    private:
        Node <node_data>*head;
        Node <node_data>*tail;
    public:
        Linked_List(){
            head = tail = NULL;
        }
        void add_node(node_data info){
            Node <node_data>*temp = new Node<node_data>(info);
            if (head == NULL && tail == NULL)
                head = tail = temp;
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }

        void remove_node(node_data info){
            Node <node_data>*temp = head;
            Node <node_data>*prev = NULL;

            while (temp && temp->info != info){
                prev = temp;
                temp = temp->next;
            }
            if (temp->info == info){
                prev->next = temp->next;
                free(temp);
            }
        }
        void print(){
            Node <node_data>*temp = head;
            while (temp){
                cout << temp->info << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        Node<node_data>* partition(Node <node_data>*head, Node <node_data>*tail, Node <node_data>**new_head, Node <node_data>**new_tail){
            Node <node_data>*pivot = tail;
            Node <node_data>*temp = head;
            Node <node_data>*prev = NULL;
            while (temp && temp != pivot){
                if (temp->info > pivot->info){
                    if (temp == head)
                        head = temp->next;
                    else
                        prev->next = temp->next;

                    temp->next = tail->next;
                    tail->next = temp;
                    tail = tail->next;

                    if (prev == NULL)
                        temp = head;
                    else
                        temp = prev->next;
                }
                else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            (*new_head) = head;
            (*new_tail) = tail;
            return pivot;
        }
        Node<node_data>* quick_sort(Node <node_data>*head, Node <node_data>*tail){
            if (!head || head == tail)
                return head;
            Node <int>*new_head = NULL;
            Node <int>*new_tail = NULL;
            Node <int>*pivot = partition(head, tail, &new_head, &new_tail);
            if (pivot != new_head){
                Node <int>*temp = new_head;
                while (temp->next != pivot){
                    temp = temp->next;
                }
                temp->next = NULL;
                new_head = quick_sort(new_head, temp);
                temp = new_head;
                while (temp->next)
                    temp = temp->next;
                temp->next = pivot;
            }
            pivot->next = quick_sort(pivot->next, new_tail);
            // cout << pivot->info << endl;
            return new_head;

        }
        void Quick_Sort(){
            head = quick_sort(head, tail);
        }
};

int main(){
    
    Linked_List <int>linked_list;
    linked_list.add_node(60);
    linked_list.add_node(20);
    linked_list.add_node(40);
    linked_list.add_node(30);
    linked_list.add_node(90);
    
    linked_list.add_node(70);
    linked_list.add_node(50);
    linked_list.print();
    linked_list.Quick_Sort();
    linked_list.print();
    return 0;
}