/**https://leetcode.com/problems/adding-two-negabinary-numbers/ */
//Given two numbers arr1 and arr2 in base -2, return the result of adding them together.
//Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.
//Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.
// 
//Example 1:
//Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
//Output: [1,0,0,0,0]
//Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
//Example 2:
//Input: arr1 = [0], arr2 = [0]
//Output: [0]
//Example 3:
//Input: arr1 = [0], arr2 = [1]
//Output: [1]
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 1000
//	arr1[i] and arr2[i] are 0 or 1
//	arr1 and arr2 have no leading zeros
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int carry = 0;
        int n = Math.max(arr1.length, arr2.length);
        int[] result = new int[n + 1];
        
        for (int i = 0; i < n; i++) {
            int a = i < arr1.length? arr1[arr1.length - 1 - i] : 0;
            int b = i < arr2.length? arr2[arr2.length - 1 - i] : 0;
            
            int sum = a ^ b ^ carry;
            carry = (a & b) | (a & carry) | (b & carry);
            
            result[n - i - 1] = sum;
        }
        
        if (carry == 1) {
            result[0] = 1;
            return result;
        }
        
        int[] res = new int[result.length - 1];
        for (int i = 0; i < result.length - 1; i++) {
            res[i] = result[i + 1];
        }
        
        return res;
        
    }
}