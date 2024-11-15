#include "List.h"
#include <iostream>
using namespace std;

template<typename T>
inline List<T>::List()
{
}

template<typename T>
List<T>::List(T* arr, int size)
{
	this->first = arr;
	this->last = *arr[size];
	Node<T>* now = arr;
	for (int i = 1; i < size - 1; i++) {
		now->setNext() = *arr[i];
		now = now->getNext();
	}
	this->last->next = nullptr;
}

template<typename T>
List<T>::List(Node<T>* first) : first(first) {
}

template<typename T>
List<T>::List(Node<T>* first, Node<T>* last) : first(first), last(last)
{
}

template<typename T>
List<T>::~List()//jfdjjdf
{
	
}

template<typename T>
bool List<T>::isEmpty()
{
	return (this->first == nullptr);
}

template<typename T>
int List<T>::getLenght()
{
	int lenght = 0;
	Node<T>* now = this->first;
	while (now->setNext() != nullptr) {
		lenght++;
		now = now->getNext();
	}
	return lenght;
}

template<typename T>
void List<T>::addElem(Node<T>* node)
{
	this->last->setNext() = node;
	this->last = node;
}

template<typename T>
void List<T>::print()
{
	Node<T>* now = this->first;
	for (int i = 0; i < getLenght(); i++) {
		cout << now->getValue() << " ";
		now = now->getNext();
	}
}

template<typename T>
Node<T>* List<T>::searchValue(T value)
{
	Node<T>* now = this->first;
	for (int i = 0; i < getLenght(); i++) {
		if (now->getValue() == value) return now;
		else {
			now = now->getNext();
		}
	}
	return nullptr;
}

template<typename T>
void List<T>::deleteFirst()
{
	Node<T>* buf = this->first;
	this->first = buf->getNext();
	delete first;
}

template<typename T>
void List<T>::deleteLast()
{
	Node<T>* now = this->first;
	for (int i = 0; i < getLenght(); i++)
	{
		if (now->getNext() == this->last) {
			this->last = now;
			now->setNext() = nullptr;
			break;
		}
		now = now->getNext();
	}
}

template<typename T>
void List<T>::deleteElem(T value)
{
	Node<T>* now = this->first;
	for (int i = 0; i < getLenght(); i++)
	{
		if (now->getNext()== value) {
			now->setNext = now->getNext()->getNext();
			break;
		}
		now = now->getNext();
	}
}

template<typename T>
Node<T>* List<T>::operator[](int i)
{
	Node<T>* now = this->first;
	for (int e = 0; e < i; e++) {
		now = now->getNext();
	}
	return now->getNext();
}

