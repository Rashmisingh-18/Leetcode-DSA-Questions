
#include <bits/stdc++.h>
using namespace std;

vector<int>nextSmallerToRight(long long arr[], int n){
    vector<long long>ans;
    stack<long long> s;
    for(int i=n-1; i>=0; i--){
        if(s.size()==0){
            ans.push_back(-1);
        }
        else if(s.size()>0 && arr[i]>s.top()){
            ans.push_back(s.top());
        }
        else if(s.size()>0 && arr[i]<s.top()){
            while(s.size()>0 && arr[i]<s.top()){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main(){
	long long arr[] = { 10, 5, 11, 10, 20, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);
	nextSmallerToRight(arr, n);
	return 0;
}
