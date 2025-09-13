/**https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ */
//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
//Return true if it is possible. Otherwise, return false.
// 
//Example 1:
//Input: nums = [1,2,3,3,4,4,5,6], k = 4
//Output: true
//Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
//Example 2:
//Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
//Output: true
//Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
//Example 3:
//Input: nums = [1,2,3,4], k = 3
//Output: false
//Explanation: Each array should be divided in subarrays of size 3.
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	1 <= nums[i] <= 109
// 
//Note: This question is the same as 846: https://leetcode.com/problems/hand-of-straights/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Initialize a map to store the frequency of each number
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Iterate through the map and find the smallest number that can be used to divide the array into sets of k consecutive numbers


        for (auto it = count.begin(); it!= count.end();) {
            int num = it->first;
            int freq = it->second;
            
            // Check if the current number can be used to divide the array into sets of k consecutive numbers
            if (freq < k) {
                return false;
            }
            
            // Remove the current number and its frequency from the map
            for (int i = 0; i < k; i++) {
                int nextNum = num + i;
                if (count.find(nextNum) == count.end() || count[nextNum] == 0) {
                    return false;
                }
                count[nextNum]--;
            }
            it = count.erase(it);
        }
        
        // If all numbers can be divided into sets of k consecutive numbers, return true
        return true;
        
    }
};