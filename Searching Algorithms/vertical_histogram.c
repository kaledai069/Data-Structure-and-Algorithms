#include<stdio.h>


int getPlace(int num)
{
    int c;
    c=1;
    while(num!=0)
    {
        num=num/10;
        c=c*10;
    }
    c=c/10;
    return c;
}

int main()
{
    int num,c,result,temp, temp2, i,j,k,max;
    int a[100];
    c=1;
    printf("Enter num");
    scanf("%d", &num);
    temp=num;        
    result = getPlace(num);
	printf("%d\n", result);    
	max = 0;
	
    while(temp != 0)
    {
        temp2 = temp / result;
        printf("%d\n", temp2);
        if(temp2>max)
        {
            max=temp2;
        }
        a[i] = temp2;
        i++;
        temp = temp % result;
        result = result / 10;
	}
	
    for(j=0;j<max;j++)
    {
        for(k=0;k<i;k++)
        {
            if(a[k]>0)
            {
                printf("*");
                a[k]--;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}