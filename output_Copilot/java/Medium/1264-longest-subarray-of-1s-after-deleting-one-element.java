/**https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/ */
//Given a binary array nums, you should delete one element from it.
//Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
// 
//Example 1:
//Input: nums = [1,1,0,1]
//Output: 3
//Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
//Example 2:
//Input: nums = [0,1,1,1,0,1,1,0,1]
//Output: 5
//Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
//Example 3:
//Input: nums = [1,1,1]
//Output: 2
//Explanation: You must delete one element.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                count = 0;
            }
            left[i] = count;
        }
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 1) {
                count++;
            } else {
                count = 0;
            }
            right[i] = count;
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                result = Math.max(result, right[i + 1]);
            } else if (i == n - 1) {
                result = Math.max(result, left[i - 1]);
            } else {
                result = Math.max(result, left[i - 1] + right[i + 1]);
            }
        }
        return result;        
    }
}