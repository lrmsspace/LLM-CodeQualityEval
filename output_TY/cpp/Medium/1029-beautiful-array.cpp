/**https://leetcode.com/problems/beautiful-array/ */
//An array nums of length n is beautiful if:
//	nums is a permutation of the integers in the range [1, n].
//	For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
// 
//Example 1:
//Input: n = 4
//Output: [2,1,4,3]
//Example 2:
//Input: n = 5
//Output: [3,1,2,5,4]
// 
//Constraints:
//	1 <= n <= 1000
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);
        while(ans.size() < n){
            vector<int> temp;
            for(int i = 0; i < ans.size(); i++){
                if(2 * ans[i] - 1 <= n) temp.push_back(2 * ans[i] - 1);
            }
            for(int i = 0; i < ans.size(); i++){
                if(2 * ans[i] <= n) temp.push_back(2 * ans[i]);
            }
            ans = temp;
        }
        return ans;
    }
};