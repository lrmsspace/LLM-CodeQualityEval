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
        unordered_map<int, int> m;
        for (auto& n : nums) {
            m[n]++;
        }
        unordered_map<int, vector<int>> adj;
        for (auto& [k, v] : m) {
            for (auto& [k2, v2] : m) {
                if (sqrt(k + k2) - floor(sqrt(k + k2)) == 0) {
                    adj[k].push_back(k2);
                    adj[k2].push_back(k);
                }
            }
        }
        int res = 0;
        for (auto& [k, v] :m) {
            if (adj.find(k) != adj.end()) {
                queue<pair<int, int>> q;
                q.push({ k, v });
                while (!q.empty()) {
                    auto [k, v] = q.front();
                    q.pop();
                    for (auto& n : adj[k]) {
                        if (m[n] > 1) {
                            m[n]--;
                            q.push({ n, m[n] });
                        }
                        else {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};