/* Given two arrays of equal size n and an integer k. The task is to permute both arrays such that sum of their corresponding element is greater than or equal to k 
i.e a[i] + b[i] >= k. The task is print “Yes” if any such permutation exists, otherwise print “No”.
  
Input : a[] = {2, 1, 3}, 
        b[] = { 7, 8, 9 }, 
        k = 10. 
Output : Yes
Permutation  a[] = { 1, 2, 3 } and b[] = { 9, 8, 7 } 
satisfied the condition a[i] + b[i] >= K */ 

// Using Sorting
public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        sort(a, a+n);
        sort(b, b+n, greater<long long>());
        for(int i=0; i<n; i++){
            if(a[i] + b[i] < k)return false;
        }
        return true;
}

// Without Using Sorting
bool isPossible(long long a[], long long b[], int n, long long k) {
        int i = 0;
        int j = n-1;
        while(i<j){
            if(a[i]+b[j] < k){
                return false;
                break;
            }
            i++;
            j--;
        }
        return true;    
}
