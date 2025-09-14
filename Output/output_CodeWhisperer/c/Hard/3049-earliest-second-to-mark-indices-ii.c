/*
 You are given two 1-indexed integer arrays, nums and, changeIndices, having lengths n and m, respectively.
 Initially, all indices in nums are unmarked. Your task is to mark all indices in nums.
 In each second, s, in order from 1 to m (inclusive), you can perform one of the following operations:
 Choose an index i in the range [1, n] and decrement nums[i] by 1.
 Set nums[changeIndices[s]] to any non-negative value.
 Choose an index i in the range [1, n], where nums[i] is equal to 0, and mark index i.
 Do nothing.
 Return an integer denoting the earliest second in the range [1, m] when all indices in nums can be marked by choosing operations optimally, or -1 if it is impossible.
 Example 1:
 Input: nums = [3,2,3], changeIndices = [1,3,2,2,2,2,3]
 Output: 6
 Explanation: In this example, we have 7 seconds. The following operations can be performed to mark all indices:
 Second 1: Set nums[changeIndices[1]] to 0. nums becomes [0,2,3].
 Second 2: Set nums[changeIndices[2]] to 0. nums becomes [0,2,0].
 Second 3: Set nums[changeIndices[3]] to 0. nums becomes [0,0,0].
 Second 4: Mark index 1, since nums[1] is equal to 0.
 Second 5: Mark index 2, since nums[2] is equal to 0.
 Second 6: Mark index 3, since nums[3] is equal to 0.
 Now all indices have been marked.
 It can be shown that it is not possible to mark all indices earlier than the 6th second.
 Hence, the answer is 6.
 Example 2:
 Input: nums = [0,0,1,2], changeIndices = [1,2,1,2,1,2,1,2]
 Output: 7
 Explanation: In this example, we have 8 seconds. The following operations can be performed to mark all indices:
 Second 1: Mark index 1, since nums[1] is equal to 0.
 Second 2: Mark index 2, since nums[2] is equal to 0.
 Second 3: Decrement index 4 by one. nums becomes [0,0,1,1].
 Second 4: Decrement index 4 by one. nums becomes [0,0,1,0].
 Second 5: Decrement index 3 by one. nums becomes [0,0,0,0].
 Second 6: Mark index 3, since nums[3] is equal to 0.
 Second 7: Mark index 4, since nums[4] is equal to 0.
 Now all indices have been marked.
 It can be shown that it is not possible to mark all indices earlier than the 7th second.
 Hence, the answer is 7.
 Example 3:
 Input: nums = [1,2,3], changeIndices = [1,2,3]
 Output: -1
 Explanation: In this example, it can be shown that it is impossible to mark all indices, as we don't have enough seconds. 
 Hence, the answer is -1.
 Constraints:
 1 <= n == nums.length <= 5000
 0 <= nums[i] <= 109
 1 <= m == changeIndices.length <= 5000
 1 <= changeIndices[i] <= n
*/

int earliestSecondToMarkIndices(int* nums, int numsSize, int* changeIndices, int changeIndicesSize) {
    // Check if we have enough operations
    if (changeIndicesSize < numsSize) {
        return -1;
    }

    // Helper function to check if possible to mark all indices by given time
    int isPossible(int time) {
        long long* nums_copy = (long long*)malloc(numsSize * sizeof(long long));
        int* marked = (int*)calloc(numsSize, sizeof(int));
        int* last_occurrence = (int*)malloc(numsSize * sizeof(int));
        
        // Copy nums array and initialize last occurrence
        for (int i = 0; i < numsSize; i++) {
            nums_copy[i] = nums[i];
            last_occurrence[i] = -1;
        }
        
        // Find last occurrence of each index up to time
        for (int i = 0; i < time; i++) {
            last_occurrence[changeIndices[i] - 1] = i;
        }
        
        // Process each second up to time
        for (int i = 0; i < time; i++) {
            int idx = changeIndices[i] - 1;
            
            // If this is the last occurrence of current index
            if (i == last_occurrence[idx]) {
                nums_copy[idx] = 0;
            }
        }
        
        // Try to mark indices
        int marks_left = numsSize;
        for (int i = time - 1; i >= 0 && marks_left > 0; i--) {
            int idx = changeIndices[i] - 1;
            if (!marked[idx] && nums_copy[idx] == 0) {
                marked[idx] = 1;
                marks_left--;
            }
        }
        
        free(nums_copy);
        free(marked);
        free(last_occurrence);
        
        return marks_left == 0;
    }
    
    // Binary search for earliest possible time
    int left = numsSize;
    int right = changeIndicesSize;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}    

