/**https://leetcode.com/problems/subsets-ii/ */
//Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//Example 1:
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//	1 <= nums.length <= 10
//	-10 <= nums[i] <= 10
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        int i = 0;
        while(i < nums.size()){
            int j = i;
            while(j < nums.size() && nums[j] == nums[i]){
                j++;
            }
            int count = j - i;
            for(int k = 0; k < ans.size(); k++){
                for(int l = 0; l < count; l++){
                    vector<int> temp2 = ans[k];
                    temp2.push_back(nums[i]);
                    ans.push_back(temp2);
                }
            }
        }
        return ans;
    }
};