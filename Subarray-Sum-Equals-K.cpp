/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,1,1], k = 2
Output: 2 */


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefix[n];
        prefix[0] = nums[0];
        unordered_map<int, int>mp;
        for(int i=1; i<n; i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(prefix[i]==k){
                ans++;
            }
            if(mp.find(prefix[i]-k)!=mp.end()){
                ans+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};
