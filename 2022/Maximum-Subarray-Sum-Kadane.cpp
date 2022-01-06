#include <bits/stdc++.h>
using namespace std;

// Keep track of the ongoing max sum, and actual max sum overall

int maxSubSumKadane(vector<int> arr){   
    int maxTotal = arr[0], maxOngoing = arr[0];
    for(int i=0; i<arr.size(); i++){
        maxTotal = max(arr[i], maxTotal+arr[i]);
        maxOngoing = max(maxTotal, maxOngoing);
    }
    return maxOngoing;
}

void printSubarray(vector<int> arr){
    int maxTotal = INT_MIN, maxOngoing = 0, f = 0, l = 0, index = 0;
    for(int i=0; i<arr.size(); i++){
        maxOngoing+=arr[i];
        if (maxTotal < maxOngoing){
            maxTotal = maxOngoing;
            f = index;
            l = i;
        }
        if (maxOngoing < 0){
            maxOngoing = 0;
            index = i+1;
        }
    }
    cout<<"MAX SUM : "<<maxTotal<<endl;
    cout<<"Range : "<<f<<" to "<<l;
}

int main()
{


    vector<int> arr{-2, -3, 4, -1, -2, 1, 5, -3};

    cout<<maxSubSumKadane(arr)<<endl;
    printSubarray(arr);

    return 0;
}