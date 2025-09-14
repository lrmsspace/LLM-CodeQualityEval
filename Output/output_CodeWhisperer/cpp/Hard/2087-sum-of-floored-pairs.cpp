/**https://leetcode.com/problems/sum-of-floored-pairs/ */
//Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
//The floor() function returns the integer part of the division.
// 
//Example 1:
//Input: nums = [2,5,9]
//Output: 10
//Explanation:
//floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
//floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
//floor(5 / 2) = 2
//floor(9 / 2) = 4
//floor(9 / 5) = 1
//We calculate the floor of the division for every pair of indices in the array then sum them up.
//Example 2:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 49
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> count(max_num + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        vector<int> prefix_sum(max_num + 1, 0);
        for (int i = 1; i <= max_num; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + count[i];
        }
        long long ans = 0;
        for (int i = 1; i <= max_num; i++) {
            if (count[i] == 0) continue;
            for (int j = 1; i * j <= max_num; j++) {
                int left = i * j - 1;
                int right = i * (j + 1) - 1;
                int cnt = prefix_sum[min(right, max_num)] - prefix_sum[left];
                ans = (ans + (long long)cnt * j * count[i]) % mod;
            }
        }
        return ans;      
    }
};