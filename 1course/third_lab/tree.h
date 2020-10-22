#pragma once
#include "node.h"
#include <iostream>
#include <functional>
using namespace std;
template<typename T>
class Tree
{
public:
	Tree();
	Tree(const node<T>& root_);
	void InsertNewNode(const T& val);
	void map_(function<T(T)> func, node<T>* node);
	node<T>* getRoot() const;
	int findWidth();
	int height(node<T>* node);
	void deleteNode(T val, node<T>* node);
	node<T>* find_node(node<T> *curNode, T val);
private:
	node<T>* root;
};