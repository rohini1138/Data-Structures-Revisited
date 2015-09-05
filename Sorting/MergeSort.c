#include <stdio.h>

//Uncomment to test and find logic of program

void mergesort(int A[],int low,int mid,int high)
{
	int mi = mid +1 ;
	int temp[50];
	int lo = low;
	int hi = high;
	int k;

	int i = low;

	while((lo<=mid) && (mi<=hi))
	{
	         printf("\nwhile\n");
		if(A[lo] <= A[mi])
		{
			temp[i]=A[lo];
			lo++;
		}
		else
		{
			temp[i]=A[mi];
			mi++;
		}
		i++;
	}

	if(lo > mid)
	{
	        //printf("\nif(lo > mid)\n");
		for(k=mi;k<=high;k++)
		{
			temp[i]=A[k];
			i++;
		}
	}
	else
	{
	        //printf("\nelse\n");
		for(k=lo;k<=high;k++)
        	{
			temp[i]=A[k];
		        i++;
        	}
	}

	for (k = low; k <= high; k++)
	{
	        A[k] = temp[k];
	}
}


void partition(int A[],int low,int high)
{
	int mid,i;
	if(low < high)
	{
		mid =(low+high)/2;
		//printf("\n\npartition(A,low,mid);\n\n");
		//printf("%d %d %d %d %d %d %d %d",A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7],A[8]);
		partition(A,low,mid);
		//printf("\n\npartition(A,mid+1,high);\n\n");
		//printf("%d %d %d %d %d %d %d %d",A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7],A[8]);
		partition(A,mid+1,high);
		//printf("\n\nSORT\n\n");
		//printf("%d %d %d %d %d %d %d %d",A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7],A[8]);
		mergesort(A,low,mid,high);
	}
}


int main()
{
	int i,A[]={6,5,1,3,9,4,2,7};
	int size=8;
	partition(A,0,size-1);
	for(i=0;i<8;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
