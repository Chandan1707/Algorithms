#include <iostream>
using namespace std;
#define RED false
#define BLACK true

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
                cout << "( " << head->info << " , ";
                cout << (head->color == RED ? "RED" : "BLACK" ) << " ), ";
                InorderHelper (head->right);
            }
        }
        void PreordetHelper(Node *head) {
            if (head) {
                cout << "( " << head->info << " , ";
                cout << (head->color == RED ? "RED" : "BLACK" ) << " ), ";
                PreordetHelper (head->left);
                PreordetHelper (head->right);
            }
        }
    public:
        void inorder () {
            cout << "Inorder :";
            InorderHelper(root);
            cout << endl;
        }
        void preorder () {

            cout << "Preorder :";
            PreordetHelper(this->root);
            cout <<endl;
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
            // pointer to right child of grand parent
            Node *rs; 
            while (node->parent->color != BLACK){
                if (node->parent && node->parent->parent) {
                    if (node->parent->parent->left == node->parent) {
                        rs = node->parent->parent->right;

                        if (rs && rs->color == RED) {
                            node->parent->color = rs->color = BLACK;
                            if (node->parent->parent == this->root){
                                break;
                            }
                            node->parent->parent->color = RED;
                            node = node->parent->parent;
                        }
                        else {
                            if (node->parent->right == node) {
                                left_rotate(node->parent);
                                node = node->left;
                            }
                            else {
                                node->parent->color = BLACK;
                                node->parent->parent->color = RED;
                                right_rotate(node->parent->parent);
                            }
                        }
                    }
                    else {
                        rs = node->parent->parent->left;

                        if (rs && rs->color == RED) {
                            node->parent->color = rs->color = BLACK;
                            if (node->parent->parent == this->root){
                                break;
                            }
                            node->parent->parent->color = RED;
                            node = node->parent->parent;
                        }
                        else {
                            if (node->parent->left == node) {
                                right_rotate(node->parent);
                                node = node->right;
                            }
                            else {
                                node->parent->color = BLACK;
                                node->parent->parent->color = RED;
                                left_rotate(node->parent->parent);
                            }
                        }
                    }
                }
            }
        }
        
};

int main() {
    RedBlackTree t1;
    // t1.insertNode(41);
    // t1.insertNode(38);
    // t1.insertNode(31);
    // t1.insertNode(12);
    // t1.insertNode(19);
    // t1.insertNode(8);

    t1.insertNode(2);
    t1.insertNode(1);
    t1.insertNode(4);
    t1.insertNode(5);
    t1.insertNode(9);
    t1.insertNode(3);
    t1.insertNode(6);
    t1.insertNode(7);

    t1.preorder();
    t1.inorder();
}