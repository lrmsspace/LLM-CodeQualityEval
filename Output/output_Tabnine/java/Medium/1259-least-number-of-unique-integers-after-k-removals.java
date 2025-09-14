/**https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/ */
//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
// 
//Example 1:
//Input: arr = [5,5,4], k = 1
//Output: 1
//Explanation: Remove the single 4, only 5 is left.
//Example 2:
//Input: arr = [4,3,1,1,3,3,2], k = 3
//Output: 2
//Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
// 
//Constraints:
//	1 <= arr.length <= 10^5
//	1 <= arr[i] <= 10^9
//	0 <= k <= arr.length
class Solution {

    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : arr) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> count.get(b) - count.get(a));
        pq.addAll(count.keySet());
        int uniqueCount = count.size();
        while (k > 0 &&!pq.isEmpty()) {
            int num = pq.poll();
            if (count.get(num) > 1) {
                count.put(num, count.get(num) - 1);
                uniqueCount--;
            }
            k--;
        }
        return uniqueCount;

        

    }

}