/**https://leetcode.com/problems/find-the-difference-of-two-arrays/ */
//Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
//	answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
//	answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
//Note that the integers in the lists may be returned in any order.
// 
//Example 1:
//Input: nums1 = [1,2,3], nums2 = [2,4,6]
//Output: [[1,3],[4,6]]
//Explanation:
//For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
//For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
//Example 2:
//Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
//Output: [[3],[]]
//Explanation:
//For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
//Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	-1000 <= nums1[i], nums2[i] <= 1000
class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> result = new ArrayList<>();
        Map<Integer, Integer> countMap1 = new HashMap<>();
        Map<Integer, Integer> countMap2 = new HashMap<>();
        
        // Count the frequency of each number in nums1 and nums2
        for (int num : nums1) {
            countMap1.put(num, countMap1.getOrDefault(num, 0) + 1);
        }
        for (int num : nums2) {
            countMap2.put(num, countMap2.getOrDefault(num, 0) + 1);
        }
        
        // Find numbers in nums1 that are not present in nums2
        List<Integer> diff1 = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : countMap1.entrySet()) {
            if (!countMap2.containsKey(entry.getKey()) || entry.getValue()!= countMap2.get(entry.getKey())) {
                diff1.add(entry.getKey());
            }
        }
        
        // Find numbers in nums2 that are not present in nums1
        List<Integer> diff2 = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : countMap2.entrySet()) {
            if (!countMap1.containsKey(entry.getKey()) || entry.getValue()!= countMap1.get(entry.getKey())) {
                diff2.add(entry.getKey());
            }
        }
        
        result.add(diff1);
        result.add(diff2);
        
        return result;
        
    }
}