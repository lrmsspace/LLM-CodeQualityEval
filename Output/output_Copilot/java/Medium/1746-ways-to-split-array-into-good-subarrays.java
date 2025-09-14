/**https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/ */
//You are given a binary array nums.
//A subarray of an array is good if it contains exactly one element with the value 1.
//Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [0,1,0,0,1]
//Output: 3
//Explanation: There are 3 ways to split nums into good subarrays:
//- [0,1] [0,0,1]
//- [0,1,0] [0,1]
//- [0,1,0,0] [1]
//Example 2:
//Input: nums = [0,1,0]
//Output: 1
//Explanation: There is 1 way to split nums into good subarrays:
//- [0,1,0]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 1
class Solution {
    public int numberOfGoodSubarraySplits(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = 0;
        for (int i = 1; i < n; i++) {
            int l = 0, r = 0;
            int left = prefix[i];
            int right = prefix[n] - prefix[i];
            for (int j = i - 1; j >= 0; j--) {
                if (prefix[i] - prefix[j] < prefix[j]) {
                    l = j;
                } else {
                    break;
                }
            }
            for (int j = i + 1; j <= n; j++) {
                if (prefix[j] - prefix[i] < prefix[n] - prefix[j]) {
                    r = j;
                } else {
                    break;
                }
            }
            res = (res + (r - i) * (i - l)) % 1000000007;
        }  
        return res; // Return the number of ways to split the array into good subarrays      
    }
}