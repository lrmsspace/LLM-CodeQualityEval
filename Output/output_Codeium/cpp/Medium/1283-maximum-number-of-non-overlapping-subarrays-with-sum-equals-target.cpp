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
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (m.count(sum - target)) res = max(res, i - m[sum - target]);
            m[sum] = i;
        }
        return res;
    }
};