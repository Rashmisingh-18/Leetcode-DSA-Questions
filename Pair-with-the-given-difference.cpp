/* Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n. 
Input: arr[] = {5, 20, 3, 2, 50, 80}, n = 78
Output: Pair Found: (2, 80) */

// Using Binary Search: First sort the array then implement binary search to find (arr[i]+n).
// Time Compelxity: O(nlogn)  n->size of array


bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    int flag = -1;
    
    for(int i=0; i<size; i++){       
        int low = i+1, high = size-1;
        int x = n+arr[i];
        
        while(low <= high){  
            int mid = low + (high-low)/2;
            if(arr[mid] < x){
                low = mid+1;
            }
            else{
                high = mid-1;     
            }
            
            if(arr[mid] - arr[i] == n){
                flag=1;
            }
        }
    }
    if (flag == 1){
        return true;
    }
    else{
        return false;
    }
};


// Implementing in O(n) time complexity, without binary search

bool findPair(int arr[], int size, int n)
{
    // Initialize positions of two elements
    int i = 0;
    int j = 1;
 
    while (i < size && j < size)
    {
        if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n) )
        {
            cout << "Pair Found: (" << arr[i] << ", " << arr[j] << ")";
            return true;
        }
        else if (arr[j]-arr[i] < n)
            j++;
        else
            i++;
    }
 
    cout << "No pair exists in array given";
    return false;
}
 
