/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.
// 
//Example 1:
//Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
//Output: [2,11,7,15]
//Example 2:
//Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
//Output: [24,32,8,12]
// 
//Constraints:
//	1 <= nums1.length <= 105
//	nums2.length == nums1.length
//	0 <= nums1[i], nums2[i] <= 109 
class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] result = new int[n];
        Arrays.sort(nums1);
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (a, b) -> nums2[a] - nums2[b]);
        int left = 0, right = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums1[right] > nums2[idx[i]]) {
                result[idx[i]] = nums1[right];
                right--;
            } else {
                result[idx[i]] = nums1[left];
                left++;
            }
        }
        return result;
        
    }
}