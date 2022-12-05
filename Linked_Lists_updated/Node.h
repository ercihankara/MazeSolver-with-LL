#include <iostream>
#pragma once

using namespace std;

template <class T>
class Node
{
    public:
        T data;
        // xor of next node and previous node
        Node<T>* xnode;
};

        /*// constructor
        Node();

        // insert from beginning
        void push_front(Node<T>* &head_ref, T data);
        // insert from end
        void push_rear(Node<T>* &rear_ref, T data);

        // remove and return element at beginning
        T pop_front();
        // remove and return element at end
        T pop_rear();

        // return w/o removing at beginning
        T peek_front();

        // delete a node
        Node<T> delete_node();

        // print all stored elements from end to beginning
        void print_elements(Node<T>* head); // make it from end to beginning
        // xor the pointers
        Node<T>* Xor(Node<T>* x, Node<T>* y);*/
