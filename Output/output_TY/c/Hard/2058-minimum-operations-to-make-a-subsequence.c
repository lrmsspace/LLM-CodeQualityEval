/**https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/ */
//You are given an array target that consists of distinct integers and another integer array arr that can have duplicates.
//In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you can insert the integer at the very beginning or end of the array.
//Return the minimum number of operations needed to make target a subsequence of arr.
//A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.
// 
//Example 1:
//Input: target = [5,1,3], arr = [9,4,2,3,4]
//Output: 2
//Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.
//Example 2:
//Input: target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
//Output: 3
// 
//Constraints:
//	1 <= target.length, arr.length <= 105
//	1 <= target[i], arr[i] <= 109
//	target contains no duplicates.
int minOperations(int* target, int targetSize, int* arr, int arrSize){
    int* dp = (int*)malloc(sizeof(int) * arrSize);
    int* pos = (int*)malloc(sizeof(int) * arrSize);
    int i, j, k, l, r, m, n, ans = 0;
    for (i = 0; i < arrSize; i++) pos[i] = -1;
    for (i = 0; i < arrSize; i++) {
        j = pos[arr[i] - 1];
    }
    for (i = 0; i < targetSize; i++) {
        j = pos[target[i] - 1];
        if (j == -1) {
            dp[i] = i ? dp[i - 1] + 1 : 1;
            pos[target[i] - 1] = i;
        } else {
            k = j;
            while (k && target[i - 1] != target[k - 1]) k--;
        }
    }
    for (i = 0; i < targetSize; i++) ans += dp[i];
    return ans;
}