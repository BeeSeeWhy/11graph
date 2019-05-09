#ifndef _GRAPH
#define _GRAPH
#include <iostream>
#include "List.h"
class Graph
{
private:
      static const int ZERO = 0;
      static const int SIX = 6;
      static const int SEVENFIVE = 75;
      static const int ONETWENTY = 120;
      static const int ONEFITTY = 150;
      static const int TWOFITTY = 250;
      static const int THREEFITTY = 350;
      static const int FIVEHUNDO = 500;
      static const int INFINITY = 1000000;

      int matrix[SIX][SIX];
      int weight[SIX];
      List vertexSet;
public:
      Graph();

      void printGraph() const;
      void printHeader() const;
      void printWeight() const;
      void cheapestPath();
}; // end Graph
#endif
