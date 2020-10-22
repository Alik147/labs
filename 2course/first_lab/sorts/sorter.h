#pragma once
#include "../Sequence.hpp"

template<typename T>
class sorter{
public:
	sorter() = default;
	~sorter() = default;
	virtual Sequence<T>* sort(Sequence<T>* seq, bool (*comparator)(const T&, const T&)) = 0;
	
	void swap(int i, int j, Sequence<T>* seq ){
				T box = seq->get(i);
	            seq->set(i, seq->get(j));
	            seq->set(j, box);
	}
};