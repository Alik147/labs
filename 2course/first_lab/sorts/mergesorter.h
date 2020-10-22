#pragma once
#include "sorter.h"

template<typename T>
class mergesorter : public sorter<T>{
public:
	Sequence<T>* sort(Sequence<T>* seq, bool (*comparator)(const T&, const T&)) override {
		T additional_arr[seq->getLength()];
		mergeSort(seq, additional_arr, 0, seq->getLength()-1, comparator);
		return seq;
	}
private:
	void merge(Sequence<T>* seq, T* add_arr, int left, int mid, int right, bool (*comparator)(const T&, const T&)){
		int ileft = 0, iright = 0;

	    while (ileft + left < mid && iright + mid < right) {
	        if (comparator(seq->get(ileft + left), seq->get(iright + mid))) {
	            add_arr[ileft + iright] = seq->get(left + ileft);
	            ileft++;
	        } else {
	            add_arr[ileft + iright] = seq->get(iright + mid);
	            iright++;
	        }
	    }

	    while (ileft + left < mid) {
	        add_arr[ileft + iright] = seq->get(left + ileft);
	        ileft++;
	    }
	    while (iright + mid < right) {
	        add_arr[ileft + iright] = seq->get(iright + mid);
	        iright++;
	    }

	    for (int i = 0; i < ileft + iright; i++) {
	        seq->set(left + i, add_arr[i]);
	    }
	}
	void mergeSort(Sequence<T>* seq, T* add_arr,int l, int r, bool (*comparator)(const T&, const T&)){
		if (l < r) 
	    { 
	         
	        int m = l + (r - l) / 2; 
	  
	        mergeSort(seq, add_arr, l, m, comparator); 
	        mergeSort(seq, add_arr, m + 1, r, comparator); 
	  
	        merge(seq, add_arr, l, m, r, comparator); 
	    }
	}
};