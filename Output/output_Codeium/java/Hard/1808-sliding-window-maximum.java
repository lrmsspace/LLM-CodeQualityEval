/**https://leetcode.com/problems/sliding-window-maximum/ */
//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.
// 
//Example 1:
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [3,3,5,5,6,7]
//Explanation: 
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	1 <= k <= nums.length
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
Deque<Integer> deque = new ArrayDeque<>();
int n = nums.length;
int[] result = new int[n - k + 1];
for (int i = 0; i < n; i++) {
    // Remove elements not within the window
    if (!deque.isEmpty() && deque.peekFirst() == i - k) {
        deque.pollFirst();
    }
    // Remove elements smaller than the current element from the deque
    while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
        deque.pollLast();
    }
    // Add current element at the back of the deque
    deque.offerLast(i);
    // The front of the deque is the largest element for the current window
    if (i >= k - 1) {
        result[i - k + 1] = nums[deque.peekFirst()];
    }
}
return result;
    }
}