/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            temp.push_back(nums[i]);
            for(int j = i+1; j < n; j++){
                if(nums[j] >= temp.back()){
                    temp.push_back(nums[j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[j] >= nums[i]){
                    vector<int> temp2;
                    temp2.push_back(nums[i]);
                    temp2.push_back(nums[j]);
                    ans.push_back(temp2);
                }
            }
        }
        return ans;
    }
};