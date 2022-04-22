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

int main(){
    Stack <int>q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    while(!q.isEmpty())
        cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.pop() << endl;
    // cout << q.isEmpty() << endl;
}