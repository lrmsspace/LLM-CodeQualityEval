/**https://leetcode.com/problems/rearrange-array-elements-by-sign/ */
//You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
//You should rearrange the elements of nums such that the modified array follows the given conditions:
//	Every consecutive pair of integers have opposite signs.
//	For all integers with the same sign, the order in which they were present in nums is preserved.
//	The rearranged array begins with a positive integer.
//Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
// 
//Example 1:
//Input: nums = [3,1,-2,-5,2,-4]
//Output: [3,-2,1,-5,2,-4]
//Explanation:
//The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
//The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
//Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
//Example 2:
//Input: nums = [-1,1]
//Output: [1,-1]
//Explanation:
//1 is the only positive integer and -1 the only negative integer in nums.
//So nums is rearranged to [1,-1].
// 
//Constraints:
//	2 <= nums.length <= 2 * 105
//	nums.length is even
//	1 <= |nums[i]| <= 105
//	nums consists of equal number of positive and negative integers.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* p1, * p2, * p3;
    int* p4, * p5, * p6;
    int* p7, * p8, * p9;
    int* p10, * p11, * p12;
    int* p13,* p14, * p15;
    p1 = malloc(sizeof(int) * numsSize);
    p2 = malloc(sizeof(int) * numsSize);
    p3 = malloc(sizeof(int) * numsSize);
    for (i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0; i < numsSize; i++) {
        if(nums[i] > 0) {
            p1[j++] = nums[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if(nums[i] < 0) {
            p2[k++] = nums[i];
        }
    }
    p13 = p1;
    p23 = p2;
    for (i = 0; i < numsSize; i++) {
        if(i % 2 == 0) {
            p3[l++] = p13[m++];
            p3[n++] = p23[o++];
        } else {
            p3[p++] = p23[q++];
            p3[r++] = p13[s++];
        }
    }
    for (i = 0; i < numsSize; i++) {
        nums[i] = p3[i];
    }
    return nums;
}