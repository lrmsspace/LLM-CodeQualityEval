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
        int left = 0, right = 100000, sum = 0, res = 0, min = Integer.MAX_VALUE;
        for (int i : arr) {
            sum += i;
            right = Math.max(right, i);
        }
        while (left <= right) {
            int mid = (left + right) / 2, temp = 0;
            for (int i : arr) {
                temp += Math.min(i, mid);
            }
            if (temp >= target) {
                if (temp - target < min) {
                    min = temp - target;
                    res = mid;
                } else if (temp - target == min) {
                    res = Math.min(res, mid);
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;      
    }
}