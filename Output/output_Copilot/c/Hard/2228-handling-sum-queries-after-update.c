/**https://leetcode.com/problems/handling-sum-queries-after-update/ */
//You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:
//	For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. Both l and r are 0-indexed.
//	For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
//	For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
//Return an array containing all the answers to the third type queries.
// 
//Example 1:
//Input: nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
//Output: [3]
//Explanation: After the first query nums1 becomes [1,1,1]. After the second query, nums2 becomes [1,1,1], so the answer to the third query is 3. Thus, [3] is returned.
//Example 2:
//Input: nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
//Output: [5]
//Explanation: After the first query, nums2 remains [5], so the answer to the second query is 5. Thus, [5] is returned.
// 
//Constraints:
//	1 <= nums1.length,nums2.length <= 105
//	nums1.length = nums2.length
//	1 <= queries.length <= 105
//	queries[i].length = 3
//	0 <= l <= r <= nums1.length - 1
//	0 <= p <= 106
//	0 <= nums1[i] <= 1
//	0 <= nums2[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* handleQuery(int* nums1, int nums1Size, int* nums2, int nums2Size, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    long long *res = (long long *)malloc(sizeof(long long) * queriesSize);
    int i, j, k, l, r, p, sum = 0;
    for (i = 0; i < queriesSize; i++) {
        if (queries[i][0] == 1) {
            l = queries[i][1];
            r = queries[i][2];
            for (j = l; j <= r; j++) {
                if (nums1[j] == 0) {
                    nums1[j] = 1;
                } else {
                    nums1[j] = 0;
                }
            }
        } else if (queries[i][0] == 2) {
            p = queries[i][1];
            for (j = 0; j < nums2Size; j++) {
                nums2[j] += nums1[j] * p;
            }
        } else {
            for (j = 0; j < nums2Size; j++) {
                sum += nums2[j];
            }
            res[i] = sum;
            sum = 0;
        }
    }
    *returnSize = queriesSize;
    return res;    
}