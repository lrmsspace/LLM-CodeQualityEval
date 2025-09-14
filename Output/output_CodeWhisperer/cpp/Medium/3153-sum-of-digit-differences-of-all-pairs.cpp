/*
 You are given an array nums consisting of positive integers where all integers have the same number of digits.
 The digit difference between two integers is the count of different digits that are in the same position in the two integers.
 Return the sum of the digit differences between all pairs of integers in nums.
 Example 1:
 Input: nums = [13,23,12]
 Output: 4
 Explanation:
 We have the following:
 - The digit difference between 13 and 23 is 1.
 - The digit difference between 13 and 12 is 1.
 - The digit difference between 23 and 12 is 2.
 So the total sum of digit differences between all pairs of integers is 1 + 1 + 2 = 4.
 Example 2:
 Input: nums = [10,10,10,10]
 Output: 0
 Explanation:
 All the integers in the array are the same. So the total sum of digit differences between all pairs of integers will be 0.
 Constraints:
 2 <= nums.length <= 105
 1 <= nums[i] < 109
 All integers in nums have the same number of digits.
*/

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int m = to_string(nums[0]).size();
        vector<vector<int>> cnt(m, vector<int>(10, 0));
        
        for(int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            for(int j = 0; j < m; j++) {
                cnt[j][s[j] - '0']++;
            }
        }
        
        long long res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < 10; j++) {
                for(int k = j + 1; k < 10; k++) {
                    res += (long long)cnt[i][j] * cnt[i][k];
                }
            }
        }
        
        return res;
         
    }
};