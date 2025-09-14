/*
 You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.
 A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
 Return the total number of good pairs.
 Example 1:
 Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1
 Output: 5
 Explanation:
 The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).
 Example 2:
 Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3
 Output: 2
 Explanation:
 The 2 good pairs are (3, 0) and (3, 1).
 Constraints:
 1 <= n, m <= 105
 1 <= nums1[i], nums2[j] <= 106
 1 <= k <= 103
*/

long long numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    long long count = 0;
    int max = 0;
    for (int i = 0; i < nums2Size; i++) {
        if (nums2[i] * k > max) {
            max = nums2[i] * k;
        }
    }
    int* hash = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < nums2Size; i++) {
        hash[nums2[i] * k]++;
    }
    for (int i = 0; i < nums1Size; i++) {
        int divisor = nums1[i];
        for (int j = 1; j <= max; j++) {
            if (divisor % j == 0) {
                count += hash[j];
            }
        }
    }
    free(hash);
    return count;    
}