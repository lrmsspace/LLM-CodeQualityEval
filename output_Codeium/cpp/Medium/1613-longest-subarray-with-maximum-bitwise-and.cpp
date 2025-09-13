/**https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/ */
//You are given an integer array nums of size n.
//Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
//	In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
//Return the length of the longest such subarray.
//The bitwise AND of an array is the bitwise AND of all the numbers in it.
//A subarray is a contiguous sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,2,3,3,2,2]
//Output: 2
//Explanation:
//The maximum possible bitwise AND of a subarray is 3.
//The longest subarray with that value is [3,3], so we return 2.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 1
//Explanation:
//The maximum possible bitwise AND of a subarray is 4.
//The longest subarray with that value is [4], so we return 1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 106
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAnd = 0, maxLen = 0, currAnd = 0, currLen = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            currAnd &= nums[i];
            if (mp.find(currAnd) == mp.end()) {
                mp[currAnd] = i;
            }
            currLen = i - mp[currAnd] + 1;
            if (currAnd > maxAnd) {
                maxAnd = currAnd;
                maxLen = currLen;
            }
            if (currAnd == maxAnd) {
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};