/**https://leetcode.com/problems/find-the-difference-of-two-arrays/ */
//Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
//	answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
//	answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
//Note that the integers in the lists may be returned in any order.
// 
//Example 1:
//Input: nums1 = [1,2,3], nums2 = [2,4,6]
//Output: [[1,3],[4,6]]
//Explanation:
//For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
//For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
//Example 2:
//Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
//Output: [[3],[]]
//Explanation:
//For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
//Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	-1000 <= nums1[i], nums2[i] <= 1000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    int* nums1_hash = (int*)malloc(sizeof(int) * 2001);
    int* nums2_hash = (int*)malloc(sizeof(int) * 2001);
    memset(nums1_hash, 0, sizeof(int) * 2001);
    memset(nums2_hash, 0, sizeof(int) * 2001);
    int i, j, k, l, m, n, p, q, r, s, t, u
    for (i = 0; i < nums1Size; i++) {
        nums1_hash[nums1[i] + 1000]++;
    }
    for (j = 0; j < nums2Size; j++) {
        nums2_hash[nums2[j] + 1000]++;
    }
    int* ans1 = (int*)malloc(sizeof(int) * 1000);
    int* ans2 = (int*)malloc(sizeof(int) * 1000);
    k = 0;
    l = 0;
    for (m = 0; m < 2001; m++) {
        if (nums1_hash[m] > 0 && nums2_hash[m] == 0) {
            ans1[k++] = m - 1000;
        }
        if (nums2_hash[m] > 0 && nums1_hash[m] == 0) {
            ans2[l++] = m - 1000;
        }
    }
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[0] = k;
    (*returnColumnSizes)[1] = l;
    int** ans = (int**)malloc(sizeof(int*) * 2);
    ans[0] = ans1;
    ans[1] = ans2;
    return ans;
}