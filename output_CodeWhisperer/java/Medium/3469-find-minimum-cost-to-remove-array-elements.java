/*
import java.util.PriorityQueue;
 You are given an integer array nums. Your task is to remove all elements from the array by performing one of the following operations at each step until nums is empty:
 Choose any two elements from the first three elements of nums and remove them. The cost of this operation is the maximum of the two elements removed.
 If fewer than three elements remain in nums, remove all the remaining elements in a single operation. The cost of this operation is the maximum of the remaining elements.
 Return the minimum cost required to remove all the elements.
 Example 1:
 Input: nums = [6,2,8,4]
 Output: 12
 Explanation:
 Initially, nums = [6, 2, 8, 4].
 In the first operation, remove nums[0] = 6 and nums[2] = 8 with a cost of max(6, 8) = 8. Now, nums = [2, 4].
 In the second operation, remove the remaining elements with a cost of max(2, 4) = 4.
 The cost to remove all elements is 8 + 4 = 12. This is the minimum cost to remove all elements in nums. Hence, the output is 12.
 Example 2:
 Input: nums = [2,1,3,3]
 Output: 5
 Explanation:
 Initially, nums = [2, 1, 3, 3].
 In the first operation, remove nums[0] = 2 and nums[1] = 1 with a cost of max(2, 1) = 2. Now, nums = [3, 3].
 In the second operation remove the remaining elements with a cost of max(3, 3) = 3.
 The cost to remove all elements is 2 + 3 = 5. This is the minimum cost to remove all elements in nums. Hence, the output is 5.
 Constraints:
 1 <= nums.length <= 1000
 1 <= nums[i] <= 106
*/

class Solution {
    public int minCost(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int num : nums) {
            pq.offer(num);
        }

        int cost = 0;
        while (pq.size() > 2) {
            int first = pq.poll();
            int second = pq.poll();
            int third = pq.poll();
            cost += first + second;
            pq.offer(third);
        }

        while (!pq.isEmpty()) {
            cost += pq.poll();
        }

        return cost;
            
    }
}