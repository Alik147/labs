#include <iostream>
using namespace std;
struct student
	{
		string name;
		string group;
	};
class students
{
private:
	student* people;
	int cur_size;
	int size;
public:
	students();
	void add(student);
	void view();
	void delete_by_group(string);
	void delete_by_name(string);
};