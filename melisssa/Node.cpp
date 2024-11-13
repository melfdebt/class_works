#include "Node.h"
template<typename T>
Node<T>::Node()
{
	this->value = 0;
	this->next = nullptr;
}
template<typename T>
Node<T>::Node(T value, Node<T>* node)
{
	this->value = value;
	this->next = node;
}
//
//template <typename T>
//Node<T>::Node() {
//	this->value = 0;
//	this->next = nullptr;
//}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
inline void Node<T>::setValue(T value)
{
	this->value = value;
}

template<typename T>
inline void Node<T>::setNext(Node<T>* node)
{
	this->next = node;
}

template<typename T>
inline T Node<T>::getValue()
{
	return value;
}

template<typename T>
inline Node<T>* Node<T>::getNext()
{
	return next;
}