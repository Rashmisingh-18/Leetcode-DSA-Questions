/* Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
  Example: Input:  N = 4, arr[] = [1 3 2 4]
           Output: 3 4 4 -1
*/

/* Here, basically we are performing three operations:
  -> if stack empty - o/p -1
  -> if stack.top > arr[i] - o/p -stack.top
  -> if stack.top <= arr[i] -pop out from the stack */
  

vector<long long> nextLargerElement(vector<long long> arr, int n){
       vector<long long>ans;
       stack<long long>s;
       for(int i=n-1;i>=0;i--){
           if(s.size()==0){
               ans.push_back(-1);
           }
           else if(s.size()>0 && s.top()>arr[i]){
               ans.push_back(s.top());
           }
           else if(s.size()>0 && s.top()<=arr[i]){
               while(s.size()>0 && s.top()<=arr[i]){
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
       reverse(ans.begin(),ans.end());
       return ans;
   }
