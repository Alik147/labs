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

void arrSeqFill(size_t size, ArraySequence<int>* v){
	for (int i = 0; i < size; ++i)
	{
		v->append(rand() % 1000000);
	}
}

void bublleSortTest(){
	ArraySequence<int> arrSeq;
	arrSeqFill(10000, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort with bubblesorter");
		auto* sorter = new bubblesorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void qSortTest(){
	ArraySequence<int> arrSeq;
	arrSeqFill(10000, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new bubblesorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort with qsorter");
		auto* sorter = new qsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void mergeSortTest(){
	ArraySequence<int> arrSeq;
	arrSeqFill(10000, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort with mergesorter");
		auto* sorter = new mergesorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void shellSortTest(){
	ArraySequence<int> arrSeq;
	arrSeqFill(10000, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort with shellsorter");
		auto* sorter = new shellsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	// arrSeqWorking.print();
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void TestAll() {
  TestRunner tr;
  RUN_TEST(tr, bublleSortTest);
  RUN_TEST(tr, shellSortTest);
  RUN_TEST(tr, mergeSortTest);
  RUN_TEST(tr, qSortTest);
}


int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	TestAll();
	return 0;
}