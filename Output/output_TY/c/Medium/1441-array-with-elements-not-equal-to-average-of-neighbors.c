/**https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/ */
//You are given a 0-indexed array nums of distinct integers. You want to rearrange the elements in the array such that every element in the rearranged array is not equal to the average of its neighbors.
//More formally, the rearranged array should have the property such that for every i in the range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].
//Return any rearrangement of nums that meets the requirements.
// 
//Example 1:
//Input: nums = [1,2,3,4,5]
//Output: [1,2,4,5,3]
//Explanation:
//When i=1, nums[i] = 2, and the average of its neighbors is (1+4) / 2 = 2.5.
//When i=2, nums[i] = 4, and the average of its neighbors is (2+5) / 2 = 3.5.
//When i=3, nums[i] = 5, and the average of its neighbors is (4+3) / 2 = 3.5.
//Example 2:
//Input: nums = [6,2,0,9,7]
//Output: [9,7,6,2,0]
//Explanation:
//When i=1, nums[i] = 7, and the average of its neighbors is (9+6) / 2 = 7.5.
//When i=2, nums[i] = 6, and the average of its neighbors is (7+2) / 2 = 4.5.
//When i=3, nums[i] = 2, and the average of its neighbors is (6+0) / 2 = 3.
// 
//Constraints:
//	3 <= nums.length <= 105
//	0 <= nums[i] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* p1 = (int*)malloc(sizeof(int) * numsSize);
    int* p2 = (int*)malloc(sizeof(int) * numsSize);
    int* p3 = (int*)malloc(sizeof(int) * numsSize);
   int* p4 = (int*)malloc(sizeof(int));
    *p4 = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                p1[*p4] = i;
                p2[*p4] = j;
                *p4 = *p4 + 1;
            }
        }
    }
    for (i = 0; i < *p4; i++) {
        for (j = 0; j < *p4; j++) {
            if (p1[i] == p2[j]) {
                p3[i] = p1[j];
            }
        }
    }
    for (i = 0; i < *p4; i++) {
        for (j = 0; j < numsSize; j++) {
            if (nums[j] != nums[p3[i]]) {
                p4[i] = nums[j];
            }
        }
    }
    return p4;
}