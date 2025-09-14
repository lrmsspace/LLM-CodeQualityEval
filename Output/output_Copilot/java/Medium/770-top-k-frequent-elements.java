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
        // Create a frequency map to count the occurrences of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Create a priority queue (min-heap) to store the top k frequent elements
        PriorityQueue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<>(
            (a, b) -> a.getValue() - b.getValue()
        );

        // Add entries to the min-heap
        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            minHeap.offer(entry);
            if (minHeap.size() > k) {
                minHeap.poll(); // Remove the least frequent element
            }
        }

        // Extract the top k frequent elements from the min-heap
        int[] result = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            result[i] = minHeap.poll().getKey();
        }

        return result;        
    }
}