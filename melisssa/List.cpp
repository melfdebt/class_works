#include "List.h"
#include <iostream>
using namespace std;

template<typename T>
inline List<T>::List()
{
}

template<typename T>
List<T>::List(T* arr, int size)//fhkscnkscnsn
{
	this->first = arr;
	this->last = *arr[size];
	Node<T>* now = arr;
	for (int i = 1; i < size-1; i++) {
		now.next = *arr[i];
		now = now.next;
	}
	this->last->next = nullptr;
}

template<typename T>
List<T>::List(Node<T>* first) : first(first) {
}

template<typename T>
List<T>::List(Node<T>* first, Node<T>* last): first(first),  last(last)
{
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
bool List<T>::isEmpty()
{
	return (first==nullptr);
}

template<typename T>
int List<T>::getLenght()
{
	int lenght = 0;
	Node<T>* now = first;
	while (now->next != nullptr) {
		lenght++;
		now = now.next;
	}
	return lenght;
}

template<typename T>
void List<T>::addElem(Node<T>* node)
{
	this->last.next = node;
	this->last = node;
}

template<typename T>
void List<T>::print()
{
	Node<T>* now = first;
	for (int i = 0; i < getLenght(); i++) {
		cout << now.getValue() << " ";
		now = now.next;
	}
}

template<typename T>
Node<T>* List<T>::searchValue(T value)
{
	Node<T>* now = first;
	for (int i = 0; i < getLenght(); i++) {
		if (now.getValue() == value) return now;
		else {
			now = now.getNext();
		}
	}
	return nullptr;
}

template<typename T>
void List<T>::deleteFirst()
{
	this->first = first->next;
}

template<typename T>
void List<T>::deleteLast()
{
	Node<T>* now = first;
	for (int i = 0; i < getLenght(); i++)
	{
		if (now.next == this->last) {
			this->last = now;
			now.next = nullptr;
			break;
		}
		now = now.next;
	}
}

template<typename T>
void List<T>::deleteElem(T value)
{
	Node<T>* now = first;
	for (int i = 0; i < getLenght(); i++)
	{
		if (now.next.getValue() == value) {
			now.next = now.next.next;
			break;
		}
		now = now.next;
	}
}

template<typename T>
Node<T>* List<T>::operator[](int i)
{
	Node<T>* now = first;
	for (int e = 0; e < i; e++) {
		now = now.next;
	}
	return now.next;
}
