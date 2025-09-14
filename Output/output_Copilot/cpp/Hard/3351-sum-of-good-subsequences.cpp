/*
 You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
 Return the sum of all possible good subsequences of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 Note that a subsequence of size 1 is considered good by definition.
 Example 1:
 Input: nums = [1,2,1]
 Output: 14
 Explanation:
 Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
 The sum of elements in these subsequences is 14.
 Example 2:
 Input: nums = [3,4,5]
 Output: 40
 Explanation:
 Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
 The sum of elements in these subsequences is 40.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
*/

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> freq;
        for (int num : nums) {
            freq[num]++;
        }

        long long totalSum = 0;
        for (const auto& [num, count] : freq) {
            // Calculate the contribution of subsequences starting with num
            long long contribution = (count * (count + 1) / 2) % MOD; // Sum of first count natural numbers
            totalSum = (totalSum + contribution * num) % MOD;

            // Check for the next number to form good subsequences
            if (freq.find(num + 1) != freq.end()) {
                long long nextCount = freq[num + 1];
                totalSum = (totalSum + contribution * nextCount * (num + 1)) % MOD;
            }
        }

        return static_cast<int>(totalSum);
        
    }
};