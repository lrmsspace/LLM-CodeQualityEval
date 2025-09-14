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
        int sum = n*(n+1)/2;
        int sum2 = 0;
        for(int i = 0; i < n; i++){
            sum2 += nums[i];
            if(nums[i] > n || nums[i] <= 0){
                return {nums[i], sum - sum2 + nums[i]};
            }
        }
        return {nums[n-1] + 1, sum - sum2 + nums[n-1] + 1};
    }
};