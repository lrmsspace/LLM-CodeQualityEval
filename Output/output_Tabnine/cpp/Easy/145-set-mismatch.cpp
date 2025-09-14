/**https://leetcode.com/problems/set-mismatch/ */
//You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
//You are given an integer array nums representing the data status of this set after the error.
//Find the number that occurs twice and the number that is missing and return them in the form of an array.
// 
//Example 1:
//Input: nums = [1,2,2,4]
//Output: [2,3]
//Example 2:
//Input: nums = [1,1]
//Output: [1,2]
// 
//Constraints:
//	2 <= nums.length <= 104
//	1 <= nums[i] <= 104
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2);
        vector<bool> visited(n + 1, false);
        
        for (int num : nums) {
            if (visited[num]) {
                res[0] = num;
            } else {
                visited[num] = true;
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                res[1] = i;
                break;
            }
        }
        
        return res;
        
    }
};