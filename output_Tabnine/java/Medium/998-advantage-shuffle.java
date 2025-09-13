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
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> nums2[a[0]]));
        for (int i = 0; i < n; i++) {
            pq.offer(new int[]{i, nums1[i]});
        }
        
        Arrays.sort(nums2);
        
        int[] res = new int[n];
        int left = 0, right = n - 1;
        while (!pq.isEmpty()) {
            int[] pair = pq.poll();
            int i = pair[0];
            int num = pair[1];
            if (nums2[left] > num) {
                res[i] = nums2[left++];
            } else {
                res[i] = nums2[right--];
            }
        }
        
        return res;
        
    }
}