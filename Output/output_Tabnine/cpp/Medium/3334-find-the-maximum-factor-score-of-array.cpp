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
public:
    long long maxScore(vector<int>& nums) {
        long long lcm = nums[0];
        long long gcd = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            lcm = lcm * nums[i] / gcd;
            gcd = __gcd(gcd, nums[i]);
        }
        
        long long maxFactorScore = lcm * gcd;
        
        for (int i = 0; i < nums.size(); i++) {
            long long newLcm = lcm / nums[i];
            long long newGcd = gcd * nums[i] / __gcd(gcd, nums[i]);
            long long newFactorScore = newLcm * newGcd;
            
            maxFactorScore = max(maxFactorScore, newFactorScore);
        }
        
        return maxFactorScore;
        
    }
};