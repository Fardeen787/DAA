
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of person ";
    cin>>n;
    vector<vector<int>> v;
    for(int i=0; i<n; i++)
    {
        int start,end;
        cout<<"Enter start time and end time of cab ";
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b)
    {
        return a[1] < b[1];
    });
    int take = 1;
    int end = v[0][1];
    for (int i= 1; i<n; i++)
        if(v[i][0]>=end)
        {
            take++;
            end = v[i][1];
        }
    cout<<"Minimum number of cab requried \n"<<take;
}
