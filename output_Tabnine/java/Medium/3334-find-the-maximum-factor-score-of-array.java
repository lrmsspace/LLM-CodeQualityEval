/*
 You are given an integer array nums.
 The factor score of an array is defined as the product of the LCM and GCD of all elements of that array.
 Return the maximum factor score of nums after removing at most one element from it.
 Note that both the LCM and GCD of a single number are the number itself, and the factor score of an empty array is 0.
 Example 1:
 Input: nums = [2,4,8,16]
 Output: 64
 Explanation:
 On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of 4 * 16 = 64.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: 60
 Explanation:
 The maximum factor score of 60 can be obtained without removing any elements.
 Example 3:
 Input: nums = [3]
 Output: 9
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 30
*/

class Solution {
    public long maxScore(int[] nums) {

        // Find the LCM and GCD of all elements in the array
        long lcm = nums[0];
        long gcd = nums[0];
        for (int i = 1; i < nums.length; i++) {
            lcm = lcm * nums[i] / gcd;
            gcd = gcd(lcm, nums[i]);
        }
        // Calculate the factor score of the original array
        long factorScore = lcm * gcd;
        // Initialize the maximum factor score to the factor score of the original array
        long maxFactorScore = factorScore;
        // Iterate through the array and remove one element at a time
        for (int i = 0; i < nums.length; i++) {
            // Calculate the new factor score after removing the ith element
            long newFactorScore = lcm * gcd / nums[i];
            // Update the maximum factor score if the new factor score is greater
            maxFactorScore = Math.max(maxFactorScore, newFactorScore);
        }
        return maxFactorScore;
        
    }
}