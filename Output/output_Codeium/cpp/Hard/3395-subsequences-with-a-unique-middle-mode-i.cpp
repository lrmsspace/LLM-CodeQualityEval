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
        int mod = 1e9 + 7;
        int n = nums.size();
        int result = 0;
        unordered_map<int, int> freq;

        // Count frequencies of each element
        for (int num : nums) {
            freq[num]++;
        }

        // Iterate over all possible subsequences of size 5
        for (int i = 0; i < n - 4; ++i) {
            for (int j = i + 1; j < n - 3; ++j) {
                for (int k = j + 1; k < n - 2; ++k) {
                    for (int l = k + 1; l < n - 1; ++l) {
                        for (int m = l + 1; m < n; ++m) {
                            vector<int> subsequence = {nums[i], nums[j], nums[k], nums[l], nums[m]};
                            unordered_map<int, int> subseq_freq;
                            for (int num : subsequence) {
                                subseq_freq[num]++;
                            }

                            // Check if the middle element has a unique mode
                            bool is_unique_mode = true;
                            int middle_value = nums[k];
                            int middle_freq = subseq_freq[middle_value];

                            for (const auto& [key, value] : subseq_freq) {
                                if (key != middle_value && value >= middle_freq) {
                                    is_unique_mode = false;
                                    break;
                                }
                            }

                            if (is_unique_mode) {
                                result = (result + 1) % mod;
                            }
                        }
                    }
                }
            }
        }

        return result;

    }
};