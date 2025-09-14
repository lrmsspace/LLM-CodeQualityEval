/**https://leetcode.com/problems/count-the-number-of-square-free-subsets/ */
//You are given a positive integer 0-indexed array nums.
//A subset of the array nums is square-free if the product of its elements is a square-free integer.
//A square-free integer is an integer that is divisible by no square number other than 1.
//Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.
//A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
// 
//Example 1:
//Input: nums = [3,4,4,5]
//Output: 3
//Explanation: There are 3 square-free subsets in this example:
//- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
//- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
//- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
//It can be proven that there are no more than 3 square-free subsets in the given array.
//Example 2:
//Input: nums = [1]
//Output: 1
//Explanation: There is 1 square-free subset in this example:
//- The subset consisting of the 0th element [1]. The product of its elements is 1, which is a square-free integer.
//It can be proven that there is no more than 1 square-free subset in the given array.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 30
class Solution {
    public int squareFreeSubsets(int[] nums) {
        int mod = 1000000007;
        int[] dp = new int[31];
        int[] prime = new int[31];
        int[] count = new int[31];
        int[] factor = new int[31];
        int[] dp2 = new int[31];
        int[] dp3 = new int[31];
        int[] dp4 = new int[31];
        int[] dp5 = new int[31];
        int[] dp6 = new int[31];
        int[] dp7 = new int[31];
        int[] dp8 = new int[31];
        int[] dp9 = new int[31];
        int[] dp10 = new int[31];  
        dp[1] = 1;
        for (int i = 2; i < 31; i++) {
            if (prime[i] == 0) {
                prime[i] = 1;
                for (int j = i * i; j < 31; j += i) {
                    prime[j] = 1;
                }
                factor[i] = 1;
                for (int j = i * i; j < 31; j += i * i) {
                    factor[j]++;
                }
            }
        }
        for (int i = 1; i < 31; i++) {
            if (prime[i] == 0) {
                count[i] = 1;
                dp2[i] = dp[i];
                dp3[i] = dp2[i];
                dp4[i] = dp3[i];
                dp5[i] = dp4[i];
                dp6[i] = dp5[i];
                dp7[i] = dp6[i];
                dp8[i] = dp7[i];
                dp9[i] = dp8[i];
                dp10[i] = dp9[i];
            }
        }
        for (int i = 2; i < 31; i++) {
            if (prime[i] == 0) {
                for (int j = i + i; j < 31; j += i) {
                    if (prime[j] == 0) {
                        count[j] += count[i];
                        dp2[j] += dp2[i];
                    }
                }
            }
        }
        for (int i = 2; i < 31; i++) {
            if (prime[i] == 0) {
                for (int j = i + i; j < 31; j += i) {
                    if (prime[j] == 0) {
                        dp3[j] += dp3[i];
                    }
                }
            }
        }
        
   }
}