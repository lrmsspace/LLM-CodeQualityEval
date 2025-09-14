/**https://leetcode.com/problems/find-k-pairs-with-smallest-sums/ */
//You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
//Define a pair (u, v) which consists of one element from the first array and one element from the second array.
//Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
// 
//Example 1:
//Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//Output: [[1,2],[1,4],[1,6]]
//Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//Example 2:
//Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//Output: [[1,1],[1,1]]
//Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 105
//	-109 <= nums1[i], nums2[i] <= 109
//	nums1 and nums2 both are sorted in non-decreasing order.
//	1 <= k <= 104
//	k <= nums1.length * nums2.length
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) return res;
        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        q.push({0, 0});
        while (k-- > 0 && !q.empty()) {
            auto t = q.top();
            q.pop();
            res.push_back({nums1[t.first], nums2[t.second]});
            if (t.first + 1 < nums1.size()) q.push({t.first + 1, t.second});
            if (t.first == 0 && t.second + 1 < nums2.size()) q.push({t.first, t.second + 1});
        }
        return res        
    }
};