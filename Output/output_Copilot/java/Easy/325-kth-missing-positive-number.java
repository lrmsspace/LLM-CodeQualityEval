/**https://leetcode.com/problems/kth-missing-positive-number/ */
//Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
//Return the kth positive integer that is missing from this array.
// 
//Example 1:
//Input: arr = [2,3,4,7,11], k = 5
//Output: 9
//Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
//Example 2:
//Input: arr = [1,2,3,4], k = 2
//Output: 6
//Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
// 
//Constraints:
//	1 <= arr.length <= 1000
//	1 <= arr[i] <= 1000
//	1 <= k <= 1000
//	arr[i] < arr[j] for 1 <= i < j <= arr.length
// 
//Follow up:
//Could you solve this problem in less than O(n) complexity?
class Solution {
    public int findKthPositive(int[] arr, int k) {
        int missingCount = 0; // Count of missing positive integers
        int current = 1; // Current positive integer to check
        int index = 0; // Index for the arr array

        while (missingCount < k) {
            // If current is not in arr, increment missingCount
            if (index < arr.length && arr[index] == current) {
                index++; // Move to the next element in arr
            } else {
                missingCount++; // Increment the count of missing numbers
            }
            current++; // Move to the next positive integer
        }

        return current - 1; // Return the last positive integer checked before reaching k missing numbers        
    }
}