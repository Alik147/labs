#pragma once
#include "sorter.h"

template<typename T>
class shellsorter: public sorter<T> {
public:
	Sequence<T>* sort(Sequence<T>* seq, bool (*comparator)(const T&, const T&)) override {
		int n = seq->getLength();
	    for (int gap = n/2; gap > 0; gap /= 2){
	        for (int i = gap; i < n; i += 1){
	            T temp = seq->get(i);
	            int j;
	            for (j = i; j >= gap && !comparator(seq->get(j - gap), temp); j -= gap)
	                seq->set(j,seq->get(j-gap));
	            seq->set(j,temp);
	        }
	    }
    	return seq;
	}
};