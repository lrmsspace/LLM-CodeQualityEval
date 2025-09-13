/**https://leetcode.com/problems/diagonal-traverse-ii/ */
//Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
// 
//Example 1:
//Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,4,2,7,5,3,8,6,9]
//Example 2:
//Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
//Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i].length <= 105
//	1 <= sum(nums[i].length) <= 105
//	1 <= nums[i][j] <= 105
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;
        int m = nums[0].size();
        
        for (int i = 0; i < n + m - 1; i++) {
            int x = min(i, n - 1);
            int y = max(0, i - (n - 1));
            
            while (x >= 0 && y < m) {
                res.push_back(nums[x][y]);
                x--;
                y++;
            }
        }
        
        return res;
        
    }
};