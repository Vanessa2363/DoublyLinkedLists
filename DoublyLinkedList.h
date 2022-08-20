//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListEmptyError.h"
#include "ConstDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
//Doubly linked list controller point to elements
//Keeps track of things
//Implemneting iterators
template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoublyLinkedNode<T>*;

  using iterator = DoublyLinkedListIterator<T>;//put the type of your iterator here
  using const_iterator =  ConstDoublyLinkedListIterator<T>;//put the type of your const iterator here
  using reverse_iterator =ReverseDoublyLinkedListIterator<T>; //put the type of your reverse iterator here
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>; //put the type of your const reverse iterator here

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);

  //create an empty DoublyLinkedList
  DoublyLinkedList();


  //destructor
  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();

  //get a reference to the front element in the list
  const T& front() const;
  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  //If list is empty, make a new node, node is both head and tail
  //Insert a value anywhere, check posiiton so it's not out of bounds
  void insert(iterator& position, const T& value);


  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
    DoublyLinkedNode <T>* head;
    DoublyLinkedNode <T>* tail;
    int sizeList;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()  {
    head = nullptr;
    tail = nullptr;
    sizeList = 0;
}
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values) : DoublyLinkedList() {
    for(const T& item : values){
        push_back(item);
    }
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
    return size() == 0;
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return sizeList;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
    return head->value;
}

template<typename T>
T& DoublyLinkedList<T>::front() {
    if (size() == 0){
        throw DoublyLinkedListEmptyError();
    }else{
        return head->value;
    }
}
//old code
//return head->value;

template<typename T>
const T& DoublyLinkedList<T>::back() const {
    return tail->value;
}

template<typename T>
T& DoublyLinkedList<T>::back() {
    if(size() == 0){
        throw DoublyLinkedListEmptyError();
    }else{
        return tail->value;
    }
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    auto itr = begin();
    insert(itr, value);
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    auto itr = end();
    insert(itr, value);
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    while (!empty()){
        auto itr = begin();
        erase(itr);
    }
}

template<typename T>
//destructor
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const {
    return const_iterator(head);
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
    return const_iterator(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return iterator(head);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
    return iterator(nullptr);
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value) {
    //Insert when out of bounds
//    if(!position){
//        throw DoublyLinkedListOutOfBoundsError();
//    }
    auto* Node = new DoublyLinkedNode<T>;
    Node->value = value;
    //Insert when empty - How to create a new node?
    if(size() == 0){
        head = Node;
        tail = Node;
    }
    //Insert at beginning
    else if(position == begin()){
        Node -> next = head;
        head -> prev = Node;
        head = Node;

    }else if(position == end()){
        //Insert at end
        Node -> prev = tail;
        tail -> next = Node;
        tail = Node;

    }else{
        //Insert at middle
        DoublyLinkedNode<T>* current = position.curNode;
        DoublyLinkedNode<T>* newNode = Node;
        newNode->value = value;
        DoublyLinkedNode<T>* prevNode = position.curNode -> prev;

        //Rewiring
        current->prev = newNode;
        newNode->next = current;
        newNode->prev = prevNode;
        prevNode->next = newNode;
    }
    sizeList++;
}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
    //Erase when position is out of bounds
    if(!position){
        throw DoublyLinkedListOutOfBoundsError();
    }
    //auto* Node = new DoublyLinkedNode<T>;

    if(size() == 0){
        //Erase when empty
        throw DoublyLinkedListEmptyError();
    }
    else if(size() == 1){
        head = nullptr;
        tail = nullptr;
    }
    //Erase value at beginning
    else if(position == begin()){
//        head = position.curNode;
        DoublyLinkedNode<T>* newHead = position.curNode -> next;
        head = newHead;
        head -> prev = nullptr;
    }else if(position.curNode == tail){
        //Erase value at end
        DoublyLinkedNode<T>* newTail = position.curNode -> prev;
        tail = newTail;
        tail -> next = nullptr;
    }else{
        //Erase value in middle
//        DoublyLinkedNode<T>* current = position.curNode;
        DoublyLinkedNode<T>* ogPrevNode = position.curNode -> prev;
        DoublyLinkedNode<T>* ogNextNode = position.curNode -> next;
        //Rearange values
        ogPrevNode -> next = ogNextNode;
        ogNextNode -> prev = ogPrevNode;
    }
    delete position.curNode;
    sizeList--;
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crbegin() const {
    return const_reverse_iterator(tail);

}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crend() const {
    return const_reverse_iterator(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin(){
    //Directly dereference list
    return reverse_iterator(tail);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend() {
    return reverse_iterator(nullptr);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList) {
//Printing values out
    for(auto item : doublyLinkedList){
        out << item << " ";
    }
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList) {
//Push back for each value
//Double check how cin works
    T value;
    while(in >> value){
        doublyLinkedList.push_back(value);
    }
    return in;
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
