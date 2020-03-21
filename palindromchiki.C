#include <stdlib.h>
#include <cstdio>

typedef struct Node
{
	char ch;
	struct Node *next;
} node;

int main(int argc, char const *argv[])
{
	char c;
	node* head = (node*)malloc(sizeof(node)); // list
	node* x = head;
	node* y = head;
	node* head_y = head;
	bool flag = false;
	while ((c = fgetc(stdin)) != EOF) {
		if (c!='\n')
		{
			if (c!=' ')
			{
				if (flag == true){
					head_y = (node*)malloc(sizeof(node));
					head_y->next = y;
					y = head_y;
					y->ch = c;
					x->next = (node*)malloc(sizeof(node));
					x = x->next;
				}
				if (!flag)
				{
					flag=true;
				}
				x->ch = c;
				x->next = 0;
			}
		} else {
			break;
		}
	}
	if (x==head) {
		printf("palindrom\n");
		return 0;
	}
	x=head;
	bool is_pali = true;
	while(y!=head->next) {
	    if (y->ch != x->ch)
	    {
	    	is_pali= false;
	    	break;
	    }
	    y=y->next;
	    x=x->next;
	}
	if (is_pali ==true)
	{
		printf("palindrom\n");
	} else {
		printf("ne palindrom\n");
	}
	return 0;
} 