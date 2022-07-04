#include <iostream>
using namespace std;
#define RED false;
#define BLACK true;

class Node {
    public:
        int info;
        Node *left;
        Node *right;
        Node *parent;
        bool color;

    Node(int val) {
        this->info = val;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = RED;
    }
};

class RedBlackTree {
    private:
        Node *root = NULL;

    
        void InorderHelper (Node *head) {
            if (head) {
                InorderHelper (head->left);
                cout << head->info << " ";
                InorderHelper (head->right);
            }
        }
    public:
        void inorder () {
            InorderHelper(root);
        }
        void insertNode (int val) {
            Node *newNode = new Node(val);

            Node *nex = root;
            Node *pre = NULL;

            if (this->root == NULL) {
                this->root = newNode;
                newNode->color = BLACK;
            }
            else {
                while (nex){
                    pre = nex;
                    if (val < nex->info) {
                        nex = nex->left;
                    }
                    else if (val > nex->info) {
                        nex = nex->right;
                    }
                }
                if (pre != NULL && val < pre->info) {
                    pre->left = newNode;
                }
                else if (pre != NULL && val > pre->info) {
                    pre->right = newNode;
                }
                newNode->parent = pre;
                if (newNode->parent->parent == NULL) {
                    return;
                }
                insertFix (newNode);
            }
        }
        void left_rotate(Node *x) {
            Node *y = x->right;
            x->right = y->left;
            if (x->right != NULL) {
                x->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == NULL) {
                this->root = y;
            }
            else if(x->parent->left == x) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        void right_rotate (Node *x) {
            Node *y = x->left;
            x->left = y->right;
            if (x->left != NULL) {
                x->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == NULL) {
                this->root = y;
            }
            else if(x->parent->left == x) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }
            y->right = x;
            x->parent = y;
            
        }

        void insertFix (Node *node) {

        }
        
};

int main() {
    RedBlackTree t1;
    t1.insertNode(20);
    t1.insertNode(10);
    t1.insertNode(30);
    t1.insertNode(40);
    t1.insertNode(50);
    t1.insertNode(60);

    t1.inorder();
}