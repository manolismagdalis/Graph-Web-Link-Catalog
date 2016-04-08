#include "neighbours.h"


void neighbours::add(int a, int b)
{
    node * temp = new node;
    temp->ID = a;
    temp->weight = b;
    temp->next = NULL;
    //temp->visited = 0;
    if (head==NULL)
    {
        head=temp;
        head->weight=0;
        return;
    }
    else
    {
        node * temp1 = head->next;
        if (head->next==NULL)
        {
            head->next=temp;
            return;
        }
        node * temp2 = head;
        while ((temp1->next!=NULL) && (temp->ID > temp1->ID))
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if (temp->ID < temp1->ID)
        {
            temp2->next=temp;
            temp->next=temp1;
            return;
        }
        else if (temp->ID == temp1->ID) return;
        else
        {
            temp1->next=temp;
            return;
        }
    }
    return;
}


void neighbours::print()
{
    node * temp = head->next;
    std::cout << head->ID << "   -->   " ;
    while (temp->next!=NULL)
    {
        std::cout << temp->ID << " (weight: " ;
        std::cout << temp->weight << ")   -->   " ;
        temp=temp->next;
    }
    std::cout << temp->ID << " (weight: " << temp->weight << ")" << std::endl;
    return;
}


void neighbours::removal(int x)
{
    node * temp = head;
    node * temp1;
    if (head->ID==x)
    {
        head=head->next;
        return;
    }
    while (temp!=NULL)
    {
        if (temp->ID==x) break;
        temp1=temp;
        temp=temp->next;
    }
    if (temp==NULL)
    {
        std::cout << "No such element in the list" << std::endl;
        return;
    }
    else
    {
       temp1->next=temp->next;
       delete temp;
       return;
    }
}
