/*
 ============================================================================
 Name        : HeapSort2.c
 Author      : Raghu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void adjust();
void heap_sort();
void heapify();
void display();
int a[20],r;
void main()
{
        int n,i;
        printf("\nenter the size of array:");
        scanf("%d",&n);
        r=n;
        printf("\nenter the elements\n");
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        heap_sort(n);
        printf("\n After Sorting :\n");
        display(a);
}
void display(int a[])
{
        int i;
        for(i=1;i<=r;i++)
        {
                printf("%d\t",a[i]);

        }
}
void heap_sort(int n)
{
        int i,t;
        heapify(n);
        printf("\nAfter heapify\n");
        display(a);
        for(i=n;i>1;i--)
        {
                t=a[1];
                a[1]=a[i];
                a[i]=t;
                adjust(1,i-1);
                printf("After heapify\n");
                display(a);
        }
}
void heapify(int n)
{
        int i;
        for(i=(n/2);i>=1;i--)
                adjust(i,n);
}
void adjust(int i,int n)
{
        int item,j;
        j=2*i;
        item=a[i];
        while(j<=n)
        {
                if(j<n && (a[j]<a[j+1]))
                        j++;
                if(item>=a[j])
                        break;
                a[j/2]=a[j];
                j=2*j;
        }
        a[j/2]=item;

}
