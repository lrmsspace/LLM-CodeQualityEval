/*
 You are given an integer array nums of length n.
 Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
 The score for a jump from index i to index j is calculated as (j - i) * nums[i].
 Return the maximum possible total score by the time you reach the last index.
 Example 1:
 Input: nums = [1,3,1,5]
 Output: 7
 Explanation:
 First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.
 Example 2:
 Input: nums = [4,3,1,3,2]
 Output: 16
 Explanation:
 Jump directly to the last index. The final score is 4 * 4 = 16.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
*/

long long findMaximumScore(int* nums, int numsSize) {
    long long maxScore = 0;
    long long currentScore = 0;
    int maxIndex = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        currentScore = (long long)(nums[i] - i + maxIndex);
        if (currentScore > maxScore) {
            maxScore = currentScore;
        }
        
        if (i + nums[i] > maxIndex) {
            maxIndex = i + nums[i];
        }
    }
    
    currentScore = (long long)(nums[numsSize - 1] - numsSize + 1 + maxIndex);
    if (currentScore > maxScore) {
        maxScore = currentScore;
    }
    
    return maxScore;

}