#include <stdio.h>
#include <conio.h>
void nhapmang(int a[],int &n)
{
	int i;
	printf ("nhap so phan tu: ");
	scanf ("%d",&n);
	for(i=0;i<n;i++)
	{
		printf  ("\na[%d]: ",i);
		scanf ("%d",&a[i]);
	}
}
void inmang (int a[],int n)
{
	int i;
	for (i=0;i<n;i++)
		printf ("\n%d",a[i]);
	printf("\n");
}
void sapxep( int a[],int n)
{
	int i,j;
	float tg;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			if (a[i]>a[j])
			{
				tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
}
int main()
{
	int n,b[20];
	nhapmang(b,n);
	inmang(b,n);
	sapxep(b,n);
	printf ("\nmang da sap xep: ");
	inmang(b,n);
}
