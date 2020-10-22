#include <stdlib.h>
#include <ctime>
#include <cstdio>
void insert(int *arr, int n){
	int i, box, j; 
    for (i = 1; i < n; i++) { 
        box = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] >box) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = box; 
    } 
}
void binar(int *arr, int n, int a){
	int start=0,end=n-1,box;
	while(abs(start-end)!=0){
			if (arr[(start+end)/2]<a)
			{
				start=(start+end)/2;
			}
			if (arr[(start+end)/2]>a)
			{
				end=(start+end)/2;
			}
			if (arr[(start+end)/2]==a){
				printf("%d\n",(start+end)/2 );
				break;
			}printf("netu takih\n");
	}
}

void binar_rec(int start, int end, int* arr ,int a)
{
	int center = (start+end)/2;
	if (abs(end -start)>0)
	{
			if (arr[center]<a)
			{
				start=(start+end)/2;
				binar_rec(start,end,arr,a);
			}

			if (arr[center]>a)
			{
				end=(start+end)/2;
				binar_rec(start,end,arr,a);
			}
	}
			if (arr[center]==a){
				printf("%d\n",center);
			}
}

int main()
{
	int n;
	printf("%s\n", "size:");
	scanf("%d",&n);
	int *arr;
	printf("\n");
	arr=(int*)malloc(n*sizeof(int));
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		arr[i]=rand()%10;
		printf("%d ", arr[i]);
	}
	printf("\n");
	insert(arr,n);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\nfind?");
	int a;
	scanf("%d",&a);
	// binar(arr,n,a);
	binar_rec(0,n-1,arr,a);
	free(arr);
	return 0;
}