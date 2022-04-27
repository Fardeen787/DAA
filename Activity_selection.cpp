#include<bits/stdc++.h>
using namespace std;
#define int long long

//This function is used to compare two times because we want to sort according to their end time whichever end time is less that will be at the first so that we can complete more activity in less time

bool compare(pair<int,int> t1, pair<int,int> t2) {
    if(t1.second == t2.second) {
        t1.first < t2.first;
    }

    return t1.second < t2.second;
}

signed main() {
    int n; cin >> n;    //Taking the number of activity from the user

    vector<pair<int,int>> times;    //storing the start time and end time inside the vector activity inside the pair of vector
    for(int i=0; i<n; i++) {
        int st, fn;
        cin >> st >> fn;

        times.push_back({st,fn});
    }

    sort(times.begin(), times.end(), compare);       //sorting according to the end time of the activity also using the compare function we are comparing the activity

    int ans = 1;                                 //storing the count of the completed activity inside the ans variable
    int previousEndTime = times[0].second;       //Storing the end time of first activity

    for(int i=1; i<n; i++) {                      //In this for loop checking all the activite which can be complete on time
        if(times[i].first >= previousEndTime) {   // Checking start time of new activity is greater then end time of previous activity because then only that activity will not overlap
            ans++;                                  // count
            previousEndTime = times[i].second;   // storing the new activity time so that next activity start time will be greater then previous activity end time
        }
    }

    cout << ans << endl;
    return 0;
}

