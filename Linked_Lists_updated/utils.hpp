#include <iostream>
#include "Node.h"
#pragma once

using namespace std;

// Xor the addresses
template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y){
    return reinterpret_cast<Node<T>*>(
        reinterpret_cast<uintptr_t>(x)
        ^ reinterpret_cast<uintptr_t>(y));
}

// insert node at the beginning of XORed LL, set it as head
template <class T>
void insert(Node<T>* &head_ref, T data){
    // Allocate memory for the new node
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;

    // Since the new node is inserted at the
    // start, xnode of new node will always be
    // Xor of current head and NULL
    new_node -> xnode = head_ref;

    // If the linkedlist is not empty, then xnode of
    // present head node will be XOR of the new node
    // and node next to current head */
    if(head_ref != (Node<T>*) nullptr){
        // *(head_ref)->xnode is Xor of (NULL and next).
        // If we XOR Null with next, we get next
        head_ref -> xnode = Xor(new_node, head_ref -> xnode);
    }

    // Change head
    head_ref = new_node;
    //cout << head_ref -> data << endl;
}

// insert node at the end of XORed LL
template <class T>
void insert_back(Node<T>* &head_ref, T data){
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = (Node<T>*) nullptr;
    Node<T>* nextPtr;
    // Allocate memory for the new node
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;

    // for an empty LL
    if(head_ref == (Node<T>*) nullptr){
        new_node -> xnode = currPtr;
        head_ref = new_node;
    }
    // for a LL with only one element
    else if(head_ref -> xnode == (Node<T>*) nullptr){
        new_node -> xnode = currPtr;
        head_ref -> xnode = new_node;
    }
    // other cases
    else{
        while(Xor(prevPtr, currPtr -> xnode) != (Node<T>*) nullptr){ // reach to the tail
            // update the pointers to be used
            nextPtr = Xor(prevPtr, currPtr -> xnode);
            prevPtr = currPtr;
            currPtr = nextPtr;
        }

        new_node -> xnode = currPtr;
    }
    if (prevPtr != NULL){
        // *(head_ref)->xnode is Xor of (NULL and next).
        // If we XOR Null with next, we get next
        currPtr -> xnode = Xor(new_node, currPtr -> xnode);
    }
}

// remove and return element at beginning
template <class T>
T remove_head(Node<T>* &head_ref){
    T temp = head_ref -> data;
    if(head_ref == (Node<T>*) nullptr){
        return NULL;
    }

    else{
        Node<T>* tempPtr = head_ref;

        // update the head pointer
        head_ref = Xor((Node<T>*) nullptr, tempPtr -> xnode); // address
        // check if LL has only one element (up and down steps combined)
        if(head_ref != (Node<T>*) nullptr)
            // update header address again
            head_ref -> xnode = Xor((Node<T>*) nullptr, Xor(tempPtr, head_ref -> xnode));

        delete(tempPtr);
    }
    return temp;

}

// remove and return element at end
template <class T>
T remove_tail(Node<T>* &head_ref){
    T temp;
    if(head_ref == (Node<T>*) nullptr){
        return NULL;
    }

    else{
        Node<T>* currPtr = head_ref;
        Node<T>* prevPtr = (Node<T>*) nullptr;
        Node<T>* nextPtr;

        while(Xor(prevPtr, currPtr -> xnode) != (Node<T>*) nullptr){ // reach to the tail
            // update the pointers to be used
            nextPtr = Xor(prevPtr, currPtr -> xnode);
            prevPtr = currPtr;
            currPtr = nextPtr;
        }

        if(prevPtr != (Node<T>*) nullptr) // LL with more than one nodes
            prevPtr -> xnode = Xor(Xor(currPtr, prevPtr -> xnode), (Node<T>*) nullptr);

        else
            head_ref = NULL;
        temp = currPtr -> data;
        // delete the last node
        delete(currPtr);
    }
    return temp;
}

// remove and return element at beginning
template <class T>
T peek_head(Node<T>* head_ref){
    if(head_ref == (Node<T>*) nullptr){
        return NULL;
    }
    return head_ref -> data;
}

// remove and return element at beginning
template <class T>
T peek_tail(Node<T>* head_ref){
    if(head_ref == (Node<T>*) nullptr){
        return NULL;
    }
    else{
        Node<T>* currPtr = head_ref;
        Node<T>* prevPtr = (Node<T>*) nullptr;
        Node<T>* nextPtr;

        while(Xor(prevPtr, currPtr -> xnode) != (Node<T>*) nullptr){ // reach to the tail
            // update the pointers to be used
            nextPtr = Xor(prevPtr, currPtr -> xnode);
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
    return currPtr -> data;
    }
}

template <class T>
void printList(Node<T>* head_ref){

    Node<T>* current = head_ref;
    Node<T>* previous = NULL;
    Node<T>* next;

    cout << "LL: ";
    // Until the current pointer reaches the end of the link list
    while (current != (Node<T>*) nullptr) {
        cout << current -> data;
        // "next" points to the next element in the node
        next = Xor(previous, current -> xnode);

        // Update pointers
        previous = current;
        current = next;
    }
    cout<<endl;
}

template <class T>
bool is_empty_LL(Node<T>* head_ref){
    if(head_ref == (Node<T>*) nullptr)
        return true;
    else
        return false;
}

// reverse the XORed LL
template <class T>
void reverse(Node<T>*& head_ref){
    // Stores pointer of current node
    Node<T>* currPtr = head_ref;

    if (currPtr == NULL)
        return;
    else{
        Node<T>* prevPtr = NULL;
        Node<T>* nextPtr;
        // check next element (NULL or not), traversing
        while(Xor(prevPtr, currPtr -> xnode) != NULL){
            // update next pointer
            nextPtr = Xor(prevPtr, currPtr -> xnode);
            // update previous pointer
            prevPtr = currPtr;
            // update current pointer
            currPtr = nextPtr;
        }
    }
        // tail is the new head!
        head_ref = currPtr;
}

// print backwards, from end to beginning
template <class T>
void printReverse(Node<T>* head_ref)
{
    Node<T>* tempPtr = head_ref;
    reverse(tempPtr);
    printList(tempPtr);

}
