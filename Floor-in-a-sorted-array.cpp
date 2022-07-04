/* Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or 
equal to x. Find the floor value of K.
Input: N = 7, x = 0 
       arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So output is "-1".

Input: N = 7, x = 5 
       arr[] = {1,2,8,10,11,12,19}
Output: 2
Explanation: Largest Number less than 5 is 2. */

#include <iostream>
using namespace std;

int floorSearch(int arr[], int low, int high, int x){
    int mid;
    int res;
    
    if (x == 0){
        return -1;
    }
    if(x<arr[0]){
        return -1;
    }
    while(low<=high){
        mid = low + (high-low)/2;
        
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid] < x){
            res = mid;
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return res;
}

int main() {
    int arr[] = { 1, 2, 4, 8, 10, 10, 12, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin >> x;

    cout << "floor of " << x << " is " << floorSearch(arr, 0, n - 1, x) ;
    
    return 0;
}
