/**https://leetcode.com/problems/binary-subarrays-with-sum/ */
//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
//A subarray is a contiguous part of the array.
// 
//Example 1:
//Input: nums = [1,0,1,0,1], goal = 2
//Output: 4
//Explanation: The 4 subarrays are bolded and underlined below:
//[1,0,1,0,1]
//[1,0,1,0,1]
//[1,0,1,0,1]
//[1,0,1,0,1]
//Example 2:
//Input: nums = [0,0,0,0,0], goal = 0
//Output: 15
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	nums[i] is either 0 or 1.
//	0 <= goal <= nums.length
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0, prefixSum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        for (int num : nums) {
            prefixSum += num;
            count += prefixSumCount[prefixSum - goal];
            prefixSumCount[prefixSum]++;
        }
        return count;
        
    }
};