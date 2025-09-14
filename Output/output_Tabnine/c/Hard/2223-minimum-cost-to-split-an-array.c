/**https://leetcode.com/problems/minimum-cost-to-split-an-array/ */
//You are given an integer array nums and an integer k.
//Split the array into some number of non-empty subarrays. The cost of a split is the sum of the importance value of each subarray in the split.
//Let trimmed(subarray) be the version of the subarray where all numbers which appear only once are removed.
//	For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].
//The importance value of a subarray is k + trimmed(subarray).length.
//	For example, if a subarray is [1,2,3,3,3,4,4], then trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this subarray will be k + 5.
//Return the minimum possible cost of a split of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,2,1,2,1,3,3], k = 2
//Output: 8
//Explanation: We split nums to have two subarrays: [1,2], [1,2,1,3,3].
//The importance value of [1,2] is 2 + (0) = 2.
//The importance value of [1,2,1,3,3] is 2 + (2 + 2) = 6.
//The cost of the split is 2 + 6 = 8. It can be shown that this is the minimum possible cost among all the possible splits.
//Example 2:
//Input: nums = [1,2,1,2,1], k = 2
//Output: 6
//Explanation: We split nums to have two subarrays: [1,2], [1,2,1].
//The importance value of [1,2] is 2 + (0) = 2.
//The importance value of [1,2,1] is 2 + (2) = 4.
//The cost of the split is 2 + 4 = 6. It can be shown that this is the minimum possible cost among all the possible splits.
//Example 3:
//Input: nums = [1,2,1,2,1], k = 5
//Output: 10
//Explanation: We split nums to have one subarray: [1,2,1,2,1].
//The importance value of [1,2,1,2,1] is 5 + (3 + 2) = 10.
//The cost of the split is 10. It can be shown that this is the minimum possible cost among all the possible splits.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	0 <= nums[i] < nums.length
//	1 <= k <= 109
// 
//.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
//}
//.spoiler {overflow:hidden;}
//.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
//.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
//.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
int minCost(int* nums, int numsSize, int k) {
    int* count = (int*)calloc(numsSize, sizeof(int));
    int* prefixSum = (int*)calloc(numsSize + 1, sizeof(int));
    int* suffixSum = (int*)calloc(numsSize + 1, sizeof(int));
    int* dp = (int*)calloc(numsSize, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    
    prefixSum[0] = count[0];
    for (int i = 1; i < numsSize; i++) {
        prefixSum[i] = prefixSum[i - 1] + count[i];
    }
    
    suffixSum[numsSize] = count[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + count[i];
    }
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = k + (i + 1) * (i + 1);
    }
    
    for (int i = 0; i < numsSize; i++) {
        int minCost = INT_MAX;
        
        for (int j = 0; j < i; j++) {
            int leftCount = prefixSum[i] - prefixSum[j];
            int rightCount = suffixSum[numsSize - 1] - suffixSum[i + 1] + prefixSum[j];
            int leftCost = dp[j] + (i - j) * (i - j) + leftCount * (leftCount - 1) / 2;
            int rightCost = dp[i] + (j + 1) * (j + 1) + rightCount * (rightCount - 1) / 2;
            minCost = min(minCost, leftCost);
            minCost = min(minCost, rightCost);
        }
        
        dp[i] = minCost;
    }
    
    int result = dp[numsSize - 1];
    
    free(count);
    free(prefixSum);
    free(suffixSum);
    free(dp);
    
    return result;
    
}