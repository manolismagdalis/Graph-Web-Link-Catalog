/**
    @author: Emmanouil Magdalis

    @version: 1.0.0

    The following program organizes web page links in a graph. The vertices of the graph are stored
    in a hashtable instead of a sorted array. Thus, in order to find the neighbours of an edge,
    the program is using open addressing and double hashing. We assume that there will be no more
    than 50.000 edges.

    The neighbours of each edge are stored in a linked list (in increasing order by the ID).
    For good time complexity regarding the search of the hashtable, our load factor must be 0,5.
    So, the size of the hashtable is 2*N (N is the max number of edges of the graph).
    Every command is read from an Example.txt file. READ_DATA signals the beginning of the commands
    reading. INSERT_LINK inserts a page link (First page, Second page, Weight of their connection).
    DELETE_LINK deletes a link between two pages. PRIM ALG executes a PRIM algorithm to find the minimum
    spanning tree. NCN finds the number of neighbours of a node, two edges away. PRINT GRAPH, prints the
    graph on the command prompt.
    An example of the commands txt is given:

    READ_DATA
    INSERT_LINK 9 5 3
    INSERT_LINK 9 7 9
    INSERT_LINK 8 7 8
    DELETE_LINK 4 5
    INSERT_LINK 6 3 7
    INSERT_LINK 6 2 2
    INSERT_LINK 6 5 4
    PRINT GRAPH
    PRIM ALG
    NCN 2
    INSERT_LINK 4 5 7
    INSERT_LINK 9 7 9
    INSERT_LINK 4 1 6
    INSERT_LINK 7 4 12
    INSERT_LINK 2 3 12
    INSERT_LINK 3 2 12
    INSERT_LINK 2 1 4
    DELETE_LINK 4 5
    PRINT GRAPH
    PRIM ALG
    NCN 2
    END

    READ_DATA exists only once in the beginning of the txt and the END once in the
    end. If during INSERT_LINK the link already exists, then nothing is inserted. Also,
    if the link that is commanded to be deleted using DELETE_LINK does not exist, then
    nothing happens and the program continues.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Hashtable.h"


int main()
{
    Hashtable MyGraph;
    std::string command;
    std::string data1;
    std::string data2;
    std::string data3;
    int ddata1;
    int ddata2;
    int ddata3;
    std::ifstream myfile;
    myfile.open ("example.txt");
    if (myfile.is_open())
    {
        while (command!="READ_DATA")  //This while loop is used to make sure the program does not read junk
        {                             //before actually reaching the first command of the code
            myfile >> command;
        }
        while ( myfile >> command >> data1 )
        {
            if (command=="INSERT_LINK")
            {
                myfile >> data2 >> data3;
                ddata1=atoi(data1.c_str()); //convert string data1 to int ddata1
                ddata2=atoi(data2.c_str()); //convert string data2 to int ddata2
                ddata3=atoi(data3.c_str()); //convert string data3 to int ddata3
                MyGraph.insertion(ddata1, ddata2, ddata3, 0);
                MyGraph.insertion(ddata2, ddata1, ddata3, 0);
            }
            else if (command=="DELETE_LINK")
            {
                myfile >> data2;
                ddata1=atoi(data1.c_str()); //convert string data1 to int ddata1
                ddata2=atoi(data2.c_str()); //convert string data2 to int ddata2
                MyGraph.deletion(ddata1, ddata2);
            }
            else if (command=="PRIM")
            {
                MyGraph.PRIM();
            }
            else if (command=="NCN")
            {
                ddata1=atoi(data1.c_str()); //convert string data1 to int ddata1
                int y=MyGraph.NCN(ddata1);
                std::cout << "The number of common neighbours of the node " << ddata1 << " at distance of 2 edges is: " << y << std::endl;
            }
            else if (command=="PRINT")
            {
                std::cout << "\nThe catalogue is the following: \n" << std::endl;
                MyGraph.print();
            }
            else if (command=="END") break;
            else
            {
                std::cout << "Unable to read the txt file!" << std::endl;
                return 0;
            }
        }
        myfile.close();
    }
    else std::cout << "Unable to open file!";


    std::cout << std::endl;
    system("pause");
    return 0;
}
