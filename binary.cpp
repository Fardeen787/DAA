#include <iostream>
#include<math.h>
#include <stdlib.h>

using namespace std;

int main()
{
        int a[1000],no,i,key,mid,temp;					//for 1000 array size
		bool found=false;
		cout<<"Enter number of elements:-";
		cin>>no;
		for(int i=0;i<no;i++)
		{
		   	a[i]=rand()%1000;
		}

		cout<<"Elements in Array:-\n";
		for(int i=0;i<no;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<"\nElements in Array(Sorted):-\n";
		for(int i=0; i<no; i++)
		{
			for(int j=i+1; j<no; j++)
			{
			    if(a[j] <a[i])
			    {
			        temp = a[i];
			        a[i] = a[j];
			        a[j] = temp;
			    }
			}
			cout<<a[i]<<" ";
		}

		cout<<"\nEnter element to be searched :";
		cin>>key;

		int first=0,last=no-1;

		while(first<=last)
		{
		    mid= (first+last)/2;

		    if(a[mid]==key)
		    {
		        found=true;
		        break;
		    }
		    else if(a[mid]<key)
		    {
		        first=mid+1;        //move to right if Larger values
		    }
		    else
		    {
		        last= mid-1;        //move to left if  Smaller values
		    }
	    }

		if(found)
		{
		    cout<<"Element found at position "<<mid;
		}
		else
		{
		    cout<<"Element not found";
	    }

      return 0;
}
