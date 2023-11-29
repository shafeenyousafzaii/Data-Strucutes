#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    int value;
    Node *curr;
    Node *prev;
    Node(int value = 0 , Node *curr=NULL , Node *prev=NULL)
    {
        this->value=value;
        this->curr=curr;
        this->prev=prev;
    };
    ~Node();
};


