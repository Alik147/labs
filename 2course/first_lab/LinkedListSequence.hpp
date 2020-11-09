#pragma once

#include "Sequence.hpp"
#include "LinkedList.hpp"
#include "complex.hpp"
#include <functional>

template<class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> *list;
public:
    LinkedListSequence(T *items, int count){
    	this->list = new LinkedList<T>(items, count);
    }

    LinkedListSequence(){
    	this->list = new LinkedList<T>();
    }

    LinkedListSequence(LinkedListSequence<T>& linkedList){
        
    	T* box = new T[linkedList.getLength()];
	    for (int i = 0; i < linkedList.getLength(); i++) {
	        box[i] = linkedList.get(i);
	    }
   		this->list = new LinkedList<T>(box, linkedList.getLength());
    }

    int getLength() override{
    	return this->list->getLength();
    }

    int getLength() const{
        return this->list->getLength();
    }

    T getFirst() override{
    	return this->list->getFirst();
    }

    T getLast() override{
    	return this->list->getLast();
    }

    T get(int i) override{
    	return this->list->get(i);
    }
    T get(int i) const{
        return this->list->get(i);
    }
    Sequence<T> *getSubsequence(const int startIndex, const int endIndex) override{
    	int listSize = endIndex - startIndex + 1;
    	T* newList = new T[listSize];
	    for (int i = startIndex; i <= endIndex; ++i)
	    {
	    	newList[i-startIndex] = list->get(i);
	    }
	    return new LinkedListSequence(newList, listSize);
    }

    void append(T value) override{
    	this->list->append(value);
    }

    void prepend(T value) override{
    	this->list->prepend(value);
    }

    virtual void set(int index, T value) override{
    	this->list->set(index, value);
    }

    void insertAt(int index, T value) override{
    	this->list->insertAt(index, value);
    }

    Sequence<T> *concat(Sequence<T> *list) override{
    	int listSize = this->getLength() + list->getLength();
	    T *box = new T[listSize];
	    int j = 0;
	    for (int i = 0; i < this->getLength(); i++) {
	        box[j] = this->get(i);
	        j++;
	    }
	    for (int i = 0; i < list->getLength(); i++) {
	        box[j] = list->get(i);
	        j++;
	    }
	    return new LinkedListSequence(box, listSize);
    }

    void print() override{
    	this->list->print();
    }

    void deleteEllement(std::function<bool(T item)> func) override {
        this->list->deleteEllement(func);
    }

    ~LinkedListSequence() = default;
};
template<typename T>
bool operator==(const LinkedListSequence<T>& l, const LinkedListSequence<T>& r){
    if (l.getLength() != r.getLength())
    {
        return false;
    }
    for (int i = 0; i < l.getLength(); ++i)
    {
        if (l.get(i) != r.get(i))
        {
            return false;
        }
    }
    return true;
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedListSequence<T>& obj){
    for (int i = 0; i < obj.getLength(); ++i)
    {
        os<<obj.get(i)<<' ';
    }
    return os;
}