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
            // if (front == NULL)
            //     return NULL;
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

int main(){
    Queue <int>q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    while(!q.isEmpty())
        cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.isEmpty();
}