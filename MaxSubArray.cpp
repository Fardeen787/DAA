#include<bits/stdc++.h>
using namespace std;


int getMaxSubarraySum(int x[],int n)
{
    int maxSubarraySum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int subarraySum=0;
            for(int k=i;k<=j;k++)
            {
                subarraySum=subarraySum+x[k];
            }
            if(subarraySum>maxSubarraySum)
            {
                maxSubarraySum=subarraySum;
            }
        }
    }
    return maxSubarraySum;
}

int main()
{
    int n;
    cout<<"Enter the size of array =";
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    cout<<getMaxSubarraySum(x,n);
}
