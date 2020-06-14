#pragma once
#include <vector>
#include <iostream>
using namespace std;
template<typename T>
class node
{
public:
	node();
	node(T value_);
	void setValue(const T& value);
	T getValue() const;
	node<T>* goLeft();
	node<T>* goRight();
	node<T>* goPrev();
public:
	T value;
	node<T>* prev;
	node<T>* left;
	node<T>* right;
};