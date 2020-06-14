#include "node.cpp"
#include "tree.cpp"
#include "complex.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
	string intORcomplex;
	Tree<int> treeINT;
	Tree<complex> treeCOMPLEX;
	cout<<"Welcome to LAB3 :)\n";
	string answer = "";
	cout<<">";
	cin>>answer;
	while(answer != "exit") {
		if (answer == "create")
		{
			cout<<"1. int\n"<<"2. complex\n";
			cin>>answer;
			while(answer != "1" && answer != "2") {
			    cin>>answer;
			}
			intORcomplex = answer;
			if (answer == "1")
			{
				int a;
				cout<<"treeINT>root_value: ";
				cin>>a;
				treeINT.getRoot()->setValue(a);
				cout<<"Tree <int> successfully created with "<<a<<" value in root\n";
			}
			if (answer == "2")
			{
				int a,b;
				cout<<"treeCOMPLEX>root_value([a]+[b]i): ";
				cin>>a>>b;
				treeCOMPLEX.getRoot()->setValue(complex(a,b));
				cout<<"Tree <complex> successfully created with "<<complex(a,b)<<" value in root\n";
			}
		}
		if (answer == "insertNode")
		{
			if (intORcomplex == "1")
	    	{
				int a;
				cout<<"treeINT>value: ";
				cin>>a;
				treeINT.InsertNewNode(a);

	    	}
	    	if (intORcomplex == "2")
	    	{
				int a,b;
				cout<<"treeCOMPLEX>value([a]+[b]i): ";
				cin>>a>>b;
				treeCOMPLEX.InsertNewNode(complex(a,b));
	    	}
					}
	    cout<<">";
	    cin>>answer;
	    if (answer == "map")
	    {
	    	if (intORcomplex == "1")
	    	{
	    		treeINT.map_([](int elem){ return elem*10 ;}, treeINT.getRoot());
	    	}
	    	if (intORcomplex == "2")
	    	{
	    		treeCOMPLEX.map_([](complex elem){ return elem*10 ;}, treeCOMPLEX.getRoot());
	    	}
	    }
	    if (answer == "height")
	    {
	    	if (intORcomplex == "1")
	    	{
	    		cout<<treeINT.height(treeINT.getRoot())<<endl;
	    	}
	    	if (intORcomplex == "2")
	    	{
	    		cout<<treeCOMPLEX.height(treeCOMPLEX.getRoot())<<endl;
	       	}
	    }
	    if (answer == "delete")
	    {
	    	if (intORcomplex == "1")
	    	{
	    		cout<<"treeINT>del_by_value:";
	    		int a;
	    		cin>>a;
	    		treeINT.deleteNode(a,treeINT.getRoot());
	    	}
	    	if (intORcomplex == "2")
	    	{
	    		cout<<"treeCOMPLEX>del_by_value([a]+[b]i):";
	    		int a,b;
	    		cin>>a>>b;
	    		treeCOMPLEX.deleteNode(complex(a,b), treeCOMPLEX.getRoot());
	       	}
	    }

	}
	return 0;
}
