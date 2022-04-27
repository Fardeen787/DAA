#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r, int size)
{
    int i = l;         //storing the left index
    int j = m + 1;     //storing the right index
    int k = l;           //storing the k index for temp variable


    int temp[size];

    while (i <= m && j <= r) {       //till left smaller then mid and mid < then right we compare
        if (arr[i] <= arr[j]) {      //if then push the left element indside the temp arr else right element will be push inside the temp array
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= m) {              //
        temp[k] = arr[i];
        i++;
        k++;
    }


    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }


    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r) {

        int m = (l + r) / 2;


        mergeSort(arr, l, m, size);        //calling from left to mid
        mergeSort(arr, m + 1, r, size);    //calling from mid to right


        merge(arr, l, m, r, size);     //merging the two array
    }
}


int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for(int i = s; i<e; i++)
    {
        if(arr[i]<pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if(s<e)
    {
        int p = Partition(arr,s, e);
        QuickSort(arr, s, (p-1));  // recursive QS call for left partition
        QuickSort(arr, (p+1), e);  // recursive QS call for right partition
    }
}


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int Partition1(int arr[], int l, int r)
{
    int lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}


int randomPartition(int arr[], int l,
                    int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return Partition1(arr, l, r);
}

// Utility function to find median
void MedianUtil(int arr[], int l, int r,
                int k, int& a, int& b)
{

    // if l < r
    if (l <= r) {

        // Find the partition index
        int partitionIndex
            = randomPartition(arr, l, r);

        // If partition index = k, then
        // we found the median of odd
        // number element in arr[]
        if (partitionIndex == k) {
            b = arr[partitionIndex];
            if (a != -1)
                return;
        }


        else if (partitionIndex == k - 1) {
            a = arr[partitionIndex];
            if (b != -1)
                return;
        }


        if (partitionIndex >= k)
            return MedianUtil(arr, l,
                              partitionIndex - 1,
                              k, a, b);


        else
            return MedianUtil(arr,
                              partitionIndex + 1,
                              r, k, a, b);
    }

    return;
}


void findMedian(int arr[], int n)
{
    int ans, a = -1, b = -1;


    if (n % 2 == 1) {
        MedianUtil(arr, 0, n - 1,
                   n / 2, a, b);
        ans = b;
    }


    else {
        MedianUtil(arr, 0, n - 1,
                   n / 2, a, b);
        ans = (a + b) / 2;
    }


    //cout << "Median = " << ans;
}



int main()
{
   int a[]={100,500,1000,1500,2000,2500,3000};
   int T=sizeof(a)/sizeof(a[0]);
   int i=0;
   while(T--)
   {
    int size=a[i];
    //cout << "Enter size of array: " << endl;
    int myarray[size];

    for(int i = 0; i < size; i++)
    {
	    myarray[i] = rand() % 5000;

    }
    //cout << "Before Sorting" << endl;
    //for (int i = 0; i < size; i++) {
     //   cout << myarray[i] << " ";
    //}
    cout << endl;
    auto start = high_resolution_clock::now();
    mergeSort(myarray, 0, (size - 1), size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    auto start1 = high_resolution_clock::now();
    QuickSort(myarray,0,(size-1));
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    //cout << "After Sorting" << endl;
    //for (int i = 0; i < size; i++) {
     //   cout << myarray[i] << " ";
    //}
     auto start2 = high_resolution_clock::now();
     findMedian(myarray, size);
     auto stop2 = high_resolution_clock::now();
     auto duration2 = duration_cast<microseconds>(stop2 - start2);
     cout<<"\nTime taken by Merge Sort when array size is "<<a[i]<< " time is= " <<duration.count()<<" microseconds"<<endl;
     cout<<"\nTime taken by Quick Sort when array size is "<<a[i]<< " time is= " <<duration1.count()<<" microseconds"<<endl;
     cout<<"\nTime taken by Quick Sort by median when array size is "<<a[i]<< " time is= " <<duration2.count()<<" microseconds"<<endl;
     i++;
   }

    return 0;
}
