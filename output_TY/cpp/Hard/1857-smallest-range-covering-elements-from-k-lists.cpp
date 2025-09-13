/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int max_val = INT_MIN;
        for(int i = 0; i < k; i++){
            pq.push({nums[i][0], i});
            max_val = max(max_val, nums[i][0]);
        }
        int min_range = INT_MAX;
        int start = 0, end = 0;
        while(pq.size() == k){
            auto top = pq.top();
            pq.pop();
            if(max_val - top.first < min_range){
                min_range = max_val - top.first;
                start = top.first;
                end = max_val;
            }
            if(top.second < nums[top.second].size() - 1){
                pq.push({nums[top.second][top.second + 1], top.second});
                max_val = max(max_val, nums[top.second][top.second + 1]);
            }
        }
        return {start, end};
    }
};