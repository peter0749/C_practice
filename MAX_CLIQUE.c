#include <stdio.h>
#include <stdlib.h>

#define MAX 70

typedef unsigned long long int ULT;

int clique(int arr_size, short arr[][MAX])
{
	ULT row[MAX] = {0};
	ULT mask = 0;
	ULT bk;
	int count = 0;
	int max = 0;
	int mask_count;
	int i ,j;
	for(i=0; i<arr_size; i++)
	{
		arr[i][i] = 1;
		row[i] = 0;
		for(j=0; j<arr_size; j++)
		{
			row[i]<<=1;
			row[i]+=(ULT)arr[i][j];
		}
		//printf("%llu\n",row[i]);
	}
	while(mask < 1uLL<<arr_size)
	{
		bk = mask;
		mask_count = 0;

		while(bk>0)
		{
			if(bk&1uLL)
			{
				mask_count++;
			}
			bk>>=1uLL;
		}
		//printf("%llu %d\n",mask,mask_count);
		count = 0;
		for(i=0; i<arr_size; i++)
		{
			if((row[i]&mask)==mask)
			{
				//if(i==9)    puts("NO");
				//if(i==9)    printf("%llu\n",row[i]);
				count++;
				if(count==mask_count)
				{
					if(mask_count>max)
						max = mask_count;
					break;
				}
			}

		}
		mask++;
	}
	return max;
}

int main(void)
{
	//freopen("clique63.in","r",stdin);
	int arr_size;
	short arr[MAX][MAX];
	int i, j;
	ULT set = 0;
	while(1)
	{
		scanf("%d",&arr_size);
		if(arr_size==0) return 0;
		for(i=0; i<arr_size; i++) for(j=0; j<arr_size; j++)
			scanf("%hd",&arr[i][j]);
		printf("%d\n",clique(arr_size,arr));
	}

	return 0;
}

