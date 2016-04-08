#ifndef NEIGHBOURS_H
#define NEIGHBOURS_H

#include "node.h"
#include <iostream>

class neighbours
{
    public:
        node * head;
        neighbours()
        {
            head=NULL;
        }
        void add(int, int);
        void print();
        void removal(int);
};

#endif // NEIGHBOURS_H
