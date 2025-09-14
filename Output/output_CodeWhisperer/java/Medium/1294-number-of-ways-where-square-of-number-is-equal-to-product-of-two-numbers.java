/**https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/ */
//Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:
//	Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
//	Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
// 
//Example 1:
//Input: nums1 = [7,4], nums2 = [5,2,8,9]
//Output: 1
//Explanation: Type 1: (1, 1, 2), nums1[1]2 = nums2[1] * nums2[2]. (42 = 2 * 8). 
//Example 2:
//Input: nums1 = [1,1], nums2 = [1,1,1]
//Output: 9
//Explanation: All Triplets are valid, because 12 = 1 * 1.
//Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]2 = nums2[j] * nums2[k].
//Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]2 = nums1[j] * nums1[k].
//Example 3:
//Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
//Output: 2
//Explanation: There are 2 valid triplets.
//Type 1: (3,0,2).  nums1[3]2 = nums2[0] * nums2[2].
//Type 2: (3,0,1).  nums2[3]2 = nums1[0] * nums1[1].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	1 <= nums1[i], nums2[i] <= 105
class Solution {
    public int numTriplets(int[] nums1, int[] nums2) {
        Map<Long, Integer> map1 = new HashMap<>();
        Map<Long, Integer> map2 = new HashMap<>();
        for (int num : nums1) {
            long square = (long)num * num;
            map1.put(square, map1.getOrDefault(square, 0) + 1);
        }
        for (int num : nums2) {
            long square = (long)num * num;
            map2.put(square, map2.getOrDefault(square, 0) + 1);
        }
        int res = 0;
        for (int i = 0; i < nums1.length; i++) {
            for (int j = i + 1; j < nums1.length; j++) {
                long product = (long)nums1[i] * nums1[j];
                res += map2.getOrDefault(product, 0) * 2;
            }
        }
        for (int i = 0; i < nums2.length; i++) {
            for (int j = i + 1; j < nums2.length; j++) {
                long product = (long)nums2[i] * nums2[j];
                res += map1.getOrDefault(product, 0) * 2;
            }
        }
        return res;       
    }
}