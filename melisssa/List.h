#pragma once
#include "Node.h"
template <typename T>
class List 
{
private:
    Node<T>* first;
    Node<T>* last;
public:
    List();
    List(T* array, int size);
    List(Node<T>* first);
    List(Node<T>* first, Node<T>* last);
    ~List();
    bool isEmpty();
    int getLenght();
    void addElem(Node<T>* node);
    void print();
    Node<T>* searchValue(T value);
    void deleteFirst();
    void deleteLast();
    void deleteElem(T value);
    Node<T>*operator[](int i);
};
 