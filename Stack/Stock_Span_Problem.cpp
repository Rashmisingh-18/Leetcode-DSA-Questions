// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of the stock’s price for 
// all n days. The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of 
// the stock on the current day is less than its price on the given day. 
//   EXAMPLE: Input: N = 7, price[] = [100 80 60 70 60 75 85]
//            Output: 1 1 1 2 1 4 6

// Here, we can use the approach similar to used in finding the Nearest Greater to Left.
// So, what we can do is, find the NGL for every element in array, then in vector put the indexes of respective NGLs, then output the (element_index - index of NGL).

// Approach: let us take, 
//       indexing:              0  1  2  3  4  5  6
//                             100 80 60 70 60 75 85

// indexing of respective NGL: -1  0  1  1  3  1  0
// now subtract both indexes:   1  1  1  2  1  4  6      which is our required output


#include<bits/stdc++.h>
using namespace std;

void calculateSpan(int price[], int n){
    vector<int>ans;
    stack<pair<int, int>>s;

    for(int i=0; i<n; i++){
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.size()>0 && price[i] < s.top().first){
            ans.push_back(s.top().second);
        }
        else if(s.size()>0 && price[i] >= s.top().first){
            while(s.size()>0 && price[i] >= s.top().first){
                s.pop();
            }
            if(s.size() == 0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top().second);
            }
        }
        s.push({price[i], i});
    }
    for(int i=0; i<n; i++){
        ans[i] = i-ans[i];
        cout<<ans[i]<<" ";
    }
}

int main(){	
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
  
    calculateSpan(price, n);
  
    return 0;
}
