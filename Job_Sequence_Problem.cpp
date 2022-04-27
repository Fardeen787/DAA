#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job
struct Job {
   int id; // Job Id
   int dead; // Deadline of job
   int profit; // Profit if job is over before or on deadline
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {        //This function is used to compare two jobs profit to return maximum profit
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);       //SOrt according to their profit so that will get maxi mum profit first
      int maxi = arr[0].dead;               //storing the first dedline inside the  maxi varible
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);     //sotring the max deadline in  maxi to make the array
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)    //intialize all with -1
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;    //one variable is used to count the job and another one is used to store the profit

      for (int i = 0; i < n; i++) {                             //This will loop will run till the number of jobs
         for (int j = arr[i].dead; j > 0; j--) {  // This loop run from the deadline of the job and subtracting till it get a postion which is empty
            if (slot[j] == -1) {
               slot[j] = i;                          //This slot will store the index of that value so that next time any other job will not take that position
               countJobs++;                         //Counting the number of job completed
               jobProfit += arr[i].profit;         //storing the profit
               break;                                // It will imediately break if any job got the place
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
}
