/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 500
 1 <= nums[i] <= 109
 0 <= k <= min(nums.length, 25)
*/

int maximumLength(int* nums, int numsSize, int k) {
    
    int i, j, n, m, kk, cnt, ans;
    int *a, *b, *c;
    
    a = (int *)malloc(numsSize * sizeof(int));
    b = (int *)malloc(numsSize * sizeof(int));
    c = (int *)malloc(numsSize * sizeof(int));
    
    for (i = 0; i < numsSize; i++) {
        a[i] = 1;
        b[i] = 1;
        c[i] = 1;
    }
    
    for (i = 0; i < numsSize; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0) {
                a[i] = max(a[i], a[j] + 1);
            }
}
    }
    for (i = numsSize - 1; i >= 0; i--) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] % nums[j] == 0) {
                b[i] = max(b[i], b[j] + 1);
            }
        }
    }
    return max(a[numsSize - 1], b[0]);
}