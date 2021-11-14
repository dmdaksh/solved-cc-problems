
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
	return a>=b?a:b;
}

int main()
{

	int n;
	scanf("%d",&n);
	//int pb[76] = {0};
	int dp[76] = {0};
	for(int i=1;i<=6 ; ++i)
	{
		dp[i-1] = i;
	}


	int curr;
	for(int i=7;i <=75 ;++i)
	{
		curr = 0;
		int c =2;
		for(int j=i-3; j>=1 ; --j)
		{
			dp[i-1] = max(c*dp[j-1],dp[i-1]);
			c++;
		}
		if(i==n)
			break;
		

	}

	
	printf("%d\n",dp[n-1] );
}
