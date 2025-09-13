/**https://leetcode.com/problems/find-k-pairs-with-smallest-sums/ */
//You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
//Define a pair (u, v) which consists of one element from the first array and one element from the second array.
//Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
// 
//Example 1:
//Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//Output: [[1,2],[1,4],[1,6]]
//Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//Example 2:
//Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//Output: [[1,1],[1,1]]
//Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 105
//	-109 <= nums1[i], nums2[i] <= 109
//	nums1 and nums2 both are sorted in non-decreasing order.
//	1 <= k <= 104
//	k <= nums1.length * nums2.length
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
    int* index = (int*)malloc(sizeof(int) * nums1Size);
    memset(index, 0, sizeof(int) * nums1Size);
    while (k > 0) {
        int min = INT_MAX;
        int minIndex = 0;
        for (int i = 0; i < nums1Size; i++) {
            if (index[i] < nums2Size && nums1[i] + nums2[index[i]] < min) {
                min = nums1[i] + nums2[index[i]];
                minIndex = i;
            }
        }
        result[k - 1] = (int*)malloc(sizeof(int) * 2);
        result[k - 1][0] = nums1[minIndex];
        result[k - 1][1] = nums2[index[minIndex]];
        (*returnColumnSizes)[k - 1] = 2;
        index[minIndex]++;
        k--;
    }
    *returnSize = k;
    free(index);
    return result;
}