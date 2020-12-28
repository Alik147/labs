#include <iostream>
#include <vector>
#include "time.h"
#include <algorithm>


#include "./sorts/bubblesorter.h"
#include "./sorts/mergesorter.h"
#include "./sorts/shellsorter.h"
#include "./sorts/qsorter.h"
#include "./sorts/heapsorter.h"


#include "test_runner.h"
#include "paginator.h"
#include "comparator.h"


#include "./ArraySequence.hpp"
#include "./LinkedListSequence.hpp"

#define MSIZE 5000
using namespace std;

void SeqFill(size_t size, Sequence<int>* v){
	for (int i = 0; i < size; ++i)
	{
		v->append(rand() % 1000000);
	}
}
void SeqFillSorted(size_t size, Sequence<int>* v){
	for (int i = 0; i < size; ++i)
	{
		v->append(i);
	}
}

void SeqFillSortedBack(size_t size, Sequence<int>* v){
	for (int i = size; i >= 0; --i)
	{
		v->append(i);
	}
}

void Arr_bublleSortTest();
void Arr_qSortTest();
void Arr_mergeSortTest();
void Arr_shellSortTest();
void Arr_heapSortTest();

void List_bublleSortTest();
void List_qSortTest();
void List_mergeSortTest();
void List_shellSortTest();
void List_heapSortTest();

void TestAll() {
  TestRunner tr;
  RUN_TEST(tr, Arr_bublleSortTest);
  RUN_TEST(tr, Arr_shellSortTest);
  RUN_TEST(tr, Arr_mergeSortTest);
  RUN_TEST(tr, Arr_qSortTest);
  RUN_TEST(tr, Arr_heapSortTest);
  RUN_TEST(tr, List_bublleSortTest);
  RUN_TEST(tr, List_shellSortTest);
  RUN_TEST(tr, List_mergeSortTest);
  RUN_TEST(tr, List_qSortTest);
  RUN_TEST(tr, List_heapSortTest);
}


int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	TestAll();
	string answer = " ";

	cout<<"WELCOME TO  THE LAB1 :)\n\n";
	

	while(answer != "exit") {
		cout<<"1.test LinkedList\n";
		cout<<"2.test DynamicArray\n";
		cout<<">";
		cin>>answer;
		if (answer == "1")
		{
			LinkedListSequence<int> Seq;
			size_t size;
			cout<<"size = ";
			cin>>size;
			cout<<"how to fill:\n\t1.random\n\t2.sorted\n\t3.sorted in reverse order\n";
			answer = "0";
			
				cout<<">";
				cin>>answer;
			
			if (answer == "1") SeqFillSorted(size, &Seq);
			if (answer == "2") SeqFill(size, &Seq);
			if (answer == "3") SeqFillSortedBack(size, &Seq);
			cout<<"sort by:\n\t1.bubblesorter\n\t2.heapsorter\n\t3.mergesorter\n\t4.qsorter\n\t5.shellsorter\n";
			cout<<'>';
			cin>>answer;
			sorter<int>* sorter ;
			if (answer == "1")
			{
				{
				LOG_DURATION("Sort list with bubblesorter");
				sorter = new bubblesorter<int>;
				
				}
			}
			if (answer == "2")
			{
				{
				LOG_DURATION("Sort list with heapsorter");
				sorter = new heapsorter<int>;
				// sorter->sort(&Seq, &lessThan<int>);
				}
			}
			if (answer == "3")
			{
				{
				LOG_DURATION("Sort list with mergesorter");
				sorter = new mergesorter<int>;
				// sorter->sort(&Seq, &lessThan<int>);
				}
			}
			if (answer == "4")
			{
				{
				LOG_DURATION("Sort list with qsorter");
				sorter = new qsorter<int>;
				// sorter->sort(&Seq, &lessThan<int>);
				}
			}
			if (answer == "5")
			{
				{
				LOG_DURATION("Sort list with shellsorter");
				sorter = new shellsorter<int>;
				// sorter->sort(&Seq, &lessThan<int>);
				}
			}
			sorter->sort(&Seq, &lessThan<int>);
			answer = "0";
		}
		if (answer == "2")
		{
			ArraySequence<int> Seq;
			size_t size;
			cout<<"size = ";
			cin>>size;
			cout<<"how to fill:\n\t1.random\n\t2.sorted\n\t3.sorted in reverse order\n";
			answer = "0";
			cout<<">";
			cin>>answer;
			if (answer == "1") SeqFillSorted(size, &Seq);
			if (answer == "2") SeqFill(size, &Seq);
			if (answer == "3") SeqFillSortedBack(size, &Seq);
			cout<<"sort by:\n\t1.bubblesorter\n\t2.heapsorter\n\t3.mergesorter\n\t4.qsorter\n\t5.shellsorter\n";
			cout<<'>';
			cin>>answer;
			if (answer == "1")
			{
				{
				LOG_DURATION("Sort arr with bubblesorter");
				auto* sorter = new bubblesorter<int>;
				sorter->sort(&Seq, &lessThan<int>);
				}
			}
			if (answer == "2")
			{
				{
				LOG_DURATION("Sort arr with heapsorter");
				auto* sorter = new heapsorter<int>;
				sorter->sort(&Seq, &lessThan<int>);
				}
			}
			if (answer == "3")
			{
				{
				LOG_DURATION("Sort arr with mergesorter");
				auto* sorter = new mergesorter<int>;
				sorter->sort(&Seq, &lessThan<int>);
				}
			}
			if (answer == "4")
			{
				{
				LOG_DURATION("Sort arr with qsorter");
				auto* sorter = new qsorter<int>;
				sorter->sort(&Seq, &lessThan<int>);
				}
			}
			if (answer == "5")
			{
				{
				LOG_DURATION("Sort arr with shellsorter");
				auto* sorter = new shellsorter<int>;
				sorter->sort(&Seq, &lessThan<int>);
				}
			}
			
			answer = "0";
		}
		
		
	}
	return 0;
}


//-------------------------------------------------------------------------------------------------------------ARRAY

void Arr_bublleSortTest(){
	ArraySequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort array with bubblesorter");
		auto* sorter = new bubblesorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void Arr_qSortTest(){
	ArraySequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new bubblesorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort array with qsorter");
		auto* sorter = new qsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void Arr_mergeSortTest(){
	ArraySequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort array with mergesorter");
		auto* sorter = new mergesorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void Arr_shellSortTest(){
	ArraySequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort array with shellsorter");
		auto* sorter = new shellsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}

	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void Arr_heapSortTest(){
	ArraySequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	ArraySequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort array with heapsorter");
		auto* sorter = new heapsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}

	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}



//-------------------------------------------------------------------------------------------------------------LIST

void List_bublleSortTest(){
	
	LinkedListSequence<int> arrSeq;
	SeqFill(1000, &arrSeq);
	LinkedListSequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort list with bubblesorter");
		auto* sorter = new bubblesorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}

	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void List_qSortTest(){
	LinkedListSequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	LinkedListSequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new mergesorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort list with qsorter");
		auto* sorter = new qsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void List_mergeSortTest(){
	LinkedListSequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	LinkedListSequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort list with mergesorter");
		auto* sorter = new mergesorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}
	
	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void List_shellSortTest(){
	LinkedListSequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	LinkedListSequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort list with shellsorter");
		auto* sorter = new shellsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}

	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}

void List_heapSortTest(){
	LinkedListSequence<int> arrSeq;
	SeqFill(MSIZE, &arrSeq);
	LinkedListSequence<int> arrSeqWorking = arrSeq;
	auto* correctSorter = new qsorter<int>;
	correctSorter->sort(&arrSeq, &lessThan<int>);
	{
		LOG_DURATION("Sort list with heapsorter");
		auto* sorter = new heapsorter<int>;
		sorter->sort(&arrSeqWorking, &lessThan<int>);
	}

	ASSERT_EQUAL(arrSeq, arrSeqWorking);
}