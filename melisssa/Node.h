#pragma once
template <typename T>
class Node
{
private:
	T value;
	Node<T>* next;
public:
	Node();
	Node(T value, Node<T>* node);
	~Node();
	void setValue(T value);
	void setNext(Node<T>* node);
	T getValue();
	Node<T>* getNext();
};


