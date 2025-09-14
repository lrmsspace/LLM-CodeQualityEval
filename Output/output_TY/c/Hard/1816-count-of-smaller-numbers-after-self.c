/**https://leetcode.com/problems/count-of-smaller-numbers-after-self/ */
//Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
// 
//Example 1:
//Input: nums = [5,2,6,1]
//Output: [2,1,1,0]
//Explanation:
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.
//Example 2:
//Input: nums = [-1]
//Output: [0]
//Example 3:
//Input: nums = [-1,-1]
//Output: [0,0]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize){
    int i, j, k, l, r, m, n, p, q, *a, *b, *c, *d, *e, *f, *g, *h, *s;
    a = (int*)malloc(sizeof(int) * numsSize);
    b = (int*)malloc(sizeof(int) * numsSize);
    c = (int*)malloc(sizeof(int) * numsSize);
   d = (int*)malloc(sizeof(int));
   e = (int*)malloc(sizeof(int));
   f = (int*)malloc(sizeof(int));
   g = (int*)malloc(sizeof(int));
   h = (int*)malloc(sizeof(int));
   s = (int*)malloc(sizeof(int) * numsSize);
   for (i = 0; i < numsSize; i++) {
       a[i] = nums[i];
       b[i] = nums[i];
   }
   qsort(b, numsSize, sizeof(int), cmp);
   for (i = 0; i < numsSize; i++) {
       j = bsearch(&a[i], b, numsSize, sizeof(int), cmp);
       s[i] = j;
   }
   for (i = 0; i < numsSize; i++) {
       printf("%d ", s[i]);
  }
   return s;
}