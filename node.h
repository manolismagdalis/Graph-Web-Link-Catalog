#ifndef NODE_H
#define NODE_H


struct node
{
    int ID;
    int weight;
    bool visited;
    node * next;
};

#endif // NODE_H
