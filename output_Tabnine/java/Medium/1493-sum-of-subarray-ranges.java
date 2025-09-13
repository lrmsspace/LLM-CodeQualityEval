/**https://leetcode.com/problems/sum-of-subarray-ranges/ */
//You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
//Return the sum of all subarray ranges of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 4
//Explanation: The 6 subarrays of nums are the following:
//[1], range = largest - smallest = 1 - 1 = 0 
//[2], range = 2 - 2 = 0
//[3], range = 3 - 3 = 0
//[1,2], range = 2 - 1 = 1
//[2,3], range = 3 - 2 = 1
//[1,2,3], range = 3 - 1 = 2
//So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
//Example 2:
//Input: nums = [1,3,3]
//Output: 4
//Explanation: The 6 subarrays of nums are the following:
//[1], range = largest - smallest = 1 - 1 = 0
//[3], range = 3 - 3 = 0
//[3], range = 3 - 3 = 0
//[1,3], range = 3 - 1 = 2
//[3,3], range = 3 - 3 = 0
//[1,3,3], range = 3 - 1 = 2
//So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
//Example 3:
//Input: nums = [4,-2,-3,4,1]
//Output: 59
//Explanation: The sum of all subarray ranges of nums is 59.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	-109 <= nums[i] <= 109
// 
//Follow-up: Could you find a solution with O(n) time complexity?
class Solution {
    public long subArrayRanges(int[] nums) {
        long res = 0;
        int n = nums.length;
        int[] leftMax = new int[n];
        int[] leftMin = new int[n];
        int[] rightMax = new int[n];
        int[] rightMin = new int[n];
        
        leftMax[0] = nums[0];
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], nums[i]);
            leftMin[i] = Math.min(leftMin[i - 1], nums[i]);
        }
        
        rightMax[n - 1] = nums[n - 1];
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], nums[i]);
            rightMin[i] = Math.min(rightMin[i + 1], nums[i]);
        }
        
        for (int i = 0; i < n; i++) {
            res += Math.max(rightMax[i] - nums[i], nums[i] - leftMin[i]);
        }
        
        return res;
        
    }
}