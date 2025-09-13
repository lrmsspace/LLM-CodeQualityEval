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
    int **ret = (int**)malloc(sizeof(int*) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
    *returnSize = 0;
    if (nums1Size == 0 || nums2Size == 0) {
        return ret;
    }
    typedef struct {
        int x, y;
    } Pair;
    Pair *pairs = (Pair*)malloc(sizeof(Pair) * nums1Size * nums2Size);
    int pairsSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            pairs[pairsSize].x = nums1[i];
            pairs[pairsSize].y = nums2[j];
            pairsSize++;
        }
    }
    qsort(pairs, pairsSize, sizeof(Pair), cmp);
    for (int i = 0; i < k && i < pairsSize; i++) {
        ret[i] = (int*)malloc(sizeof(int) * 2);
        ret[i][0] = pairs[i].x;
        ret[i][1] = pairs[i].y;
        (*returnColumnSizes)[i] = 2;
        (*returnSize)++;
    }
    return ret;    
}