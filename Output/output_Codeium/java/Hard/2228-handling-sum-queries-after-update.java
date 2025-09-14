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
class Solution {
    public long[] handleQuery(int[] nums1, int[] nums2, int[][] queries) {
        int n = nums1.length;
        int[] bit1 = new int[n+1], bit2 = new int[n+1];
        for (int i = 0; i < n; i++) {
            update(bit1, i+1, nums1[i]);
            update(bit2, i+1, nums2[i]);
        }
        
        List<Long> res = new ArrayList<>();
        for (int[] q : queries) {
            if (q[0] == 1) {
                for (int i = q[1]; i <= q[2]; i++) {
                    update(bit1, i+1, 1-update(bit1, i+1));
                }
            } else if (q[0] == 2) {
                for (int i = 0; i < n; i++) {
                    update(bit2, i+1, query(bit2, i+1) + query(bit1, i+1)*q[1]);
                }
            } else {
                res.add((long)query(bit2, n));
            }
        }
        return res.stream().mapToLong(Long::longValue).toArray();
        
    }
    
    private void update(int[] bit, int i, int x) {
        while (i < bit.length) {
            bit[i] += x;
            i += i&-i;
        }
    }
    
    private int query(int[] bit, int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i&-i;
        }
        return res;
    }
    }
}