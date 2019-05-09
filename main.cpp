#include <iostream>
#include "Graph.h"
using namespace std;

void printAirplane()
{
  cout << "          |" << endl;
  cout << "\\________( )________/" << endl;
  cout << "       o\'   \'o" << endl;
} // end printAirplane

int main()
{
    Graph CSA;
    cout << endl << endl;
    cout << "Welcome to CS Airlines!\n";
    printAirplane();
    cout << endl << endl;
    cout << "CS Airlines Adjacency Matrix: \n";
    CSA.printGraph();

    cout << endl << endl;
    CSA.cheapestPath();

    cout << "Here at CS Airlines, we put you first!\n";
    printAirplane();
    cout << endl << endl;

    cout << "From SFO, here are the best rates for all our destinations: \n";
    cout << endl;
    CSA.printHeader();
    CSA.printWeight();
    return 0;
}
