/**https://leetcode.com/problems/single-number-ii/ */
//Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
// 
//Example 1:
//Input: nums = [2,2,3,2]
//Output: 3
//Example 2:
//Input: nums = [0,1,0,1,0,1,99]
//Output: 99
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	-231 <= nums[i] <= 231 - 1
//	Each element in nums appears exactly three times except for one element which appears once.
class Solution {
    public int singleNumber(int[] nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            // Update twos with the bits that are in ones and current number
            twos |= ones & num;
            // Update ones with the current number
            ones ^= num;
            // Get the bits that are in both ones and twos (i.e., the bits that appear three times)
            int threes = ones & twos;
            // Remove those bits from ones and twos
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones; // The result is in ones, which contains the bits of the single number        
    }
}