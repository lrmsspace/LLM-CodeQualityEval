/**https://leetcode.com/problems/count-number-of-special-subsequences/ */
//A sequence is special if it consists of a positive number of 0s, followed by a positive number of 1s, then a positive number of 2s.
//	For example, [0,1,2] and [0,0,1,1,1,2] are special.
//	In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
//Given an array nums (consisting of only integers 0, 1, and 2), return the number of different subsequences that are special. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. Two subsequences are different if the set of indices chosen are different.
// 
//Example 1:
//Input: nums = [0,1,2,2]
//Output: 3
//Explanation: The special subsequences are bolded [0,1,2,2], [0,1,2,2], and [0,1,2,2].
//Example 2:
//Input: nums = [2,2,0,0]
//Output: 0
//Explanation: There are no special subsequences in [2,2,0,0].
//Example 3:
//Input: nums = [0,1,2,0,1,2]
//Output: 7
//Explanation: The special subsequences are bolded:
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 2
class Solution {
    public int countSpecialSubsequences(int[] nums) {
        int mod = 1000000007;
        long count0 = 0, count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == 0) {
                count0 = (count0 * 2 + 1) % mod; // double the count of subsequences and add one for the new zero
            } else if (num == 1) {
                count1 = (count1 * 2 + count0) % mod; // double the count of subsequences and add the count of zeros before it
            } else if (num == 2) {
                count2 = (count2 * 2 + count1) % mod; // double the count of subsequences and add the count of ones before it
            }
        }
        return (int) count2; // return the final count of special subsequences ending with 2        
    }
}