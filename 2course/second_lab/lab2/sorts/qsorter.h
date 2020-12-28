#pragma once
#include "sorter.h"

template<typename T>
class qsorter : public sorter<T>{
public:
	qsorter() = default;
	~qsorter() = default;
	Sequence<T>* sort(Sequence<T>* seq, bool (*comparator)(const T&, const T&)) override {
		qsort(seq, 0, seq->getLength() - 1,comparator);
		return seq;
	}
private:
	int partition(Sequence<T>* seq, int l, int r, bool (*comparator)(const T&, const T&)){
		int pivot = seq->get(r);
	    int i = l - 1;

	    for (int j = l; j <= r - 1; j++){
	        if (comparator(seq->get(j) , pivot))
	        {
	            i++;
	            this->swap(i, j, seq);
	        }
	    }
	   	this->swap(i+1, r, seq);
	    return i + 1;
	}
	void qsort(Sequence<T>* seq, int l, int r, bool (*comparator)(const T&, const T&)){
		if (l < r)
		{
			int piv = partition(seq, l, r, comparator);
			qsort(seq, l, piv-1, comparator);
			qsort(seq, piv+1, r, comparator);
		}
	}
};