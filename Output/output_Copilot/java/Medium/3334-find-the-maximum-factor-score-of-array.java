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
        int n = nums.length;
        long maxScore = 0;

        // Calculate the GCD of the entire array
        int overallGCD = nums[0];
        for (int num : nums) {
            overallGCD = gcd(overallGCD, num);
        }

        // Calculate the LCM of the entire array
        long overallLCM = nums[0];
        for (int num : nums) {
            overallLCM = lcm(overallLCM, num);
        }

        // Calculate the factor score without removing any element
        maxScore = overallGCD * overallLCM;

        // Check by removing each element one by one
        for (int i = 0; i < n; i++) {
            int currentGCD = overallGCD;
            long currentLCM = overallLCM;

            // Calculate GCD and LCM excluding nums[i]
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    currentGCD = gcd(currentGCD, nums[j]);
                    currentLCM = lcm(currentLCM, nums[j]);
                }
            }

            // Update maxScore if the new score is greater
            maxScore = Math.max(maxScore, currentGCD * currentLCM);
        }

        return maxScore;        
    }
}