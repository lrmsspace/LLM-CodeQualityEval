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
        vector<int> idx(k, 0);
        int min_idx = -1, max_idx = -1;
        int min_val = INT_MAX, max_val = INT_MIN;
        int min_range = INT_MAX;
        vector<int> res(2, 0);
        while(true){
            for(int i = 0; i < k; i++){
                if(idx[i] == nums[i].size()) return res;
                if(nums[i][idx[i]] < min_val){
                    min_idx = i;
                    min_val = nums[i][idx[i]];
                }
                if(nums[i][idx[i]] > max_val){
                    max_idx = i;
                    max_val = nums[i][idx[i]];
                }
            }
            if(max_val - min_val < min_range){
                min_range = max_val - min_val;
                res[0] = min_val;
                res[1] = max_val;
            }
            idx[min_idx]++;
        }
        return res;       
    }
};