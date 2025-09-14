/*
 You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
 Example 1:
 Input: n = 10, t = 2
 Output: 10
 Explanation:
 The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
 Example 2:
 Input: n = 15, t = 3
 Output: 16
 Explanation:
 The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.
 Constraints:
 1 <= n <= 100
 1 <= t <= 10
*/

class Solution {
    public int smallestNumber(int n, int t) {

        // Convert the number to a string for easy manipulation
        String numStr = String.valueOf(n);
        int minNumber = n;
        int product = 1;
        boolean found = false;  
        // Iterate through each digit in the number
        for (char digit : numStr.toCharArray()) {
            int digitValue = Character.getNumericValue(digit);
            // Calculate the product of the current digit and the current product
            product *= digitValue;
            // If the product is divisible by t, update the smallest number and mark the found flag
            if (product % t == 0) {
                minNumber = Math.min(minNumber, Integer.parseInt(numStr.replace(String.valueOf(digit), "")));
                found = true;
                break;
            }
        }
        // If no digit product is divisible by t, append the smallest digit possible to the number
        if (!found) {
            minNumber = Math.min(minNumber, Integer.parseInt(numStr + String.valueOf(t - 1)));
        }
        return minNumber;
        
    }
}