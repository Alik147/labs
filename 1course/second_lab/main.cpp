#include <iostream>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "TriangularMatrix.hpp"
#include <functional>

using namespace std;
int main(int argc, char const *argv[])
{
	TriangularMatrix<complex> *TriangularMatrixCOMPLEX = nullptr;
	TriangularMatrix<int> *TriangularMatrixINT = nullptr;
	LinkedListSequence<complex> *LinkedListCOMPLEX = nullptr;
	LinkedListSequence<int> *LinkedListINT = nullptr;
	ArraySequence<complex> *DynamicArrayCOMPLEX = nullptr;
	ArraySequence<int> *DynamicArrayINT = nullptr;

	bool listORarray;
	string complexORint = "null";
	string answer = " ";

	cout<<"WELCOME TO  THE LAB2 :)\n\n";
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
					if (answer == "help")
					{
						cout<<"\ncreate\n";
						cout<<"print\n";
						cout<<"det\n";
						cout<<"norm\n";
						cout<<"sum\n";
						cout<<"multi\n\n";

					}
				    if (answer == "create")
				    {
				    	cout<<"\n0.List\n";
				    	cout<<"1.Array\n\n";
				    	cout<<">TriangularMatrix>create>";
				    	cin>>listORarray;

				    	cout<<"\n0.Complex\n";
				    	cout<<"1.Real\n\n";
				    	cout<<">TriangularMatrix>create>";

						cin>>complexORint;
						while(complexORint != "0" && complexORint != "1") {
							cout<<">TriangularMatrix>create>";
						    cin>>complexORint;
						}
						if (complexORint == "0")
						{
							int size;
				    		cout<<"\nMatrix size:";
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
				    		if (listORarray)
				    		{
				    			ArraySequence<complex>** mat = new ArraySequence<complex>*[size];
								for (int i = 0; i < size; ++i)
								{
									mat[i] = new ArraySequence<complex>(arr[i],size);
								}
								TriangularMatrixCOMPLEX = new TriangularMatrix<complex>(reinterpret_cast<Sequence<complex> **>(mat),size,listORarray);
				    		}
				    		if (!listORarray)
				    		{
				    			LinkedListSequence<complex>** mat = new LinkedListSequence<complex>*[size];
								for (int i = 0; i < size; ++i)
								{
									mat[i] = new LinkedListSequence<complex>(arr[i],size);
								}
								TriangularMatrixCOMPLEX = new TriangularMatrix<complex>(reinterpret_cast<Sequence<complex> **>(mat),size,listORarray);
				    		}
				    		
						}
						if (complexORint == "1")
						{
							int size;
				    		cout<<"\nMatrix size:";
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
							if (listORarray)
				    		{
				    			ArraySequence<int>** mat = new ArraySequence<int>*[size];
								for (int i = 0; i < size; ++i)
								{
									mat[i] = new ArraySequence<int>(arr[i],size);
								}
								TriangularMatrixINT = new TriangularMatrix<int>(reinterpret_cast<Sequence<int> **>(mat),size,listORarray);
				    		}
				    		if (!listORarray)
				    		{
				    			LinkedListSequence<int>** mat = new LinkedListSequence<int>*[size];
								for (int i = 0; i < size; ++i)
								{
									mat[i] = new LinkedListSequence<int>(arr[i],size);
								}
								TriangularMatrixINT = new TriangularMatrix<int>(reinterpret_cast<Sequence<int> **>(mat),size,listORarray);
				    		}
				    		
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




				    if (answer == "norm"){
				    	if (complexORint == "0")
				    	{
				    		cout<<"Error\n";
				    	}

				    	if (complexORint == "1")
				    	{
				    		cout<<TriangularMatrixINT->norm()<<endl;
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
				    		complex** arr = new complex*[TriangularMatrixCOMPLEX->getSize()];
				    		for (int i = 0; i < TriangularMatrixCOMPLEX->getSize(); ++i)
				    		{
				    			arr[i] = new complex[TriangularMatrixCOMPLEX->getSize()];
				    		}
				    		for (int i = 0; i < TriangularMatrixCOMPLEX->getSize(); ++i)
				    		{
				    			for (int j = 0; j < i; ++j)
				    			{
				    				complex x;
				    				cout<<x<<" ";
				    				arr[i][j] = x;
				    			}
				    			for (int j = i; j < TriangularMatrixCOMPLEX->getSize(); ++j)
				    			{
				    				int a,b;
				    				cin>>a>>b;
				    				complex x(a,b);
				    				arr[i][j] = x;
				    			}
				    		}
				    		TriangularMatrix<complex>* newmat;
				    		if (listORarray)
				    		{
				    			ArraySequence<complex>** mat = new ArraySequence<complex>*[TriangularMatrixCOMPLEX->getSize()];
								for (int i = 0; i < TriangularMatrixCOMPLEX->getSize(); ++i)
								{
									mat[i] = new ArraySequence<complex>(arr[i],TriangularMatrixCOMPLEX->getSize());
								}
								newmat = new TriangularMatrix<complex>(reinterpret_cast<Sequence<complex> **>(mat),TriangularMatrixCOMPLEX->getSize(),listORarray);
				    		}
				    		if (!listORarray)
				    		{
				    			LinkedListSequence<complex>** mat = new LinkedListSequence<complex>*[TriangularMatrixCOMPLEX->getSize()];
								for (int i = 0; i < TriangularMatrixCOMPLEX->getSize(); ++i)
								{
									mat[i] = new LinkedListSequence<complex>(arr[i],TriangularMatrixCOMPLEX->getSize());
								}
								newmat = new TriangularMatrix<complex>(reinterpret_cast<Sequence<complex> **>(mat),TriangularMatrixCOMPLEX->getSize(),listORarray);
				    		}
				    		
				    		TriangularMatrixCOMPLEX->sum_with(*newmat);
				    	}

				    	if (complexORint == "1")
				    	{
				    		int** arr = new int*[TriangularMatrixINT->getSize()];
				    		for (int i = 0; i < TriangularMatrixINT->getSize(); ++i)
				    		{
				    			arr[i] = new int[TriangularMatrixINT->getSize()];
				    		}
				    		for (int i = 0; i < TriangularMatrixINT->getSize(); ++i)
				    		{
				    			for (int j = 0; j < i; ++j)
				    			{
				    				cout<<"0 ";
				    				arr[i][j] = 0;
				    			}
				    			for (int j = i; j < TriangularMatrixINT->getSize(); ++j)
				    			{
				    				int a;
				    				cin>>a;
				    				arr[i][j] = a;
				    			}
				    		}
				    		TriangularMatrix<int>* newmat;
				    		if (listORarray)
				    		{
				    			ArraySequence<int>** mat = new ArraySequence<int>*[TriangularMatrixINT->getSize()];
								for (int i = 0; i < TriangularMatrixINT->getSize(); ++i)
								{
									mat[i] = new ArraySequence<int>(arr[i],TriangularMatrixINT->getSize());
								}
								newmat = new TriangularMatrix<int>(reinterpret_cast<Sequence<int> **>(mat),TriangularMatrixINT->getSize(),listORarray);
				    		}
				    		if (!listORarray)
				    		{
				    			LinkedListSequence<int>** mat = new LinkedListSequence<int>*[TriangularMatrixINT->getSize()];
								for (int i = 0; i < TriangularMatrixINT->getSize(); ++i)
								{
									mat[i] = new LinkedListSequence<int>(arr[i],TriangularMatrixINT->getSize());
								}
								newmat = new TriangularMatrix<int>(reinterpret_cast<Sequence<int> **>(mat),TriangularMatrixINT->getSize(),listORarray);
				    		}
				    		
				    		TriangularMatrixINT->sum_with(*newmat);
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
			    	cout<<"\n0.Complex\n";
			    	cout<<"1.Real\n\n";
			    	cout<<">LinkedList>create>";

					cin>>complexORint;
					while(complexORint != "0" && complexORint != "1") {
							cout<<">LinkedList>create>";
						    cin>>complexORint;
						}
					cout<<"\nList size:";
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

				if (answer == "delete")
				{
					if (complexORint == "0")
					{
						
					}

					if (complexORint == "1")
					{
						LinkedListINT->deleteEllement([](const int& item){
							if (item == 1) {
								return true;
							} else{
								return false;
							}
						});
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
					    	cout<<"\n0.Complex\n";
					    	cout<<"1.Real\n\n";
					    	cout<<">DynamicArray>create>";

							cin>>complexORint;
							while(complexORint != "0" && complexORint != "1") {
									cout<<">DynamicArray>create>";
								    cin>>complexORint;
								}
							cout<<"\nArray size:";
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

				if (answer == "delete")
				{
					if (complexORint == "0")
					{
						
					}

					if (complexORint == "1")
					{
						DynamicArrayINT->deleteEllement([](const int& item){
							if (item == 1) {
								return true;
							} else{
								return false;
							}
						});
					}
				}

				if (answer == "concat")
				{
					int size;
					cout<<"\nSize of new list : ";
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