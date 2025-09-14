/**https://leetcode.com/problems/longest-consecutive-sequence/ */
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.
// 
//Example 1:
//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//Example 2:
//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
// 
//Constraints:
//	0 <= nums.length <= 105
//	-109 <= nums[i] <= 109
int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    // Create a set to store the numbers
    int* set = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        set[i] = nums[i];
    }
    
    // Initialize the maximum length
    int maxLength = 1;
    
    // Iterate through the set
    for (int i = 0; i < numsSize; i++) {
        // Skip if the number is already processed
        if (set[i] == -1) continue;
        
        // Initialize the current number and its adjacent numbers
        int current = set[i];
        int adjacent = current + 1;
        
        // Find the length of the consecutive sequence starting from the current number
        while (set[adjacent - 1]!= -1) {
            current++;
            adjacent = current + 1;
        }
        
        // Update the maximum length if necessary
        maxLength = fmax(maxLength, current - set[i] + 1);
        
        // Mark the consecutive sequence as processed
        for (int j = set[i]; j < current; j++) {
            set[j] = -1;
        }
    }
    
    // Free the allocated memory
    free(set);
    
    return maxLength;
    
}