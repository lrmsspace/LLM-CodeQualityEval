/**https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/ */
//Given an array nums and an integer target, return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], target = 2
//Output: 2
//Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
//Example 2:
//Input: nums = [-1,3,5,1,4,2,-9], target = 6
//Output: 2
//Explanation: There are 3 subarrays with sum equal to 6.
//([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	0 <= target <= 106
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.count(sum - target)) {
                ans++;
                sum = 0;
                mp.clear();
                mp[0] = -1;
            }
            mp[sum] = i;
        }
        return ans;
    }
};