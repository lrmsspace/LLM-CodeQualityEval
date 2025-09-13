/*
 You are given an integer array nums and a positive integer k.
 The value of a sequence seq of size 2 * x is defined as:
 (seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR seq[2 * x - 1]).
 Return the maximum value of any subsequence of nums having size 2 * k.
 Example 1:
 Input: nums = [2,6,7], k = 1
 Output: 5
 Explanation:
 The subsequence [2, 7] has the maximum value of 2 XOR 7 = 5.
 Example 2:
 Input: nums = [4,2,5,6,7], k = 2
 Output: 2
 Explanation:
 The subsequence [4, 5, 6, 7] has the maximum value of (4 OR 5) XOR (6 OR 7) = 2.
 Constraints:
 2 <= nums.length <= 400
 1 <= nums[i] < 27
 1 <= k <= nums.length / 2
*/

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return 0; // Not enough elements for a valid subsequence

        // Calculate the OR values for the first k elements
        int leftOr = 0;
        for (int i = 0; i < k; ++i) {
            leftOr |= nums[i];
        }

        // Calculate the OR values for the last k elements
        int rightOr = 0;
        for (int i = n - k; i < n; ++i) {
            rightOr |= nums[i];
        }

        // The maximum value is the XOR of the two OR values
        return leftOr ^ rightOr;
        
    }
};