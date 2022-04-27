#include <bits/stdc++.h>
using namespace std;


class Solution
{

public:
    int CoinChange(int coins[], int n, int sum)
	{


	    int dp[n+1][sum+1];
	    for(int i=0;i<sum+1;i++)
	    {
	        dp[0][i]=INT_MAX-1;
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        dp[i][0]=0;
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<sum+1;j++)
	        {
	            if(coins[i-1]<=j)
	            {
	                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    if(dp[n][sum]==INT_MAX-1)
	    {
	        return -1;
	    }

	    return dp[n][sum];
	}
    int CoinChange_greedy(int v[],int n,int val)
    {
        vector<int> ans;
        for(int i=n-1; i>=0; i--)
        {
            while(val>=v[i])
            {
                val-=v[i];
                ans.push_back(v[i]);
            }
        }
        int count=0;
        for(int i=0; i<ans.size(); i++)
        {
            count++;
        }
        return count;
    }


};

int main()
{
    Solution sp;
    int coins[]= {1,2,5,10,50,100,200};
    int n=sizeof(coins)/sizeof(coins[0]);
    int choice;
    while(1)
    {

    int sum=0;
    cout<<"Enter the sum= ";
    cin>>sum;

    cout<<"Enter your choice";
    cout<<"\n1.DP Coin Change";
    cout<<"\n2.Greedy Coin Change";
    cout<<"\n0.Exit"<<endl;
    cin>>choice;
    if(choice==1)
    {
      cout<<sp.CoinChange(coins,n,sum)<<endl;
    }
    else if(choice==2)
    {
         cout<<sp.CoinChange_greedy(coins,n,sum)<<endl;
    }


    }


}
