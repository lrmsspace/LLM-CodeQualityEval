/*
 Given an integer array nums, find the number of subsequences of size 5 of nums with a unique middle mode.
 Since the answer may be very large, return it modulo 109 + 7.
 A mode of a sequence of numbers is defined as the element that appears the maximum number of times in the sequence.
 A sequence of numbers contains a unique mode if it has only one mode.
 A sequence of numbers seq of size 5 contains a unique middle mode if the middle element (seq[2]) is a unique mode.
 Example 1:
 Input: nums = [1,1,1,1,1,1]
 Output: 6
 Explanation:
 [1, 1, 1, 1, 1] is the only subsequence of size 5 that can be formed, and it has a unique middle mode of 1. This subsequence can be formed in 6 different ways, so the output is 6. 
 Example 2:
 Input: nums = [1,2,2,3,3,4]
 Output: 4
 Explanation:
 [1, 2, 2, 3, 4] and [1, 2, 3, 3, 4] each have a unique middle mode because the number at index 2 has the greatest frequency in the subsequence. [1, 2, 2, 3, 3] does not have a unique middle mode because 2 and 3 appear twice.
 Example 3:
 Input: nums = [0,1,2,3,4,5,6,7,8]
 Output: 0
 Explanation:
 There is no subsequence of length 5 with a unique middle mode.
 Constraints:
 5 <= nums.length <= 1000
 -109 <= nums[i] <= 109
*/

class Solution {
public:
    int subsequencesWithMiddleMode(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        if (n < 5) return 0;

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        long long result = 0;

        // Iterate through all unique elements to find the middle mode
        for (const auto& [mode, count] : freq) {
            if (count < 3) continue; // Need at least 3 occurrences for a unique middle mode

            // Calculate the number of ways to choose 2 other elements from the remaining
            long long ways = count * (count - 1) / 2; // Choose 2 from count
            for (const auto& [other, otherCount] : freq) {
                if (other == mode || otherCount < 2) continue; // Skip the mode and those with less than 2 occurrences
                ways = (ways * otherCount * (otherCount - 1)) % MOD; // Choose 2 from otherCount
            }

            result = (result + ways) % MOD;
        }

        return static_cast<int>(result);
        
    }
};