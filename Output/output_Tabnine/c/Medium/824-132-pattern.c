/**https://leetcode.com/problems/132-pattern/ */
//Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
//Return true if there is a 132 pattern in nums, otherwise, return false.
// 
//Example 1:
//Input: nums = [1,2,3,4]
//Output: false
//Explanation: There is no 132 pattern in the sequence.
//Example 2:
//Input: nums = [3,1,4,2]
//Output: true
//Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
//Example 3:
//Input: nums = [-1,3,2,0]
//Output: true
//Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 2 * 105
//	-109 <= nums[i] <= 109
bool find132pattern(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 3) return false;
    
    // Find the smallest number in the array
    int minVal = INT_MAX;
    for (int i = 0; i < n; i++) {
        minVal = min(minVal, nums[i]);
    }
    
    // Initialize a stack to store the increasing part of the sequence
    stack<int> st;
    
    // Iterate through the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If the current number is greater than or equal to the smallest number, continue to the next number
        if (nums[i] >= minVal) continue;
        
        // If the stack is empty or the top number in the stack is less than the current number, push it to the stack
        while (!st.empty() && st.top() < nums[i]) {
            int third = st.top();
            st.pop();
            
            // If the top number in the stack is less than the current number and greater than the smallest number,
            // it means there is a 132 pattern, so return true
            if (third > minVal) return true;
        }
        
        // Push the current number to the stack
        st.push(nums[i]);
    }
    
    // If no 132 pattern is found, return false
    return false;
    
}