#include "Hashtable.h"

const int MaxNumberOfEdges = 50000;

neighbours * Hashtable::findone(int x, int l)
{
    int z=l;
    neighbours * temp;
    int p=((x^2)%100003+z*(30011-(x^2)%30011))%100003;  // 30011 is the parameter of the second hash function
    if (links[p].head==NULL)
    {
        return NULL;
    }
    else
    {
        if ((links[p].head->ID)==x)
        {
            return &links[p];
        }
        else
        {
            z+=1;
            temp=findone(x, z);
            return temp;
        }
    }
}

void Hashtable::insertion(int x, int y, int w, int l)
{
    int z=l;
    int p=((x^2)%100003+z*(30011-(x^2)%30011))%100003;
    if (links[p].head==NULL)
    {
        links[p].add(x, 0);
        links[p].add(y, w);
        return;
    }
    else if (links[p].head->ID==x)
    {
        links[p].add(y,w);
        return;
    }
    else
    {
        z+=1;
        insertion(x, y, w, z);
        return;
    }
}

//We need to delete the connection from both two sides.
void Hashtable::deletion (int x, int y)
{
    neighbours * temp = findone(x, 0);
    if (temp==NULL)
    {
        return;
    }
    else
    {
        temp->removal(y);
    }

    temp = findone(y,0);
    temp->removal(x);
}

void Hashtable::print()
{
    for (int j=0; j<MaxNumberOfEdges; j++)
    {
        if (links[j].head!=NULL)
        {
            links[j].print();
        }
    }
    return;
}

bool Hashtable::ispart(int * x, int y)
{
    for (int i=0; i<8; i++)
    {
        if (x[i]==y)
        {
            return 1;
        }
    }
    return 0;
}

int Hashtable::minimum(int * x, int sum)
{
    int i=0;
    int s=-1;
    int m=10000;
    while (i<sum)
    {
        if (x[i]<m && x[i]>-1)
        {
            s=i;
            m=x[i];
        }
        i++;
    }
    return s;
}

int * Hashtable::PRIM ()
{
    int * A = new int [MaxNumberOfEdges];  //Because the maximum number of edges is 50.000
    int * Q = new int [MaxNumberOfEdges];
    int * key =  new int [MaxNumberOfEdges];
    int * parent = new int [MaxNumberOfEdges];
    int j=0;
    int sum;
    //We fill the array Q
    for (int i=0; i<MaxNumberOfEdges; i++)
    {
        if (links[i].head!=NULL)
        {
            Q[j]=(links[i].head)->ID;
            j++;
            sum=j;//
        }
    }

    for (int i=0; i<MaxNumberOfEdges; i++)
    {
        A[i]=0;
    }


    for (int i=0; i<sum; i++)
    {
        key[i]=1000000;
        parent[i]=0;
    }

    key[0]=0;

    int sumofa=0; // A counter of the array A

    int h=0;
    while (1)
    {
        h++;
        j=minimum(key, sum);
        if (j==-1) break;
        int teemp=Q[j];
        Q[j]=-1;
        key[j]=-1;
        if (parent[j]!=0)
        {
            A[sumofa]=parent[j];
            sumofa++;
            A[sumofa]=teemp;
            sumofa++;
        }

    //Now, we update all the neighbour nodes
        neighbours * temp = findone(teemp, 0);


        node * blah=(temp->head)->next;  //Because head is of no interest to us right now

        while (blah!=NULL)
        {
            int g=-1;
            for (int i=0; i<sum; i++)
            {
                if (Q[i]==(blah->ID))
                {
                    g=i;
                }
            }

            if (blah->weight < key[g])
            {
                key[g]=blah->weight;
                parent[g]=teemp;
            }
            blah=blah->next;
        }

    }


    std::cout << "\nThe MST consists of the following edges: " << std::endl;
    int i=0;
    while (A[i]!=0)
    {
        std::cout << A[i] << " <---> " ;
        i++;
        std::cout << A[i] << std::endl;
        i++;
    }
    std::cout << std::endl;
    return A;
}


int Hashtable::NCN (int x)
{
    int * s = new int[MaxNumberOfEdges];
    int i=0;
    neighbours * temp = findone (x, 0);
    node * first = temp->head;
    node * blah = first;
    blah = blah->next;
    while (blah!=NULL)
    {
        neighbours * temp1 = findone (blah->ID, 0);
        node * blah1 = temp1->head;
        blah1=blah1->next;
        while (blah1!=NULL)
        {
            if (blah1->ID!=first->ID)
            {
                s[i]=blah1->ID;
                i++;
            }
            blah1=blah1->next;
        }
        blah=blah->next;
    }
    for (int j=0; j<i; j++)
    {
        for(int p=0; p<j; p++)
        {
            if (s[p]==s[j])
            {
                s[j]=0;
                i--;
            }
        }
    }
    return i;
}
