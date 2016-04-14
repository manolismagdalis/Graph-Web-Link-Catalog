# Graph-Web-Link-Catalog


# author: Emmanouil Magdalis

# version: 1.0.0

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


