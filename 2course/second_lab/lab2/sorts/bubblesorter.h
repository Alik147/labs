#pragma once
#include "sorter.h"

template<typename T>
class bubblesorter : public sorter<T> {
public:
	Sequence<T>* sort(Sequence<T>* seq, bool (*comparator)(const T&, const T&)) override {
		for (int i = 0; i < seq->getLength(); ++i)
		{
			for (int j = 0; j < seq->getLength(); ++j)
			{
				 if (comparator(seq->get(i) , seq->get(j))){
				 	this->swap(i, j, seq);
				 }
			}
		}
		return seq;
	}
};