/**https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/ */
//You are given an integer array nums of size n.
//Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
//	In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
//Return the length of the longest such subarray.
//The bitwise AND of an array is the bitwise AND of all the numbers in it.
//A subarray is a contiguous sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,2,3,3,2,2]
//Output: 2
//Explanation:
//The maximum possible bitwise AND of a subarray is 3.
//The longest subarray with that value is [3,3], so we return 2.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 1
//Explanation:
//The maximum possible bitwise AND of a subarray is 4.
//The longest subarray with that value is [4], so we return 1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 106
class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] & nums[i];
        }
        int[] suffix = new int[n];
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] & nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i == 0 ? 0 : prefix[i - 1];
            int right = i == n - 1 ? 0 : suffix[i + 1];
            int val = nums[i];
            if ((val & left) == val && (val & right) == val) {
                ans = Math.max(ans, 1);
            }
        }
        return ans;        
    }
}