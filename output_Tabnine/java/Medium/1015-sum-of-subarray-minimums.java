/**https://leetcode.com/problems/sum-of-subarray-minimums/ */
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [3,1,2,4]
//Output: 17
//Explanation: 
//Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
//Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
//Sum is 17.
//Example 2:
//Input: arr = [11,81,94,43,3]
//Output: 444
// 
//Constraints:
//	1 <= arr.length <= 3 * 104
//	1 <= arr[i] <= 3 * 104
class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int mod = (int) 1e9 + 7;
        long[] leftMin = new long[n];
        long[] rightMin = new long[n];
        int[] leftIdx = new int[n];
        int[] rightIdx = new int[n];
        
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                rightIdx[stack.pop()] = i;
            }
            leftIdx[i] = stack.isEmpty()? -1 : stack.peek();
            stack.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                leftIdx[stack.pop()] = i;
            }
            rightMin[i] = stack.isEmpty()? n : stack.peek();
            stack.push(i);
        }
        
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + (long) arr[i] * (i - leftIdx[i]) * (rightMin[i] - i) % mod) % mod;
        }
        
        return (int) sum;
        
    }
}