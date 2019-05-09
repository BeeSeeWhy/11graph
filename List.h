#ifndef _LIST
#define _LIST
#include <iostream>
#include <stdexcept>

class List
{
  private:
      static const int MAX_SIZE = 6;
      int* list;
      int numItems;
      int maxItems;
  public:
      List() { numItems = 0; maxItems = MAX_SIZE;
                list = new int[MAX_SIZE]; }
      virtual ~List() { delete [] list; }

      bool isEmpty() const { return numItems == 0; }
      bool isFull() const { return numItems == maxItems; }
      int getLength() const { return numItems; }
      void add(const int& item);
      //bool remove(int pos);

      void clear() { numItems = 0; }
      bool searchEntry(int target) const;
      int getEntry() { return list[numItems - 1]; }
      void printList() const;
}; // end List
#endif
