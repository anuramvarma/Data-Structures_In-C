#include<stdio.h>
void sort(int a[],int n)
{
	int i,temp,j;
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<n-i-1;++j)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	int mid,end,start=0,i,n,a[50],key;
	printf("enter a size of the array");
	  scanf("%d",&n);
	printf("enter a key");
	  scanf("%d",&key);
	printf("enter a elements");
	for(i=0;i<n;++i)
	{	
	  scanf("%d",&a[i]);
	}
	sort(a,n);
	printf("storted array=");
	for(i=0;i<n;++i)
	  {
	    printf("%d ",a[i]);
	  }
	end=n-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(key==a[mid])
		{
		  printf("\nkey found at %d",mid+1);
		  break;
	        }
else if(key<a[mid])
 {
  end=mid-1;
 }
else if(key>a[mid])
  {
    start=mid;
  }
else
  {
   printf("element not found");
   return 0;
  }
	}
return 0;
}
