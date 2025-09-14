/**https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/ */
//You are given two integer arrays nums1 and nums2 of equal length n and an integer k. You can perform the following operation on nums1:
//	Choose two indexes i and j and increment nums1[i] by k and decrement nums1[j] by k. In other words, nums1[i] = nums1[i] + k and nums1[j] = nums1[j] - k.
//nums1 is said to be equal to nums2 if for all indices i such that 0 <= i < n, nums1[i] == nums2[i].
//Return the minimum number of operations required to make nums1 equal to nums2. If it is impossible to make them equal, return -1.
// 
//Example 1:
//Input: nums1 = [4,3,1,4], nums2 = [1,3,7,1], k = 3
//Output: 2
//Explanation: In 2 operations, we can transform nums1 to nums2.
//1st operation: i = 2, j = 0. After applying the operation, nums1 = [1,3,4,4].
//2nd operation: i = 2, j = 3. After applying the operation, nums1 = [1,3,7,1].
//One can prove that it is impossible to make arrays equal in fewer operations.
//Example 2:
//Input: nums1 = [3,8,5,2], nums2 = [2,4,1,6], k = 1
//Output: -1
//Explanation: It can be proved that it is impossible to make the two arrays equal.
// 
//Constraints:
//	n == nums1.length == nums2.length
//	2 <= n <= 105
//	0 <= nums1[i], nums2[j] <= 109
//	0 <= k <= 105
class Solution {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[] count1 = new int[6 * n + 1];
        int[] count2 = new int[6 * n + 1];
        for (int num : nums1) {
            count1[num]++;
        }
        for (int num : nums2) {
            count2[num]++;
        }
        int sum1 = Arrays.stream(nums1).sum();
        int sum2 = Arrays.stream(nums2).sum();
        if (sum1 == sum2) {
            return 0;
        }
        int diff = Math.abs(sum1 - sum2);
        long res = Long.MAX_VALUE;
        for (int i = 1; i <= 6 * n; i++) {
            int j = i + k;
            if (j > 6 * n) {
                break;
            }
            int cnt = 0;
            if (sum1 < sum2) {
                for (int num = 1; num <= 6 * n; num++) {
                    int need = (j - num) * count1[num];
                    if (need <= 0) {
                        continue;
                    }
                    int give = (num - i) * count2[num];
                    if (give <= 0) {
                        continue;
                    }
                    int use = Math.min(need, give);
                    cnt += use;
                    need -= use;
                    give -= use;
                    if (need > 0) {
                        cnt += need;
                    }
                }
            } else {
                for (int num = 1; num <= 6 * n; num++) {
                    int need = (num - i) * count1[num];
                    if (need <= 0) {
                        continue;
                    }
                    int give = (j - num) * count2[num];
                    if (give <= 0) {
                        continue;
                    }
                    int use = Math.min(need, give);
                    cnt += use;
                    need -= use;
                    give -= use;
                    if (need > 0) {
                        cnt += need;
                    }
                }
            }
            if (cnt >= diff) {
                res = Math.min(res, (long) i * (cnt - diff));
            }
        }
        return res == Long.MAX_VALUE ? -1 : res;       
    }
}