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
int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    int n = numsSize;
    int count = 0;
    int prefixSum[n + 1];
    prefixSum[0] = 0;
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    for (int left = 0; left < n; ++left) {
        for (int right = left; right <= n; ++right) {
            int sum = prefixSum[right] - prefixSum[left];
            if (sum == goal) {
                count += (right - left);
            }
        }
    }
    
    return count;
    
}