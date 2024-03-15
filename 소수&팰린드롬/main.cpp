#include <stdio.h>
#include <list>

int main()
{
    int N, j;
    int i=1;
    int count=1;
    char* numstr[8];
    int* pnum;
    scanf("%d",&N);
    if(N<=11)
        printf("11\n");
    pnum=new int[N];
    pnum[1]=2;
    while(1)
    {
        if(i>N)
            break;
        for(j=1; j<count; j++) //현재 i가 소수인지 아닌지 판별
        {                      //여태까지의 모든 소수로 나눠본다.
            if(i%pnum[j]==0)
                break;
        }
        if(j==count)
        {
            count++;
            pnum[count]=i;
        }
        i=i+2;
    }
}