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

        int MOD = 1000000007;

        Stack<Integer> stack = new Stack<>();

        long sumOfMinimums = 0;

        // initialize previousLess and nextLess less than length of the array
        int[] prevLess = new int[arr.length];
        int[] nextLess = new int[arr.length];

        // find previousLess
        for (int i = 0; i < arr.length; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                stack.pop();
            }

            prevLess[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        // empty the stack
        stack.clear();

        // find nextLess
        for (int i = arr.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }

            nextLess[i] = stack.isEmpty() ? arr.length : stack.peek();
            stack.push(i);
        }

        // calculate sum of minimums
        for (int i = 0; i < arr.length; i++) {
            sumOfMinimums += (i - prevLess[i]) * (nextLess[i] - i) % MOD * arr[i] % MOD;
            sumOfMinimums %= MOD;
        }

        return (int) (sumOfMinimums);
    }
}