#include <iostream>
using namespace std;

template <class d_type>
class node{
    public:
        node <d_type>*prev;
        d_type info;
        node <d_type>*next;
};

