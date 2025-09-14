/**https://leetcode.com/problems/k-th-smallest-prime-fraction/ */
//You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
//For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
//Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
// 
//Example 1:
//Input: arr = [1,2,3,5], k = 3
//Output: [2,5]
//Explanation: The fractions to be considered in sorted order are:
//1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
//The third fraction is 2/5.
//Example 2:
//Input: arr = [1,7], k = 1
//Output: [1,7]
// 
//Constraints:
//	2 <= arr.length <= 1000
//	1 <= arr[i] <= 3 * 104
//	arr[0] == 1
//	arr[i] is a prime number for i > 0.
//	All the numbers of arr are unique and sorted in strictly increasing order.
//	1 <= k <= arr.length * (arr.length - 1) / 2
// 
//Follow up: Can you solve the problem with better than O(n2) complexity?
class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        int left = 0, right = 1;
        while (left < n - 1) {
            double maxFraction = 0.0;
            int maxI = left, maxJ = right;
            for (int j = right; j < n; j++) {
                double fraction = (double) arr[left] / arr[j];
                if (fraction > maxFraction) {
                    maxFraction = fraction;
                    maxI = left;
                    maxJ = j;
                }
            }
            if (--k == 0) {
                return new int[]{arr[maxI], arr[maxJ]};
            }
            if (right < n - 1 && (double) arr[left] / arr[right + 1] > maxFraction) {
                right++;
            } else {
                left++;
                right = left + 1;
            }
        }
        return new int[0]; // This line should never be reached        
    }
}