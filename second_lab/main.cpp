#include <iostream>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "TriangularMatrix.hpp"

using namespace std;
int main(int argc, char const *argv[])
{
	complex* arr = new complex[3];
	for (int i = 0; i < 3; ++i)
	{
		int a,b;
		cin>>a>>b;
		complex x(a,b);
		arr[i] = x;
		arr[i].print();
	}
	DynamicArray<complex> com(arr, 3);
	// int** arr1 = new int*[3];
	// for (int i = 0; i < 3; ++i)
	// {
	// 	arr1[i] = new int [3];
	// }
	// for (int i = 0; i < 3; ++i)
	// {
	// 	for (int j = 0; j < 3; ++j)
	// 	{
	// 		cin>>arr1[i][j];
	// 	}
	// }
	cout<<"next\n";
	// TriangularMatrix<int> second(arr1,3);
	// second.print();
	return 0;
}