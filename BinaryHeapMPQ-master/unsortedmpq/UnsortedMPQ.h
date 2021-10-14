#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

/**
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   private:
        std::vector<T> vect;
    public:
        T remove_min();
        T min();
        bool is_empty();
        void insert(const T& data);
};

template <typename T>
   T UnsortedMPQ<T>::remove_min()
   {
      if(is_empty())
      {
        throw ("MPQ is empty!!");
      }
      else
      {
         int n = 0;
         T val = vect.at(0);
         for(int i = 0; i < vect.size(); i++){
            if(vect[i] < val){
               val = vect[i];
               n = i;
            }
        }
      //vect.erase(vect.begin() + n);
      int vari=vect.size();
      std::swap(vect[n],vect[vari-1]);
      vect.pop_back();
      return val;
    }
}

template <typename T>
   T UnsortedMPQ<T>::min(){
      if(is_empty())
      {
         throw ("MPQ is empty!!");
      }
      else
      {
         T val = vect.at(0);
            for(int i = 0; i < vect.size(); i++)
            {
               if(vect[i] < val)
               {
                  val = vect[i];
               }
         }
        return val;
    }
}

template <typename T>
   bool UnsortedMPQ<T>::is_empty(){
      if(vect.size() == 0)
      {
         return true;
      }
   return false;
}

template <typename T>
   void UnsortedMPQ<T>::insert(const T& data)
   {
      vect.push_back(data);    
   }



#endif