/*
 Given an array nums, you can perform the following operation any number of times:
 Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
 Replace the pair with their sum.
 Return the minimum number of operations needed to make the array non-decreasing.
 An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
 Example 1:
 Input: nums = [5,2,3,1]
 Output: 2
 Explanation:
 The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
 The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
 The array nums became non-decreasing in two operations.
 Example 2:
 Input: nums = [1,2,2]
 Output: 0
 Explanation:
 The array nums is already sorted.
 Constraints:
 1 <= nums.length <= 105
 -109 <= nums[i] <= 109
*/

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) return 0;
    
    int operations = 0;
    bool changed = true;
    
    while(changed) {
        changed = false;
        
        // Check if array is already non-decreasing
        bool isNonDecreasing = true;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                isNonDecreasing = false;
                break;
            }
        }
        if(isNonDecreasing) break;
        
        // Find adjacent pair with minimum sum
        int minSum = nums[0] + nums[1];
        int minIdx = 0;
        for(int i = 1; i < nums.size()-1; i++) {
            if(nums[i] + nums[i+1] < minSum) {
                minSum = nums[i] + nums[i+1];
                minIdx = i;
            }
        }
        
        // Replace pair with their sum
        nums.erase(nums.begin() + minIdx);
        nums[minIdx] = minSum;
        operations++;
        changed = true;
    }
    
    return operations;
}            
};