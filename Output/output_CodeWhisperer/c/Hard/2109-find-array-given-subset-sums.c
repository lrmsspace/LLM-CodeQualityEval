/**https://leetcode.com/problems/find-array-given-subset-sums/ */
//You are given an integer n representing the length of an unknown array that you are trying to recover. You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).
//Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.
//An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.
//Note: Test cases are generated such that there will always be at least one correct answer.
// 
//Example 1:
//Input: n = 3, sums = [-3,-2,-1,0,0,1,2,3]
//Output: [1,2,-3]
//Explanation: [1,2,-3] is able to achieve the given subset sums:
//- []: sum is 0
//- [1]: sum is 1
//- [2]: sum is 2
//- [1,2]: sum is 3
//- [-3]: sum is -3
//- [1,-3]: sum is -2
//- [2,-3]: sum is -1
//- [1,2,-3]: sum is 0
//Note that any permutation of [1,2,-3] and also any permutation of [-1,-2,3] will also be accepted.
//Example 2:
//Input: n = 2, sums = [0,0,0,0]
//Output: [0,0]
//Explanation: The only correct answer is [0,0].
//Example 3:
//Input: n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
//Output: [0,-1,4,5]
//Explanation: [0,-1,4,5] is able to achieve the given subset sums.
// 
//Constraints:
//	1 <= n <= 15
//	sums.length == 2n
//	-104 <= sums[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* recoverArray(int n, int* sums, int sumsSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    int* count = (int*)calloc(20001, sizeof(int));
    for (int i = 0; i < sumsSize; i++) {
        count[sums[i] + 10000]++;
    }
    int* unique = (int*)malloc(sizeof(int) * sumsSize);
    int uniqueSize = 0;
    for (int i = 0; i < 20001; i++) {
        if (count[i] > 0) {
            unique[uniqueSize++] = i - 10000;
        }
    }
    for (int i = 0; i < n; i++) {
        int k = 0;
        int* next = (int*)calloc(20001, sizeof(int));
        for (int j = 0; j < uniqueSize; j++) {
            if (count[unique[j]] > 0) {
                count[unique[j]]--;
                int num = unique[j] + unique[k];
                ans[i] = num;
                k++;
                next[num + 10000]++;
            }
        }
        free(count);
        count = next;
        uniqueSize = 0;
        for (int j = 0; j < 20001; j++) {
            if (count[j] > 0) {
                unique[uniqueSize++] = j - 10000;
            }
        }
    }
    free(count);
    return ans;
}