#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   private:
        std::list<T> linkList;
    public:
        T remove_min();
        T min();
        bool is_empty();
        void insert(const T& data);
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
};

template <typename T>
   bool SortedMPQ<T>::is_empty()
   {
      if(linkList.size() == 0)
      {
         return true;
      }
   return false;
   }

template <typename T>
   T SortedMPQ<T>::min()
   {
      if(is_empty())
      {
         throw "MPQ is empty!!";
      }
   return linkList.front();
   }

template <typename T>
   T SortedMPQ<T>::remove_min()
   {
      if(is_empty())
      {
         throw "MPQ is empty!!";
      }
      T temp = min();
      linkList.pop_front();
      return temp;
   }

template <typename T>
   void SortedMPQ<T>::insert(const T& data)
   {
      if (linkList.size() == 0)
      {
         linkList.push_front(data);
         return;
      }

   typename std::list<T>::iterator it;
      for (it = linkList.begin(); it != linkList.end(); ++it)
      {
         if (data < *it) 
         {
            linkList.insert(it, data);
            return;
        }

    }

   linkList.push_back(data);
   return;
}

#endif