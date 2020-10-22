#include <stdlib.h>
#include <cstdio>
#include <ctype.h>
typedef struct Node
{
	char ch;
	struct Node *next;
} node;

void rec(node* head, int* is_pali, node** x) {
	
	if (head->next != 0)
	{
		rec(head->next,is_pali,x);
	}
	node* box = *x;
	if (toupper(box->ch) != toupper(head->ch))
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
	while ((c = fgetc(stdin)) != '\n') {
		
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