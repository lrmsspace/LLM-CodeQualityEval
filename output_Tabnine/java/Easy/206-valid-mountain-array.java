/**https://leetcode.com/problems/valid-mountain-array/ */
//Given an array of integers arr, return true if and only if it is a valid mountain array.
//Recall that arr is a mountain array if and only if:
//	arr.length >= 3
//	There exists some i with 0 < i < arr.length - 1 such that:
//	
//		arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
//		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//	
//	
// 
//Example 1:
//Input: arr = [2,1]
//Output: false
//Example 2:
//Input: arr = [3,5,5]
//Output: false
//Example 3:
//Input: arr = [0,3,2,1]
//Output: true
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 104
class Solution {
    public boolean validMountainArray(int[] arr) {
        int i = 0;
        // Find the peak element
        while (i + 1 < arr.length && arr[i] < arr[i + 1]) {
            i++;
        }
        // If peak element is not found or it is the first or last element, then it's not a mountain array
        if (i == 0 || i == arr.length - 1) {
            return false;
        }
        // Check if the array after the peak element is strictly decreasing
        for (int j = i + 1; j < arr.length; j++) {
            if (arr[j] <= arr[j - 1]) {
                return false;
            }
        }
        return true;
        
    }
}