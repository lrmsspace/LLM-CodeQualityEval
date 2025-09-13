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
        int n = nums.size();
        int mod = 1e9 + 7;
        int res = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        for (auto& [k, v] : cnt) {
            if (v >= 3) {
                res = (res + 1) % mod;
            }
            if (v >= 2) {
                res = (res + 1) % mod;
            }
            if (v >= 1) {
                res = (res + 1) % mod;
            }
        }
        for (auto& [k1, v1] : cnt) {
            for (auto& [k2, v2] : cnt) {
                if (k1 == k2) continue;
                if (v1 >= 2 && v2 >= 1) {
                    res = (res + 1) % mod;
                }
                if (v1 >= 1 && v2 >= 2) {
                    res = (res + 1) % mod;
                }
                if (v1 >= 1 && v2 >= 1) {
                    res = (res + 1) % mod;
                }
            }
        }
        return res;

    }
};