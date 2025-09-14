/**https://leetcode.com/problems/sort-array-by-increasing-frequency/ */
//Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
//Return the sorted array.
// 
//Example 1:
//Input: nums = [1,1,2,2,2,3]
//Output: [3,1,1,2,2,2]
//Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
//Example 2:
//Input: nums = [2,3,1,3,2]
//Output: [1,3,3,2,2]
//Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
//Example 3:
//Input: nums = [-1,1,-6,4,5,-6,1,4,1]
//Output: [5,-1,4,4,-6,-6,1,1,1]
// 
//Constraints:
//	1 <= nums.length <= 100
//	-100 <= nums[i] <= 100
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h, j1, k1, l1, m1, n1, o1, p1, q1, r1, s1, t1, u1, v1, w1, x1, y1,z1;
    int* p1 = (int*)malloc(sizeof(int)*numsSize);
    int* p2 = (int*)malloc(sizeof(int)*numsSize);
    int* p3 = (int*)malloc(sizeof(int)*numsSize);
    int* p4 = (int*)malloc(sizeof(int)*numsSize);
    int* p5 = (int*)malloc(sizeof(int)*numsSize);
   int* p6 = (int*)malloc(sizeof(int));
    *p6 = 0;
    for (i = 0; i < numsSize; i++) {
        p1[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        p2[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (p1[i] == p1[j]) {
                p2[i]++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        p3[i] = p2[i];
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (p3[i] < p3[j]) {
                a = p3[i];
                p3[i] = p3[j];
                p3[j] = a;
                a = p1[i];
                p1[i] =p1[j];
            }
        }
    }
        for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (p1[i] == p1[j]) {
                p4[i]++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++){
            if (p4[i] > p4[j]) {
                a = p4[i];
                p4[i] = p4[j];
                p4[j] = a;
                a = p1[i];
                p1[i] = p1[j];
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (p1[i] == nums[j]) {
                p5[i] = j;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        p6[i] = p5[i];
    }
    *returnSize = numsSize;
    return p6;
}