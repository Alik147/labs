#include <iostream>
#include <vector>
#include "time.h"
#include <algorithm>


#include "./sorts/bubblesorter.h"
#include "./sorts/mergesorter.h"
#include "./sorts/shellsorter.h"
#include "./sorts/qsorter.h"


#include "test_runner.h"
#include "paginator.h"
#include "comparator.h"


#include "./ArraySequence.hpp"
#include "./LinkedListSequence.hpp"

using namespace std;

void fillVector(size_t size, std::vector<int>* v){
	for (int i = 0; i < size; ++i)
	{
		v->push_back(rand() % 1000000);
	}
}

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	ArraySequence<int> arrSeq;
	std::vector<int> rnd_vector;
	fillVector(10000, &rnd_vector);
	for (int i = 0; i < rnd_vector.size(); ++i)
	{
		arrSeq.append(rnd_vector[i]);
	}
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	Sequence<int>* correct = correctSorter->sort(&arrSeqWorking, &lessThan<int>);
	// correct->print();
	{
		LOG_DURATION("Sort with bubblesorter");
		auto* sorter = new bubblesorter<int>;
		Sequence<int>* res = sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
		for (int i = 0; i < rnd_vector.size(); ++i)
		{
			ASSERT_EQUAL(arrSeqWorking.get(i), correct->get(i));	
		}
		arrSeqWorking = arrSeq;
	{
		LOG_DURATION("Sort with mergesorter");
		auto* sorter = new mergesorter<int>;
		Sequence<int>* res = sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
		for (int i = 0; i < rnd_vector.size(); ++i)
		{
			ASSERT_EQUAL(arrSeqWorking.get(i), correct->get(i));	
		}
	arrSeqWorking = arrSeq;
	{
		LOG_DURATION("Sort with qsorter");
		auto* sorter = new qsorter<int>;
		Sequence<int>* res = sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
		for (int i = 0; i < rnd_vector.size(); ++i)
		{
			ASSERT_EQUAL(arrSeqWorking.get(i), correct->get(i));	
		}
	arrSeqWorking = arrSeq;
	{
		LOG_DURATION("Sort with shellsorter");
		auto* sorter = new shellsorter<int>;
		Sequence<int>* res = sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	for (int i = 0; i < rnd_vector.size(); ++i)
		{
			ASSERT_EQUAL(arrSeqWorking.get(i), correct->get(i));	
		}
	return 0;
}