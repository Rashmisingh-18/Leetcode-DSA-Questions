/* Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x, and the floor is the greatest element smaller than 
or equal to x. Assume that the array is sorted in non-decreasing order. Write efficient functions to find the floor and ceiling of x.

Input: arr = {1, 2, 4, 8, 10, 10, 12, 19}
       x = 5
Output: 8
  
Here, binary search is implemented, as sorted array given */

#include <bits/stdc++.h>
using namespace std;

int ceilSearch(int arr[], int low, int high, int x){

    int mid;
    int res = 0;

    while(low <= high){
        mid = low + (high - low)/2;
        if(arr[mid] == x){
            return arr[mid];
        }
        else if(x > arr[mid]){
            low = mid+1;           
        }
        else{
            res = arr[mid];
            high = mid-1;
        }
    }
    return res;
}

int main() {
    int arr[] = { 1, 2, 4, 8, 10, 10, 12, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin >> x;
    if(x > arr[n-1]){
        cout << "Element not present in array" << endl;
    }
    else{
        cout << "ceiling of " << x << " is " << ceilSearch(arr, 0, n - 1, x) ;
    }
    return 0;
}
