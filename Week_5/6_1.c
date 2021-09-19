#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long int countSetBits(long long int n)
{
    long long int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}
long long int ncr[65][65];
void precomp()
{
	int i,j;
	for(i=1;i<=64;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||j==i)
			{
				ncr[i][j]=1;
			}
			else
			{
				ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
			}
		}
	}
}
long long int find(long long int n,long long int k)
{
	long long int m,msb,i,j,l,ans;
	if(n==1&&k==1)
	{
		return 1;
	}
	if(k==0||n==0)
	{
		return 0;
	}
	msb=log2(n);
	//printf("n=%lld k=%lld msb=%lld\n",n,k,msb);
	if(k>msb+1)
	{
		return 0;
	}
	else
	{
		if(k==1)
		{
			ans=ncr[msb][k]+1;
		}
		else
		{
			ans=ncr[msb][k];
		}
		return (ans+find(n&((long long int)pow(2,msb)-1),k-1));
	}
}
long long int search(long long int m,long long int k)
{
	long long int low=0,high=1000000000000000000;
	long long int mid;
	while(low<high)
	{
		mid=(low+high)/2;
		long long int count;
		printf("low:%lld %lld",low,mid);
	
		count=(find(2*mid,k)-find(mid,k));
		
			
		if(count<m)
		{
			low=mid+1;
		}
		else
		{
			printf(" CORRECT: %lld:\n",mid);
			high=mid;
		}
		printf("\n");
	}
	return low;
}

int main(int argc, char *argv[]) 
{
	long long int i,j,m,k;
	precomp();
	scanf("%lld",&m);
	scanf("%lld",&k);
	printf("%lld\n",search(m,k));
	printf("%lld\n",find(8,2));
	printf("\n ANS:%lld\n",search(m,k));



	// long long int n=167167411424854017;
	// printf("%lld\n",find(n,13));
	// printf("%lld\n",find(2*n,13));
	// long long int count=0;
	// while(n!=0){
	// 	printf("%d\n",n%2);
	// 	n=n/2;
	// }
	return 0;
}

