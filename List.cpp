#include <iostream>
#include <stdexcept>
#include <string>
#include "List.h"

void List::add(const int& item)
{
    bool canAdd;
    /*if (numItems == maxItems)
    {
        throw invalid_argument("ERROR: insert() using invalid position.\n");
    } // end if*/

    canAdd = (numItems < maxItems);
    if (canAdd)
    {
        list[numItems - 1] = item;
        numItems++;
    } // end if
} // end add

bool List::searchEntry(int target) const
{
    bool found = false;
    for (int i = 0; i < numItems; i++ )
    {
        if (list[i] == target)
            found = true;
    } // end for
    return found;
} // end searchEntry

void List::printList() const
{
    std::cout << "List: ";
    for (int i = 0; i < numItems; i++)
        std::cout << list[i] << ' ';
    std::cout << std::endl;
}
