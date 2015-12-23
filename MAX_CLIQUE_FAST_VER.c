#include <stdio.h>
#include <stdlib.h>

#define MAX 70

typedef unsigned long long int ULLT;

int ans = 0;
int book[MAX][MAX];

ULLT add_set(ULLT set, int input)
{
    return set|(1uLL<<input);
}

int count_set(ULLT set)
{
    int count = 0;
    while(set>0)
    {
        if(set&1)   count++;
        set>>=1;
    }
    return count;
}

void clique(int arr_size,int crr_position,ULLT set)
{
    int i ,j;
    int flag = 1;
    ULLT test_set;
    int count = 0;
    if(arr_size==crr_position)
    {
        count = count_set(set);
        if(count > ans) ans = count;
        return 1;
    }

    test_set = add_set(set,crr_position);

    for(i=0;i<arr_size;i++)
    {
        for(j=i+1;j<arr_size;j++)
        {
            if(book[i][j]==0 && ((1uLL<<i)&test_set)!=0 && ((1uLL<<j)&test_set)!=0)
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag==0)
    {
        clique(arr_size,crr_position+1,set);
    }
    else        //Undet
    {
        clique(arr_size,crr_position+1,set);
        clique(arr_size,crr_position+1,test_set);
    }

}

int main(void)
{
    int n;
    int i , j;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)    return 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&book[i][j]);
            }
        }
        clique(n,0,0uLL);
        printf("%d\n",ans);
    }
    return 0;
}
