#include <stdlib.h>
#include <cstdio>

typedef struct Node
{
	char ch;
	struct Node *next;
} node;

void rec(node* head, int* is_pali,node** x) {
	
	if (head->next != 0)
	{
		rec(head->next,is_pali,x);
	}
	node* box = *x;
	if (box->ch != head->ch)
	{
		*is_pali = 0;
	}
	*x = box->next;
}
int main(int argc, char const *argv[])
{
	char c;
	node* head = (node*)malloc(sizeof(node)); // list
	node* x = head;
	bool flag = false;
	while ((c = fgetc(stdin)) != EOF) {
		if (c!='\n')
		{
			if (c!=' ')
			{
				if (flag == true){
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
	int is_pali = 1;
	rec(head,&is_pali, &head);
	if (is_pali==0)
	{
		printf("Ne palindrom\n");
	} else {
		printf("Palindrom\n");
	}
}