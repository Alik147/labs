#include <stdlib.h>
#include <cstdio>
#include <string.h>
typedef struct dynamic_arr
{
	void *value;
	int count;
} dynarr;

void create_dynarr(dynarr* darr, int size){
	char** arr =(char**)malloc(sizeof(char*)*size);
	for (int i = 0; i < size; ++i)
	{
		arr[i] = (char*)malloc(sizeof(char)*256);
	}
	darr->value = (void*)arr;
	darr->count = size;
}

void fill_arr(dynarr* darr){
	char** arr = (char**)darr->value;
	for (int i = 0; i < darr->count; ++i)
	{
		printf("Write %d string:\n",i+1);
		scanf("%s",arr[i]);
	}
	darr->value = (void*)arr;
}
void concatenation(dynarr* darr){
	printf("which lines?\n");
	int a=0,b=0;
	while(a<=0 || a>darr->count || b<=0 || b>darr->count) {
	scanf("%d %d",&a,&b);
	}
	char** arr = (char**)darr->value;
	strcat(arr[a-1],arr[b-1]);
	printf("%s\n",(arr[a-1]));
}

void* some_func1(char* string){
	strcat(string,"BB");
	return (void*)string;
}

void* some_func2(char* string){
	strcat(string,"AA");
	return (void*)string;
}

void* where(bool (*function)(char*),dynarr* darr){
	char** arr = (char**)darr->value;
	char** Answer_arr =(char**)malloc(sizeof(char*)*darr->count);
	int counter = 0;
	for (int i = 0; i < darr->count; ++i)
	{
		if (function(arr[i])==true)
		{
			Answer_arr[counter]=arr[i];
			counter++;
		}
	}
	for (int i = 0; i < counter; ++i)
	{
		printf("%s\n", Answer_arr[i]);
	}
	return (void*)Answer_arr;
}

bool test_isA (char* string){
	if ((char)*string=='A')
	{
		return true;
	} else return  false;
}

void map(void* (*function)(char*), dynarr* darr){
	char** arr = (char**)darr->value;
	for (int i = 0; i < darr->count; ++i)
	{
		arr[i]=(char*)function(arr[i]);
	}
}

void viewarr(dynarr* darr){
	char** arr = (char**)darr->value;
	for (int i = 0; i < darr->count; ++i)
	{
		printf("%s\n", arr[i]);
	}
}

int main()
{
	int n;
	dynarr darr;
	int answer= 0,res;
	bool flag = false;
	while(answer!=5) {
		printf("0 - create array\n");
		printf("1 - map\n");
		printf("2 - where\n");
		printf("3 - view array\n");
		printf("4 - concatenation\n");
		printf("5 - exit\n");
		printf(":");
			do{
				res=scanf("%d",&answer);
				fflush(stdin);
	   			if(res!=1) printf("%s","Invalid input. Try again.\n");
		 	 }
		 	while(res!=1);
  	    if (answer==0)
	    {
	    	printf("input size:\n");
	    	do{
					res=scanf("%d",&n);
					fflush(stdin);
		   			if(res!=1) printf("%s","Invalid input. Try again.\n");
			 }
			 while(res!=1);

			create_dynarr(&darr,n);
			fill_arr(&darr);
			flag=true;
			continue;
	    }
	    if (answer==1 && flag ==true){
	    	printf("add AA(0) or BB(1) ?\n");
	    	int ans;
		    	do{
					res=scanf("%d",&ans);
					 fflush(stdin);
		   			 if(res!=1) printf("%s","Invalid input. Try again.\n");
			 	 }
			 	while(res!=1);

	    	if (ans==0)
	    	{
	    		map((some_func2),&darr);
	    	}
	    	if (ans==1)
	    	{
	    		map((some_func1),&darr);
	    	}
	    	continue;
	    }
	    if (answer==2 && flag ==true){
	    	where((test_isA),&darr);
	    	continue;
	    }
	    if (answer==3 && flag ==true){
	    	viewarr(&darr);
	    	continue;
	    }
	    if (answer==4 && flag ==true){
	    	concatenation(&darr);
	    	continue;
	    }
	    
	}
	
	// scanf("%d",&n);
	// create_dynarr(&darr,n);
	// fill_arr(&darr);
	// char** newarr = (char**)where((isA),&darr);
	// concatenation(&darr);
	// map((func),&darr);
	// viewarr(&darr);
	return 0;
}