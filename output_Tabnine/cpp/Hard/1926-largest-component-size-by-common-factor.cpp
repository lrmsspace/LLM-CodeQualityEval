/**https://leetcode.com/problems/largest-component-size-by-common-factor/ */
//You are given an integer array of unique positive integers nums. Consider the following graph:
//	There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
//	There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
//Return the size of the largest connected component in the graph.
// 
//Example 1:
//Input: nums = [4,6,15,35]
//Output: 4
//Example 2:
//Input: nums = [20,50,9,63]
//Output: 2
//Example 3:
//Input: nums = [2,3,6,7,4,12,21,39]
//Output: 8
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] <= 105
//	All the values of nums are unique.
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        auto find = [&](int x) {
            return x == parent[x]? x : parent[x] = find(parent[x]);
        };
        
        auto unionSet = [&](int x, int y) {
            int px = find(x), py = find(y);
            if (px!= py) {
                parent[px] = py;
            }
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int gcd = __gcd(nums[i], nums[j]);
                if (gcd > 1) {
                    unionSet(i, j);
                }
            }
        }
        
        unordered_map<int, int> count;
        for (int i = 0; i < n; ++i) {
            count[find(i)]++;
        }
        
        return *max_element(count.begin(), count.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }).second;
        
    }
};