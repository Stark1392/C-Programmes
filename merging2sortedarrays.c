#include<stdio.h>

void sort(int x[],int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            int temp = x[i];
            x[i]=x[i+1];
            x[i+1]=temp;
        }
    }
}

void merge(int x[],int y[],int m,int n)
{

}

int main()
{
    int m,n;
    printf("Enter the size of the 1st array : ");
    scanf("%d",&m);

    printf("Enter the size of the 2nd array : ");
    scanf("%d",&n);

    int a[m],b[n],c[m+n];

    for(int i=0;i<m;i++)
    {
        printf("a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("a[%d] : ",i);
        scanf("%d",&b[i]);
    }

    sort(a,m);
    sort(b,n);



    return 0;
}
