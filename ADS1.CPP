//Merge Sort using C++
#include<stdio.h>
#include<conio.h>
int size,a[100];
void merge(int [],int,int,int);
void mergesort(int [],int,int);
void input();
void display();

void merge(int a[],int lb,int mid,int ub)
{       int i,j,k,n1=mid-lb+1,n2=ub-mid;
	int*l=new int[n1];
	int*r=new int[n2];
	for(i=0;i<n1;i++)
	{	l[i]=a[lb+i];
	}
	for(j=0;j<n2;j++)
	{	r[j]=a[mid+1+j];
	}
	i=0;j=0;k=lb;
	while(i<n1 && j<n2)
	{	if(l[i]<=r[j])
		{ 	a[k]=l[i];
			i++;
		}
		else
		{	a[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{	a[k]=l[i];
		i++;
		k++;
	}
	while(j<n2)
	{ 	a[k]=r[j];
		j++;
		k++;
	}
	delete[] l;
	delete[] r;
}
void mergesort(int a[],int lb,int ub)
{       int mid;
	if(lb>=ub)
	{	return;
	}
	else
	{	mid=(lb+ub)/2;
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
void input()
{	int i;
	printf("Enter number elements to be stored in the array:");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{	printf("%d array element:",i+1);
		scanf("%d",&a[i]);
	}
}
void display()
{	int i;
	for(i=0;i<size;i++)
	{	printf("%d ",a[i]);
	}
}
void main()
{	int lb,mid,ub,i;
	clrscr();
	input();
	lb=0;
	ub=size-1;
	mergesort(a,lb,ub);
	display();
	getch();
}