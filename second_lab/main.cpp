#include <iostream>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "TriangularMatrix.hpp"

using namespace std;
int main(int argc, char const *argv[])
{
	TriangularMatrix<complex> *TriangularMatrixCOMPLEX = nullptr;
	TriangularMatrix<int> *TriangularMatrixINT = nullptr;
	LinkedListSequence<complex> *LinkedListCOMPLEX = nullptr;
	LinkedListSequence<int> *LinkedListINT = nullptr;
	ArraySequence<complex> *DynamicArrayCOMPLEX = nullptr;
	ArraySequence<int> *DynamicArrayINT = nullptr;

	string complexORint = "null";
	string answer = " ";

	cout<<"WELCOME TO  THE LAB2 :)\n";
	cout<<"0.test TriangularMatrix\n";
	cout<<"1.test LinkedList\n";
	cout<<"2.test DynamicArray\n";

	while(answer != "exit") {
		cout<<">";
		cin>>answer;
		if (answer == "TriangularMatrix" || answer == "0")
		{
			while(answer != "..") {
				cout<<">TriangularMatrix>";

				cin>>answer;
				    if (answer == "create")
				    {
				    	cout<<"0.Complex\n";
				    	cout<<"1.Real\n";
				    	cout<<">TriangularMatrix>create>";

						cin>>complexORint;
						while(complexORint != "0" && complexORint != "1") {
							cout<<">TriangularMatrix>create>";
						    cin>>complexORint;
						}
						if (complexORint == "0")
						{
							int size;
				    		cout<<"Matrix size:";
				    		cin>>size;
				    		complex** arr = new complex*[size];
				    		for (int i = 0; i < size; ++i)
				    		{
				    			arr[i] = new complex[size];
				    		}
				    		for (int i = 0; i < size; ++i)
				    		{
				    			for (int j = 0; j < i; ++j)
				    			{
				    				cout<<"0+0i ";
				    				complex x;
				    				arr[i][j] = x;
				    			}
				    			for (int j = i; j < size; ++j)
				    			{
				    				int a,b;
				    				cin>>a>>b;
				    				complex x(a,b);
				    				arr[i][j] = x;
				    			}
				    		}
							TriangularMatrixCOMPLEX = new TriangularMatrix<complex>(arr,size);
						}
						if (complexORint == "1")
						{
							int size;
				    		cout<<"Matrix size:";
				    		cin>>size;
				    		int** arr = new int*[size];
				    		for (int i = 0; i < size; ++i)
				    		{
				    			arr[i] = new int[size];
				    		}
				    		for (int i = 0; i < size; ++i)
				    		{
				    			for (int j = 0; j < i; ++j)
				    			{
				    				cout<<"0 ";
				    				arr[i][j] = 0;
				    			}
				    			for (int j = i; j < size; ++j)
				    			{
				    				int a;
				    				cin>>a;
				    				arr[i][j] = a;
				    			}
				    		}
							TriangularMatrixINT = new TriangularMatrix<int>(arr,size);
						}
				    }


				    if (answer == "print"){
				    	if (complexORint == "0")
				    	{
				    		TriangularMatrixCOMPLEX->print();
				    	}

				    	if (complexORint == "1")
				    	{
				    		TriangularMatrixINT->print();
				    	}
				    }


				    if (answer == "det"){
				    	if (complexORint == "0")
				    	{
				    		cout<<TriangularMatrixCOMPLEX->det()<<endl;
				    	}

				    	if (complexORint == "1")
				    	{
				    		cout<<TriangularMatrixINT->det()<<endl;
				    	}
				    }


				    if (answer == "norm_x"){
				    	if (complexORint == "0")
				    	{
				    		cout<<"Error\n";
				    	}

				    	if (complexORint == "1")
				    	{
				    		cout<<TriangularMatrixINT->norm_x()<<endl;
				    	}
				    }


				    if (answer == "norm_y"){
				    	if (complexORint == "0")
				    	{
				    		cout<<"Error\n";
				    	}

				    	if (complexORint == "1")
				    	{
				    		cout<<TriangularMatrixINT->norm_y()<<endl;
				    	}
				    }


				    if (answer == "multi"){
				    	if (complexORint == "0")
				    	{
				    		int a;
				    		cin>>a;
				    		TriangularMatrixCOMPLEX->scalarMultiplication(a);
				    	}

				    	if (complexORint == "1")
				    	{
				    		int a;
				    		cin>>a;
				    		TriangularMatrixINT->scalarMultiplication(a);
				    	}
				    }


				    if (answer == "sum"){
				    	if (complexORint == "0")
				    	{
				    		complex** mat = new complex*[TriangularMatrixCOMPLEX->getSize()];
				    		for (int i = 0; i < TriangularMatrixCOMPLEX->getSize(); ++i)
				    		{
				    			mat[i] = new complex[TriangularMatrixCOMPLEX->getSize()];
				    		}
				    		for (int i = 0; i < TriangularMatrixCOMPLEX->getSize(); ++i)
				    		{
				    			for (int j = 0; j < i; ++j)
				    			{
				    				complex x;
				    				cout<<x<<" ";
				    				mat[i][j] = x;
				    			}
				    			for (int j = i; j < TriangularMatrixCOMPLEX->getSize(); ++j)
				    			{
				    				int a,b;
				    				cin>>a>>b;
				    				complex x(a,b);
				    				mat[i][j] = x;
				    			}
				    		}
				    		TriangularMatrix<complex> newmat(mat, TriangularMatrixCOMPLEX->getSize());
				    		TriangularMatrixCOMPLEX->sum_with(newmat);
				    	}

				    	if (complexORint == "1")
				    	{
				    		int** mat = new int*[TriangularMatrixINT->getSize()];
				    		for (int i = 0; i < TriangularMatrixINT->getSize(); ++i)
				    		{
				    			mat[i] = new int[TriangularMatrixINT->getSize()];
				    		}
				    		for (int i = 0; i < TriangularMatrixINT->getSize(); ++i)
				    		{
				    			for (int j = 0; j < i; ++j)
				    			{
				    				cout<<"0 ";
				    				mat[i][j] = 0;
				    			}
				    			for (int j = i; j < TriangularMatrixINT->getSize(); ++j)
				    			{
				    				int a;
				    				cin>>a;
				    				mat[i][j] = a;
				    			}
				    		}
				    		TriangularMatrix<int> newmat(mat, TriangularMatrixINT->getSize());
				    		TriangularMatrixINT->sum_with(newmat);
				    	}
				    }
				}	
		}
		if (answer == "LinkedList" || answer == "1")
		{
			while(answer != "..") {
				cout<<">LinkedList>";

				cin>>answer;


				if (answer == "create"){
			    	cout<<"0.Complex\n";
			    	cout<<"1.Real\n";
			    	cout<<">LinkedList>create>";

					cin>>complexORint;
					while(complexORint != "0" && complexORint != "1") {
							cout<<">LinkedList>create>";
						    cin>>complexORint;
						}
					cout<<"List size:";
					int size;
					cin>>size;
					if (complexORint == "0")
					{
						complex* arr = new complex[size];
						for (int i = 0; i < size; ++i)
						{
							cout<<"%d (a+bi) : ";
							int a,b;
							cin>>a>>b;
							complex x(a,b);
							arr[i] = x;
						}
						LinkedListCOMPLEX = new LinkedListSequence<complex>(arr,size);
					}
					if (complexORint == "1")
					{
						int* arr = new int[size];
						for (int i = 0; i < size; ++i)
						{
							cin>>arr[i];
						}
						LinkedListINT = new LinkedListSequence<int>(arr,size);
					}
				}


				if (answer == "print")
				{
					if (complexORint == "0")
					{
						LinkedListCOMPLEX->print();
					}

					if (complexORint == "1")
					{
						LinkedListINT->print();
					}
				}


				if (answer == "append")
				{
					if (complexORint == "0")
					{
						int a,b;
						cout<<"(a+bi) : ";
						cin>>a>>b;
						complex x(a,b);
						LinkedListCOMPLEX->append(x);
					}
					
					if (complexORint == "1")
					{
						int a;
						cin>>a;
						LinkedListINT->append(a);
					}
				}

				if (answer == "prepend")
				{
					if (complexORint == "0")
					{
						int a,b;
						cout<<"(a+bi) : ";
						cin>>a>>b;
						complex x(a,b);
						LinkedListCOMPLEX->prepend(x);
					}
					
					if (complexORint == "1")
					{
						int a;
						cin>>a;
						LinkedListINT->prepend(a);
					}
				}

				if (answer == "getSub")
				{
					int start,end;
					cout<<"start, end : ";
					cin>>start>>end;
					if (complexORint == "0")
					{
						LinkedListCOMPLEX->getSubsequence(start,end)->print();
					}
					
					if (complexORint == "1")
					{
						LinkedListINT->getSubsequence(start,end)->print();
					}
				}

				if (answer == "concat")
				{
					int size;
					cout<<"Size of new list : ";
					cin>>size;
					if (complexORint == "0")
					{
						complex* newArr = new complex[size];
						for (int i = 0; i < size; ++i)
						{
							int a,b;
							cout<<i<<"(a+bi) : ";
							cin>>a>>b;
							complex x(a,b);
							newArr[i] = x;
						}
						LinkedListSequence<complex>* temp = new LinkedListSequence<complex>(newArr,size);
						LinkedListCOMPLEX->concat(temp)->print();
					}
					
					if (complexORint == "1")
					{
						int* newArr = new int[size];
						for (int i = 0; i < size; ++i)
						{
							cout<<i<<" :";
							cin>>newArr[i];
						}
						LinkedListSequence<int>* temp = new LinkedListSequence<int>(newArr,size);
						LinkedListINT->concat(temp)->print();
					}
				}
			}
		}
		if (answer == "DynamicArray" || answer == "2")
		{
			while(answer != "..") {
					cout<<">DynamicArray>";

					cin>>answer;

						if (answer == "create"){
					    	cout<<"0.Complex\n";
					    	cout<<"1.Real\n";
					    	cout<<">DynamicArray>create>";

							cin>>complexORint;
							while(complexORint != "0" && complexORint != "1") {
									cout<<">DynamicArray>create>";
								    cin>>complexORint;
								}
							cout<<"Array size:";
							int size;
							cin>>size;
							if (complexORint == "0")
							{
								complex* arr = new complex[size];
								for (int i = 0; i < size; ++i)
								{
									cout<<i<<" (a+bi) : ";
									int a,b;
									cin>>a>>b;
									complex x(a,b);
									arr[i] = x;
								}
								DynamicArrayCOMPLEX = new ArraySequence<complex>(arr,size);
							}
							if (complexORint == "1")
							{
								int* arr = new int[size];
								for (int i = 0; i < size; ++i)
								{
									cin>>arr[i];
								}
								DynamicArrayINT = new ArraySequence<int>(arr,size);
							}
						}


				if (answer == "print")
				{
					if (complexORint == "0")
					{
						DynamicArrayCOMPLEX->print();
					}

					if (complexORint == "1")
					{
						DynamicArrayINT->print();
					}
				}


				if (answer == "append")
				{
					if (complexORint == "0")
					{
						int a,b;
						cout<<"(a+bi) : ";
						cin>>a>>b;
						complex x(a,b);
						DynamicArrayCOMPLEX->append(x);
					}
					
					if (complexORint == "1")
					{
						int a;
						cin>>a;
						DynamicArrayINT->append(a);
					}
				}

				if (answer == "prepend")
				{
					if (complexORint == "0")
					{
						int a,b;
						cout<<"(a+bi) : ";
						cin>>a>>b;
						complex x(a,b);
						DynamicArrayCOMPLEX->prepend(x);
					}
					
					if (complexORint == "1")
					{
						int a;
						cin>>a;
						DynamicArrayINT->prepend(a);
					}
				}

				if (answer == "getSub")
				{
					int start,end;
					cout<<"start, end : ";
					cin>>start>>end;
					if (complexORint == "0")
					{
						DynamicArrayCOMPLEX->getSubsequence(start,end)->print();
					}
					
					if (complexORint == "1")
					{
						DynamicArrayINT->getSubsequence(start,end)->print();
					}
				}

				if (answer == "concat")
				{
					int size;
					cout<<"Size of new list : ";
					cin>>size;
					if (complexORint == "0")
					{
						complex* newArr = new complex[size];
						for (int i = 0; i < size; ++i)
						{
							int a,b;
							cout<<"(a+bi) : ";
							cin>>a>>b;
							complex x(a,b);
							newArr[i] = x;
						}
						ArraySequence<complex>* temp = new ArraySequence<complex>(newArr,size);
						DynamicArrayCOMPLEX->concat(temp)->print();
					}
					
					if (complexORint == "1")
					{
						int* newArr = new int[size];
						for (int i = 0; i < size; ++i)
						{
							cout<<i<<" :";
							cin>>newArr[i];
						}
						ArraySequence<int>* temp = new ArraySequence<int>(newArr,size);
						DynamicArrayINT->concat(temp)->print();
					}
				}
			}	
		}
	}
	return 0;
}