/**https://leetcode.com/problems/distribute-repeating-integers/ */
//You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
//	The ith customer gets exactly quantity[i] integers,
//	The integers the ith customer gets are all equal, and
//	Every customer is satisfied.
//Return true if it is possible to distribute nums according to the above conditions.
// 
//Example 1:
//Input: nums = [1,2,3,4], quantity = [2]
//Output: false
//Explanation: The 0th customer cannot be given two different integers.
//Example 2:
//Input: nums = [1,2,3,3], quantity = [2]
//Output: true
//Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
//Example 3:
//Input: nums = [1,1,2,2], quantity = [2,2]
//Output: true
//Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	1 <= nums[i] <= 1000
//	m == quantity.length
//	1 <= m <= 10
//	1 <= quantity[i] <= 105
//	There are at most 50 unique values in nums.
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n = nums.size();
        int m = quantity.size();
        
        if (n * quantity[0] > 5000) return false;
        
        sort(nums.begin(), nums.end());
        int target = n * quantity[0];
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] * quantity[0] > target) return false;
            count += nums[i] * quantity[0];
        }
        
        if (count!= target) return false;
        
        vector<int> freq(1001, 0);
        
        for (int num : nums) freq[num]++;
        
        for (int i = 0; i < m; i++) {
            if (quantity[i] > freq[nums[0]]) return false;
            for (int j = 0; j < nums[0]; j++) freq[nums[j]]--;
        }
        
        return true;
        
    }
};