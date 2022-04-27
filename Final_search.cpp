#include<bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std :: chrono;


int BinarySearch(int arr[], int num, int beg, int end)
{

 int mid;

 if (beg > end){

  return 0;

 } else {

  mid = (beg + end) / 2;

  if(arr[mid] == num){


   return 0;

  } else if (num > arr[mid]) {

   BinarySearch (arr, num, mid+1, end);

  } else if (num < arr[mid]) {

   BinarySearch (arr, num, beg , mid-1);
  }
 }

}

void linear_search(int myarr[],int n,int num)
{
    bool flag=0;
    for(int i=0;i<n;i++)
  {
      if(myarr[i]==num)
      {

          flag=1;
          break;
      }

  }
  if(flag==0)
  {

  }

}

int binarySearch_w(int arr[], int left, int right, int x) {


    int output=-1;


  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
      output=mid;
      break;
    } else if (arr[mid] < x) {
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }



  if (output == -1)
   {
    cout << "No Match Found" << endl;
  }
  else {
    cout << "Match found at position: " << output << endl;
  }

}





int main()
{


  int a[]={100,200,300,400,500};
  int T=sizeof(a)/sizeof(a[0]);
  int i=0;
  while(T--)

  {

  int num,arr[100];
  bool flag=0;
  int n=a[i];
  int myarr[n];
  cout << "Randomly store elements" << endl;
  for (int i = 0; i < n ;i++) {
    myarr[i]=rand()%1000;
  }


  sort(myarr,myarr+n);

  for(int i=0;i<n;i++)
  {
      cout<<myarr[i]<<" ";
  }
  cout<<endl;
  cout<<"Please enter an element to search"<<endl;
  cin>>num;


    auto start3 = high_resolution_clock::now();
    binarySearch_w(myarr,0,n,num);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "\n\nTime taken By Binary Search Without Recusrsion: " << duration3.count() << " microseconds" << endl;

    auto start1 = high_resolution_clock::now();
    BinarySearch(myarr,num,0,n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "\n\nTime taken By Recursive Binary Search: " << duration1.count() << " microseconds" << endl;

    auto start2 = high_resolution_clock::now();
    linear_search(myarr,n,num);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "\n\nTime taken By Linear Search: " << duration2.count() << " microseconds" << endl;
    cout<<"\n";
    i++;

  }




}
