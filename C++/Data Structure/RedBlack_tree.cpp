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
        Node *TNULL;

    
        void InorderHelper (Node *head) {
            if (head != TNULL) {
                InorderHelper (head->left);
                cout << "( " << head->info << " , ";
                cout << (head->color == RED ? "RED" : "BLACK" ) << " ), ";
                InorderHelper (head->right);
            }
        }
        void PreordetHelper(Node *head) {
            if (head != TNULL) {
                cout << "( " << head->info << " , ";
                cout << (head->color == RED ? "RED" : "BLACK" ) << " ), ";
                PreordetHelper (head->left);
                PreordetHelper (head->right);
            }
        }

        Node* immediate_successor(Node *node) {
            while (node->left != TNULL) {
                node = node->left;
            }
            return node;
        }
        Node* immediate_predecessor (Node *node) {
            while (node->right != TNULL) {
                node = node->right;
            }
            return node;
        }

        void printHelper (Node *node, string indent, bool last) {
            if (node != TNULL) {
                
                if (node == root) {
                    cout << "ROOT---";
                    // cout << indent;
                }
                else if (last) {
                    cout << indent;
                    cout << "L---";
                    indent += "    ";
                }
                else {
                    cout << indent;
                    cout << "R---";
                    indent += "    ";
                }
                
                cout << node->info << "(" << (node->color == RED ? " RED " : "BLACK") << ")" << endl;
                printHelper (node->left, indent, true);
                printHelper (node->right, indent, false);
            }
            
        }

        bool searchHelper (Node *node, int key) {
            while (node != TNULL){
                if (node->info == key) {
                    return true;
                }
                if (key < node->info) {
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }
            return false;
        }

        // transplant whole node (not vlaue) and parent pointer are resized 
        void rbNodeTransplant(Node *a, Node *b) {
            if (a->parent == NULL) {
                this->root = b;
            }
            else if (a->parent->left == a) {
                a->parent->left = b;
            }
            else {
                a->parent->right = b;
            }
            b->parent = a->parent;
        }
        // delete key node if found and transplant whole node with his decendent leaf node
        void deleteNodeHalper(Node *node, int val) {
            Node *target = TNULL;
            Node *child,*helper;
            while (node != TNULL) {
                if (node->info == val) {
                    target = node;
                    break;
                }
                if (val < node->info) {
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }

            if (target == TNULL) {
                cout << "Key is not prasent " << endl;
                return;
            }

            child = target;
            int deleted_node_original_color = child->color;
            if (target->left == TNULL) {
                helper = target->right;
                rbNodeTransplant (target , target->right);
            }
            else if (target->right == TNULL) {
                helper = target->left;
                rbNodeTransplant (target, target->left);
            }
            else {
                child = immediate_successor (target->right);
                deleted_node_original_color = child->color;
                helper = child->right;
                if (target == child->parent) {
                    child->right->parent = child;
                }
                else {
                    rbNodeTransplant(child, child->right);
                    child->right = target->right;
                    target->right->parent = child;
                }
                rbNodeTransplant (target, child);
                child->left = target->left;
                child->left->parent = child;
                child->color = target->color;
            }
            if (deleted_node_original_color == BLACK) {
                deleteFix (helper);
            }
        }
        void deleteFix (Node *x) {
            Node *s;
            while (x != root && x->color == BLACK) {
                if (x == x->parent->left) {
                    s = x->parent->right;
                    if (s->color == RED) {
                        s->color = BLACK;
                        x->parent->color = RED;
                        left_rotate (x->parent);
                        s = x->parent->right;
                    }

                    if (s->left->color == BLACK && s->right->color == BLACK) {
                        s->color = RED;
                        x = x->parent;
                    }
                    else {
                        if (s->right->color == BLACK) {
                            s->color = RED;
                            s->left->color = BLACK;
                            right_rotate (s);
                            s = x->parent->right;
                        }
                        
                        s->color = s->parent->color;
                        s->parent->color = BLACK;
                        s->right->color = BLACK;
                        left_rotate (x->parent);
                        x = root;
                    }
                }
                else {
                    s = x->parent->left;
                    if (s->color == RED) {
                        s->color = BLACK;
                        s->parent->color = RED;
                        right_rotate (x->parent);
                        s = x->parent->left;
                    }

                    if (s->left->color == BLACK && s->right->color == BLACK) {
                        x = x->parent;
                        s->color = RED;
                        s = x->parent->left;
                    }
                    else {
                        if (s->left->color == BLACK) {
                            s->right->color = BLACK;
                            s->color = RED;
                            left_rotate(s);
                            s = x->parent->left;
                        }

                        s->color = x->parent->color;
                        x->parent->color = BLACK;
                        s->left->color = BLACK;
                        right_rotate (x->parent);
                        x = root;
                    }
                }
            }
            x->color = BLACK;
        }
        void left_rotate(Node *x) {
            Node *y = x->right;
            x->right = y->left;
            if (x->right != TNULL) {
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
            if (x->left != TNULL) {
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

        //this function recolor and rotate nodes to maintain red-black tree proparty
        void insertFix (Node *node) {

            // pointer to other child of grand parent
            Node *rs; 
            while (node->parent->color != BLACK){
                if (node->parent && node->parent->parent) {
                    if (node->parent->parent->left == node->parent) {
                        rs = node->parent->parent->right;

                        // if right child not exist or color red
                        if (rs && rs->color == RED) {
                            node->parent->color = rs->color = BLACK;
                            //grand parent is root node
                            if (node->parent->parent == this->root){
                                break;
                            }

                            // recolor nodes
                            node->parent->parent->color = RED;
                            node = node->parent->parent;
                        }
                        else {
                            // node is right child of parent
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
                        // insert left grand child
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
                            // node is left child of parent
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
    public:
        RedBlackTree() {
            TNULL = new Node(0);
            TNULL->color = BLACK;
            TNULL->left = NULL;
            TNULL->right = NULL;
        }
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
        void search(int key) {
            if (searchHelper(root, key)){
                cout << key << " -- Found ";
            }
            else {
                cout << key << " -- Not Found ";
            }
            cout << endl;
        }

        void print () {
            printHelper (root, "      ", true);
        }
        void insertNode (int val) {
            Node *newNode = new Node(val);
            newNode->left = TNULL;
            newNode->right = TNULL;

            Node *nex = root;
            Node *pre = NULL;

            if (this->root == NULL) {
                this->root = newNode;
                newNode->color = BLACK;
            }
            else {
                while (nex != TNULL){
                    pre = nex;
                    if (val < nex->info) {
                        nex = nex->left;
                    }
                    else if (val > nex->info) {
                        nex = nex->right;
                    }
                }
                if (pre != TNULL && val < pre->info) {
                    pre->left = newNode;
                }
                else if (pre != TNULL && val > pre->info) {
                    pre->right = newNode;
                }
                newNode->parent = pre;
                if (newNode->parent->parent == NULL) {
                    return;
                }
                insertFix (newNode);
            }
        }
        
        void deleteNode (int val) {
            deleteNodeHalper (root, val);
        }
        
};

int main() {
    cout << endl << "T1 Tree " << endl;

    RedBlackTree t1;
    
    t1.insertNode(2);
    t1.insertNode(1);
    t1.insertNode(4);
    t1.insertNode(5);
    t1.insertNode(9);
    t1.insertNode(3);
    t1.insertNode(6);
    t1.insertNode(7);

    t1.print();

    t1.deleteNode(1);

    cout << endl;
    cout << "After deletion 1 :" << endl;
    t1.print();

    cout << endl << "T2 Tree " << endl;
    RedBlackTree t2;
    t2.insertNode(41);
    t2.insertNode(38);
    t2.insertNode(31);
    t2.insertNode(12);
    t2.insertNode(19);
    t2.insertNode(8);

    cout << "Search for 19 :" << endl;
    t2.search(19);
    cout << endl;
    t2.print();

    t1.deleteNode(12);
    cout << endl;
    cout << "After deletion 12 :" << endl;
    t1.print();
}