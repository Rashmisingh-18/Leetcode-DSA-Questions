/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
  
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]. */

/* We can find the (target-nums[i]), which is the value when adds up with the nums[i] gives the target value. So we, find that then we push both in the map and 
return the index of those elements. */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                res.emplace_back(i);
                res.emplace_back(mp[target-nums[i]]);
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
