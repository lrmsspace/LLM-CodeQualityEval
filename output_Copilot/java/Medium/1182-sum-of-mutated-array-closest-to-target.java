/**https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/ */
//Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
//In case of a tie, return the minimum such integer.
//Notice that the answer is not neccesarilly a number from arr.
// 
//Example 1:
//Input: arr = [4,9,3], target = 10
//Output: 3
//Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
//Example 2:
//Input: arr = [2,3,5], target = 10
//Output: 5
//Example 3:
//Input: arr = [60864,25176,27249,21296,20204], target = 56803
//Output: 11361
// 
//Constraints:
//	1 <= arr.length <= 104
//	1 <= arr[i], target <= 105
class Solution {
    public int findBestValue(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;
        int[] prefix = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        int l = 0, r = arr[n - 1], ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int index = Arrays.binarySearch(arr, mid);
            if (index < 0) {
                index = -index - 1;
            }
            int cur = prefix[index] + (n - index) * mid;
            if (cur <= target) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int chooseSmall = check(arr, target, ans);
        int chooseBig = check(arr, target, ans + 1);
        return Math.abs(chooseSmall - target) <= Math.abs(chooseBig - target) ? ans : ans + 1;        
    }
}