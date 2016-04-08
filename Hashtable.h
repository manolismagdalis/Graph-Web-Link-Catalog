#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "neighbours.h"

// Our hashtable. To find a node, it uses open addressing and double hashing
class Hashtable
{
    private:
        neighbours * links;
    public:
        Hashtable()
        {
            links = new neighbours [100003]; // The closest prime number to 100.000 which
        }                                    // is the MaxNumberOfEdges multiplied by 2 (because
        void insertion (int, int, int, int); // we want the load factor to be close to 0.5)
        void deletion (int, int);
        void print();
        neighbours * findone (int, int);
        bool ispart(int *, int);
        int minimum (int *, int);
        int * PRIM ();  //The PRIM algorithm to find the minimum spanning tree
        int NCN (int);  //The NCN algorithm to find the number of the neighbour nodes up to distance of 2 from a given node
};

#endif // HASHTABLE_H
