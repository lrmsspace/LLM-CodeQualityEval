/*
 You are given an array of integers nums of size 3.
 Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.
 Note that the binary representation of any number does not contain leading zeros.
 Example 1:
 Input: nums = [1,2,3]
 Output: 30
 Explanation:
 Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
 Example 2:
 Input: nums = [2,8,16]
 Output: 1296
 Explanation:
 Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.
 Constraints:
 nums.length == 3
 1 <= nums[i] <= 127
*/

class Solution {
    public int maxGoodNumber(int[] nums) {
        // Sort the array in descending order
        Arrays.sort(nums);
        
        // Calculate the maximum possible number by concatenating the binary representation of the sorted numbers
        int maxNum = 0;
        for (int num : nums) {
            maxNum = (maxNum << 3) + num;
        }
        
        return maxNum;
        
    }
}