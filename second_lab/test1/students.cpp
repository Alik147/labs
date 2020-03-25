#include <iostream>
#include "students.h"
using namespace std;
students::students(){
	size = 50;
	cur_size = -1;
	people = new student[50];
}
void students::add(student some_student){
	people[cur_size+1] = some_student;
	cur_size+=1;
}
void students::view(){
	for (int i = 0; i <= cur_size; ++i)
	{
		cout<<people[i].name<<' '<<people[i].group<<endl;
	}
}
void students::delete_by_name(string name){
	bool flag =false;
	for (int i = 0; i <= cur_size; ++i)
	{
		if (flag == true)
		{

			people[i-1]=people[i];
		}
		if (people[i].name == name && flag ==false)
		{
			flag = true;
		}
	}
	people[cur_size].name = "";
	people[cur_size].group = "";
	cur_size-=1;
}
void students::delete_by_group(string group){
	bool flag =false;
	int counter=0;
	for (int i = 0; i <= cur_size; ++i)
	{
		if (people[i].group == group)
		{
			delete_by_name(people[i].name);
			i--;
		}
	}
}