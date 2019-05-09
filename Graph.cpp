#include <iomanip>
#include <iostream>
#include <string>
#include "Graph.h"

Graph::Graph()
{
    matrix[0][0] = ZERO;
    matrix[0][1] = ONETWENTY;
    matrix[0][2] = ONEFITTY;
    matrix[0][3] = INFINITY;
    matrix[0][4] = INFINITY;
    matrix[0][5] = FIVEHUNDO;

    matrix[1][0] = ONETWENTY;
    matrix[1][1] = ZERO;
    matrix[1][2] = INFINITY;
    matrix[1][3] = SEVENFIVE;
    matrix[1][4] = INFINITY;
    matrix[1][5] = THREEFITTY;

    matrix[2][0] = ONEFITTY;
    matrix[2][1] = INFINITY;
    matrix[2][2] = ZERO;
    matrix[2][3] = INFINITY;
    matrix[2][4] = TWOFITTY;
    matrix[2][5] = INFINITY;

    matrix[3][0] = INFINITY;
    matrix[3][1] = SEVENFIVE;
    matrix[3][2] = INFINITY;
    matrix[3][3] = ZERO;
    matrix[3][4] = ONEFITTY;
    matrix[3][5] = INFINITY;

    matrix[4][0] = INFINITY;
    matrix[4][1] = INFINITY;
    matrix[4][2] = TWOFITTY;
    matrix[4][3] = ONEFITTY;
    matrix[4][4] = ZERO;
    matrix[4][5] = INFINITY;

    matrix[5][0] = FIVEHUNDO;
    matrix[5][1] = THREEFITTY;
    matrix[5][2] = INFINITY;
    matrix[5][3] = INFINITY;
    matrix[5][4] = INFINITY;
    matrix[5][5] = ZERO;
} // end constructor

void Graph::printGraph() const
{
    printHeader();
    for (int row = 0; row < 6; row++)
    {
        std::string airport;
        if (row == 0)
            airport = "SFO\t";
        else if (row == 1)
            airport = "LAX\t";
        else if (row == 2)
            airport = "LAS\t";
        else if (row == 3)
            airport = "PHX\t";
        else if (row == 4)
            airport = "DEN\t";
        else
            airport = "JFK\t";
        std::cout << std::setw(5) << airport;
        for (int column = 0; column < 6; column++)
            std::cout << std::left << std::setw(10) << matrix[row][column] << '\t';
        std::cout << std::endl;
    } // end for
} // end printGraph

void Graph::printHeader() const
{
    std::cout << std::left << std::setw(3)  << " \t";
    std::cout << std::left << std::setw(12) << "SFO\t";
    std::cout << std::left << std::setw(12) << "LAX\t";
    std::cout << std::left << std::setw(12) << "LAS\t";
    std::cout << std::left << std::setw(12) << "PHX\t";
    std::cout << std::left << std::setw(12) << "DEN\t";
    std::cout << std::left << std::setw(12) << "JFK" << std::endl;
} // end printHeader

void Graph::printWeight() const
{
    std::cout <<std::left << std::setw(2) << " \t";
    for (int v = 0; v < 6; v++)
    {
        if (weight[v] == 0 || weight[v] == 1000000)
            std::cout << std::left << std::setw(10) << " " << '\t';
        else
            std::cout << '$' << std::left << std::setw(10) << weight[v] << '\t';
    } // end for
    std::cout << std::endl;
} // end printWeight

void Graph::cheapestPath()
{
    int minIndex = 0;
    // add origin to vertexSet
    vertexSet.add(minIndex);

    // test to see list
    //vertexSet.printList();

    // add weights of origin to vertices
    for (int v = 0; v < 6; v++)
    {
        weight[v] = matrix[0][v];
    } // end for

    // print column header for airports
    //printHeader();

    // make it look fancy...make 0 and 1000000 print [space]
    //printWeight();

    while (!vertexSet.isFull())
    {
        // set variable for minimum
        int minValue = 1000000;
        // search weight for lowest vertex not in vertexSet
        int v;
        for (v = 0; v < 6; v++)
        {
            if (!vertexSet.searchEntry(v))
            {
                if (weight[v] < minValue)
                {
                    minValue = weight[v];
                    minIndex = v;
                } // end if
            } // end if
        } // end for

        // add weight of lowest vertex not in vertexSet to vertexSet
        vertexSet.add(minIndex);
        //vertexSet.printList();
        for (int u = 0; u < 6; u++)
        {
            if (!vertexSet.searchEntry(u))
            {
                if (weight[u] > weight[minIndex] + matrix[minIndex][u])
                    weight[u] = weight[minIndex] + matrix[minIndex][u];
            } // end if
        } // end for

        //printHeader();
        //printWeight();
    } // end while


} // end cheapestPath
