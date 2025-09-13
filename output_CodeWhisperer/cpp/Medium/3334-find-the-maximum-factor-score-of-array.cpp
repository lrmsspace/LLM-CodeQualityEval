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
        int n = nums.size();
        vector<int> gcd(n, 0);
        vector<int> lcm(n, 0);
        gcd[0] = nums[0];
        lcm[0] = nums[0];
        for(int i = 1; i < n; i++) {
            gcd[i] = __gcd(gcd[i - 1], nums[i]);
            lcm[i] = lcm[i - 1] * nums[i] / __gcd(lcm[i - 1], nums[i]);
        }
        long long maxScore = 0;
        for(int i = 0; i < n; i++) {
            long long left = (i == 0) ? 0 : gcd[i - 1];
            long long right = (i == n - 1) ? 0 : lcm[n - 1] / lcm[i] * gcd[n - 1] / gcd[i];
            maxScore = max(maxScore, (long long)left * right);
        }
        return maxScore;

            
    }
};