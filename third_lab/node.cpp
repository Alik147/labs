#include "tree.h"
template<typename T>
node<T>::node() {
	// prev = nullptr;
	left = nullptr;
	right = nullptr;
}

template<typename T>
void node<T>::setValue(const T& value_) {
	this->value = value_;
}

template<typename T>
T node<T>::getValue() const{
	return value;
}
template<typename T>
node<T>::node(T value_) : value(value_) {
	// prev = nullptr;
	left = nullptr;
	right = nullptr;
}

template<typename T>
node<T>* node<T>::goLeft() {
	return this->left;
}
template<typename T>
node<T>* node<T>::goRight() {
	return this->left;
}
template<typename T>
node<T>* node<T>::goPrev() {
	return this->left;
}