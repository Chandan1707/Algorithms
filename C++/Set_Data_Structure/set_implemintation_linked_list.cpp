#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node;

class NODE{
    public:
        node *head;
        node *tail;
};

class node{
    public:
        NODE *prev;
        int info;
        node *next;
};

class disjoint_set {
    private:
        vector <NODE*>set_items;
    public:
        void make_set(int val) {
            NODE *temp = new NODE;
            node *item = new node;

            item->info = val;
            item->next = NULL;
            item->prev = temp;

            temp->head = item;
            temp->tail = item;

            set_items.push_back(temp);
        }
        NODE* find_set(int val){
            node *temp = NULL;
            for (int i = 0; i <= set_items.size(); i++){
                temp = set_items[i]->head;
                while (temp) {
                    if (temp->info == val){
                        return temp->prev;
                    }
                    temp = temp->next;
                }
            }
            return temp->prev;
        }
        void set_union(NODE *n1, NODE *n2){
            if (n1 != n2){
                node *temp = n2->head;
                (n1->tail)->next = temp;
                while (temp != NULL){
                    temp->prev = n1;
                    temp = temp->next;
                }
                n1->tail = n2->tail;
                int i;
                for (i = 0; i < set_items.size(); i ++){
                    if (set_items[i] == n2){
                        break;
                    }
                }
                if (i < set_items.size()){
                    set_items.erase(set_items.begin() + i);
                }
            }
        }
        void display_set(NODE *item){
            node *temp = item->head;
            while (temp) {
                cout << temp->info << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        void dispaly(){
            for (int i = 0; i < set_items.size(); i++){
                cout << set_items[i] << endl;
            }
            cout << endl;
        }

};

int main(){
    disjoint_set s1;
    s1.make_set(10);
    s1.make_set(20);
    s1.make_set(30);
    s1.make_set(40);
    s1.make_set(50);
    s1.make_set(60);
    s1.make_set(70);
    s1.make_set(80);

    // NODE *n1 = s1.find_set(10);
    // NODE *n2 = s1.find_set(20);
    // NODE *n3 = s1.find_set(30);
    // NODE *n4 = s1.find_set(40);
    // NODE *n5 = s1.find_set(50);
    // NODE *n6 = s1.find_set(60);
    // NODE *n7 = s1.find_set(70);
    // NODE *n8 = s1.find_set(80);


    s1.set_union(s1.find_set(10), s1.find_set(20));
    s1.set_union(s1.find_set(20), s1.find_set(30));
    s1.set_union(s1.find_set(30), s1.find_set(80));
    s1.set_union(s1.find_set(40), s1.find_set(50));
    s1.set_union(s1.find_set(20), s1.find_set(30));
    s1.set_union(s1.find_set(60), s1.find_set(70));

    s1.set_union(s1.find_set(10), s1.find_set(40));
    s1.set_union(s1.find_set(40), s1.find_set(60));

    // cout << n1 << endl;
    // cout << n2 << endl;
    // cout << n3 << endl;
    // cout << n4 << endl;
    // cout << n5 << endl;
    // cout << n6 << endl;
    // cout << n7 << endl;
    // cout << n8 << endl;
    cout << endl;


    s1.dispaly();

    s1.display_set(s1.find_set(10));
    s1.display_set(s1.find_set(40));


    return 0;
}
