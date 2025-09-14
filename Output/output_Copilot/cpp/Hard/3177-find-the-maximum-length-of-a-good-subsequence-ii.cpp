/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 5 * 103
 1 <= nums[i] <= 109
 0 <= k <= min(50, nums.length)
*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (k >= n - 1) {
            return n; // If k is large enough, we can take the entire array
        }

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Sort frequencies in descending order
        vector<int> frequencies;
        for (const auto& entry : freq) {
            frequencies.push_back(entry.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());

        // Calculate the maximum length of a good subsequence
        int maxLength = 0;
        for (int i = 0; i < frequencies.size(); ++i) {
            if (i < k + 1) {
                maxLength += frequencies[i];
            } else {
                break;
            }
        }

        return maxLength;
        
    }
};