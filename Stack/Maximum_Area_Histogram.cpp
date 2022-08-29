// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all 
// bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.
  
// Input:
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12


#include<bits/stdc++.h>
using namespace std;

vector<long long> nearest_left(long long int* arr,int n){
       vector<long long> left;
       stack< pair<long long,long long>> s;
       for(int i=0;i<n;i++){
           while(!s.empty() && s.top().first>=arr[i]){
               s.pop();
           }
           if(s.empty()){
               left.push_back(-1);
           }
           else{
               left.push_back(s.top().second);
           }
           s.push({arr[i],i});
       }
      return left;
  }
  
  vector<long long> nearest_right(long long int* arr,int n){
       vector<long long> right;
       stack< pair<long long,long long>> s;
       for(int i=n-1;i>=0;i--){
           while(!s.empty() && s.top().first>=arr[i]){
               s.pop();
           }
           if(s.empty()){
               right.push_back(n);
           }
           else{
               right.push_back(s.top().second);
           }
           s.push({arr[i],i});
       }
      reverse(right.begin(),right.end());
      return right;
  }
  
  long long getMaxArea(long long arr[], int n){
      vector<long long> left;
      vector<long long> right;
      left = nearest_left(arr,n);
      right = nearest_right(arr,n);
      
      long long area = INT_MIN;
      for(int i=0;i<n;i++){
           long long temp = (right[i]-left[i]-1)*arr[i];
           area = max(area, temp);
      }
      return area;
  }
int main(){
    long long hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << getMaxArea(hist, n) << endl;
    return 0;
}
