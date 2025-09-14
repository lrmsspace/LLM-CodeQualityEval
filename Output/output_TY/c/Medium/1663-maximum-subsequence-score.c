/**https://leetcode.com/problems/maximum-subsequence-score/ */
//You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
//For chosen indices i0, i1, ..., ik - 1, your score is defined as:
//	The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
//	It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
//Return the maximum possible score.
//A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.
// 
//Example 1:
//Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
//Output: 12
//Explanation: 
//The four possible subsequence scores are:
//- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
//- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
//- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
//- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
//Therefore, we return the max score, which is 12.
//Example 2:
//Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
//Output: 30
//Explanation: 
//Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
// 
//Constraints:
//	n == nums1.length == nums2.length
//	1 <= n <= 105
//	0 <= nums1[i], nums2[j] <= 105
//	1 <= k <= n
long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k){
    int i, j, n = nums1Size, m = nums2Size;
    int* p = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        p[i] = i;
    qsort(p, n, sizeof(int), [](const void* a, const void* b) { return nums2[*(int*)a] - nums2[*(int*)b]; });
    for (i = 0; i < n; i++)
        nums2[p[i]] = i;
    int* q = (int*)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++)
        q[i] = i;
    qsort(q, m, sizeof(int), [](const void* a, const void* b) { return nums1[*(int*)a] - nums1[*(int*)b]; });
    for (i = 0; i < m; i++)
        nums1[q[i]] = i;
    long long ans = 0;
    for (i = 0; i < k; i++)
        ans += nums1[q[i]] * nums2[p[i]];
    ans = ans * nums2[p[i - 1]];
    for (i = k; i < m;i++) {
        if (nums2[p[i]] > nums2[p[i - 1]]) {
            ans -= nums1[q[i - k]] * nums2[p[i - 1]];
            ans += nums1[q[i]] * nums2[p[i - 1]];
            ans = ans * nums2[p[i]];
        }
    }
    return ans;
}