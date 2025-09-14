/*
 You are given an array nums consisting of positive integers.
 We call two integers x and y in this problem almost equal if both integers can become equal after performing the following operation at most once:
 Choose either x or y and swap any two digits within the chosen number.
 Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.
 Note that it is allowed for an integer to have leading zeros after performing an operation.
 Example 1:
 Input: nums = [3,12,30,17,21]
 Output: 2
 Explanation:
 The almost equal pairs of elements are:
 3 and 30. By swapping 3 and 0 in 30, you get 3.
 12 and 21. By swapping 1 and 2 in 12, you get 21.
 Example 2:
 Input: nums = [1,1,1,1,1]
 Output: 10
 Explanation:
 Every two elements in the array are almost equal.
 Example 3:
 Input: nums = [123,231]
 Output: 0
 Explanation:
 We cannot swap any two digits of 123 or 231 to reach the other.
 Constraints:
 2 <= nums.length <= 100
 1 <= nums[i] <= 106
*/
class Solution {
    public int countPairs(int[] nums) {
        int count = 0;
        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++) {
                if(isAlmostEqual(nums[i], nums[j])) {
                    count++;
                }
            }
        }
        return count;
    }
    
    private boolean isAlmostEqual(int num1, int num2) {
        if(num1 == num2) return true;
        
        // Convert numbers to char arrays for easier digit manipulation
        char[] arr1 = String.valueOf(num1).toCharArray();
        char[] arr2 = String.valueOf(num2).toCharArray();
        
        // If lengths are different, they can't be almost equal
        if(arr1.length != arr2.length) return false;
        
        // Try swapping each pair of digits in num1
        for(int i = 0; i < arr1.length; i++) {
            for(int j = i + 1; j < arr1.length; j++) {
                // Swap digits
                char temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
                
                // Check if equal after swap
                if(String.valueOf(arr1).equals(String.valueOf(arr2))) {
                    return true;
                }
                
                // Swap back
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
        
        // Try swapping each pair of digits in num2
        for(int i = 0; i < arr2.length; i++) {
            for(int j = i + 1; j < arr2.length; j++) {
                // Swap digits
                char temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
                
                // Check if equal after swap
                if(String.valueOf(arr1).equals(String.valueOf(arr2))) {
                    return true;
                }
                
                // Swap back
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
        
        return false;
    }
}                    
   