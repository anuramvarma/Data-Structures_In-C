//Sorting Techinques
#include<stdio.h>
void Read(int [],int );
void print(int [],int );
void selection(int [],int );
void insertion(int [],int );
void swap(int *,int*);
    void Read(int a[],int n)
     {
        int i;
        for(i=0;i<n;i++)
        {
          scanf("%d",&a[i]);
        }
      }       
    void print(int a[],int n)
{
        int i;
        for( i=0;i<n;i++)
           printf("%d\t", a[i]);        
}   
    void insertion(int a[],int n)
{
         int i,j,key;
         for(i=1;i<n;i++)
         {
            key=a[i];
            j=i-1;
            
            while(j>=0&&a[j]>key)
            {
                 a[j+1]=a[j];
                 j--;
             }
               a[j+1]=key;
                
         }
}
  void swap(int *x,int *y)
{
       int temp=*x;
       *x=*y;
       *y=temp;
    }
      int main()
      {
       int n,i;
      
      printf("enter the size of an array");
      scanf("%d",&n);
      int a[n];
      printf("enter the %d elements",n);
      Read(a,n);
       /*for(i=0;i<n;i++)
       {
          scanf("%d",&a[i]);
          }*/
      printf("Before sorting\n");
      print(a,n);
      insertion(a,n);
      printf("\nAfter sorting\n");
      print(a,n);
      return 0;
      }
