#include <iostream>
#include "Node.h"
#include "utils.hpp"
#pragma once

using namespace std;

template <class T>
class LL_wrapper{
    private:
        Node<T>* head_node;
        // SQ and LL comparison: rear is the head, front is the tail!
    public:
        // constructor
        LL_wrapper(){
            head_node = NULL;
        }
        // insert node at the beginning of LL
        void push_front(T data){
            insert_back(head_node, data);
        }
        // insert node at the end of LL
        void push_rear(T data){
            insert(head_node, data);
        }
        // return and remove the data from the beginning of LL
        T pop_front(){
            return remove_tail(head_node);
        }
        // return and remove the data from the end of LL
        T pop_rear(){
            return remove_head(head_node);
        }
        // return the data from the beginning of LL
        T peek_front(){
            return peek_tail(head_node);
        }
        // return the data from the end of LL
        T peek_rear(){
            return peek_head(head_node);
        }
        // print the data of LL from end to beginning
        void print_elements(){
            printReverse(head_node);
        }
        bool is_empty(){
            return is_empty_LL(head_node);
        }
        // destructor
        ~LL_wrapper(){
            delete[] head_node;
        }
};
