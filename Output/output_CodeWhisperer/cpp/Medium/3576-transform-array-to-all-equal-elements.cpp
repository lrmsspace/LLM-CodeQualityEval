/*
 You are given an integer array nums of size n containing only 1 and -1, and an integer k.
 You can perform the following operation at most k times:
 Choose an index i (0 <= i < n - 1), and multiply both nums[i] and nums[i + 1] by -1.
 Note that you can choose the same index i more than once in different operations.
 Return true if it is possible to make all elements of the array equal after at most k operations, and false otherwise.
 Example 1:
 Input: nums = [1,-1,1,-1,1], k = 3
 Output: true
 Explanation:
 We can make all elements in the array equal in 2 operations as follows:
 Choose index i = 1, and multiply both nums[1] and nums[2] by -1. Now nums = [1,1,-1,-1,1].
 Choose index i = 2, and multiply both nums[2] and nums[3] by -1. Now nums = [1,1,1,1,1].
 Example 2:
 Input: nums = [-1,-1,-1,1,1,1], k = 5
 Output: false
 Explanation:
 It is not possible to make all array elements equal in at most 5 operations.
 Constraints:
 1 <= n == nums.length <= 105
 nums[i] is either -1 or 1.
 1 <= k <= n
*/

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Count number of negative numbers
    int negCount = 0;
    for(int num : nums) {
        if(num == -1) negCount++;
    }
    
    // If number of negative numbers is odd, array can't be made all equal
    if(negCount % 2 != 0) return false;
    
    // Count minimum operations needed
    int ops = 0;
    for(int i = 0; i < n-1; i++) {
        // If current number is -1, flip it and next number
        if(nums[i] == -1) {
            nums[i] *= -1;
            nums[i+1] *= -1;
            ops++;
        }
    }
    
    // Check if last number is -1 (impossible case)
    if(nums[n-1] == -1) return false;
    
    // Return true if required operations are less than or equal to k
    return ops <= k;
}                        
    
};