/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int x : nums) {
            ++count[x];
        }
        int res = 0;
        function<void(int, int, int)> dfs = [&](int i, int prev, int next) {
            if (i == nums.size()) {
                ++res;
                return;
            }
            for (int x : count) {
                if (x.second == 0) continue;
                if (i == 0 || is_square(prev + x.first)) {
                    --count[x.first];
                    dfs(i + 1, x.first, next);
                    ++count[x.first];
                }
                if (i == 1 || is_square(next + x.first)) {
                    --count[x.first];
                    dfs(i + 1, prev, x.first);
                    ++count[x.first];
                }
            }
        };
        dfs(0, 0, 0);
        return res;
    }
};