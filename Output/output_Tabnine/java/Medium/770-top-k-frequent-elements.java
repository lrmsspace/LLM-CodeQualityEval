/**https://leetcode.com/problems/top-k-frequent-elements/ */
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	k is in the range [1, the number of unique elements in the array].
//	It is guaranteed that the answer is unique.
// 
//Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(Map.Entry::getValue).reversed());
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            pq.offer(entry);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = pq.poll().getKey();
        }
        
        return result;
        
    }
}