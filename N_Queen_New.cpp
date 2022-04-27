#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr,int x,int y,int n)   //THis function is used to check if there is any queen in that column or in row and also checking at its diagonaly
{
    for(int row=0; row<x; row++)      //checking in the row if any queen present or not
    {
        if(arr[row][y]==1)
        {
            return false;
        }
    }

    int row=x;
    int col=y;
    while(row>=0 && col>=0)          //checking diagonaly left if any queen present or not
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n)           //checking diagonaly right if any queen present or not
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** arr,int x,int n)
{
    if(x>=n)                 //If all queen push then will return true
    {
        return true;
    }
    for(int col=0; col<n; col++)   //Adding queen 1 by in different column and check if they placed right or not
    {
        if(isSafe(arr,x,col,n)) //here checking if we put the their is it safe or not
        {
            arr[x][col]=1;         //Adding one to that safe place
            if(nQueen(arr,x+1,n))   // Now calling the function for next row
            {
                return true;
            }
            arr[x][col]=0;     //Backtracking when the condition not satisfied
        }

    }
    return false;

}


int main()
{
   int n;
   cout<<"Enter the number of queens= ";
   cin>>n;
   int** arr=new int*[n];
   for(int i=0;i<n;i++)     //Filling the 2D array with 0
   {
       arr[i]=new int[n];
       for(int j=0;j<n;j++)
       {
           arr[i][j]=0;
       }
   }

   if(nQueen(arr,0,n)){

      for(int i=0;i<n;i++)              //Printing the safe
      {

          for(int j=0;j<n;j++)
          {
              cout<<arr[i][j]<<" ";

          }cout<<endl;
      }

   }

}
