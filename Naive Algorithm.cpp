#include<bits/stdc++.h>
using namespace std;

bool naive(string text,string pat)
{
    int m=text.size();
    int n=pat.size();
    bool flag;
    for(int i=0;i<=(m-n);i++)
    {
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            if(text[i+j]!=pat[j])
            {
                flag=false;
                break;
            }

        }
        if(flag)
        {
            return true;
        }

    }
        return false;

}


int main()
{
    string text,pat;
    cout<<"\nEnter the Text =";
    cin>>text;
    cout<<"\nEnter the pattern =";
    cin>>pat;

    bool ans=naive(text,pat);
    if(ans==true)
    {
        cout<<"Matched"<<endl;

    }
    else{
        cout<<"Not Matched"<<endl;
    }


}
