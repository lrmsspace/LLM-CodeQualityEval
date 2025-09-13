/**https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/ */
//You are given an array nums​​​ and an integer k​​​​​. The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].
//Return the minimum number of elements to change in the array such that the XOR of all segments of size k​​​​​​ is equal to zero.
// 
//Example 1:
//Input: nums = [1,2,0,3,0], k = 1
//Output: 3
//Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
//Example 2:
//Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
//Output: 3
//Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].
//Example 3:
//Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
//Output: 3
//Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].
// 
//Constraints:
//	1 <= k <= nums.length <= 2000
//	​​​​​​0 <= nums[i] < 210
int minChanges(int* nums, int numsSize, int k) {
    int minChanges = INT_MAX;
    int n = numsSize;
    int* prefixXor = (int*)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        prefixXor[i + 1] = prefixXor[i] ^ nums[i];
    }
    
    for (int i = 0; i <= n - k; i++) {
        int xorSegment = prefixXor[i + k] ^ prefixXor[i];
        int changes = 0;
        
        for (int j = 0; j < k; j++) {
            int bit = (xorSegment >> j) & 1;
            changes += bit ^ nums[i + j];
        }
        
        minChanges = fmin(minChanges, changes);
    }
    
    free(prefixXor);
    return minChanges;
    
}