#include "students.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
	string ans;
	students obj;
	getline(cin,ans);
	while(ans != "end") {
	    if (ans == "add")
	    {
		    student someone;
		    cout<<"name:"<<endl;
			getline(cin,someone.name);
			cout<<"group:"<<endl;
			getline(cin,someone.group);
			obj.add(someone);
	    }
	    if (ans == "view")
	    {
	    	obj.view();
	    }
	    if (ans == "del by name")
	    {
	    	string name;
	    	cout<<"name:"<<endl;
	    	getline(cin,name);
	    	obj.delete_by_name(name);
	    }
	    if (ans == "del by group")
	    {
	    	string group;
	    	cout<<"group:"<<endl;
	    	getline(cin,group);
	    	obj.delete_by_group(group);
	    }
	    getline(cin,ans);
	}
	return 0;
}