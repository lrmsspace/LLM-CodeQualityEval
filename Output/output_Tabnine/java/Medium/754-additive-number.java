/**https://leetcode.com/problems/additive-number/ */
//An additive number is a string whose digits can form an additive sequence.
//A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//Given a string containing only digits, return true if it is an additive number or false otherwise.
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
// 
//Example 1:
//Input: "112358"
//Output: true
//Explanation: 
//The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
//1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//Example 2:
//Input: "199100199"
//Output: true
//Explanation: 
//The additive sequence is: 1, 99, 100, 199. 
//1 + 99 = 100, 99 + 100 = 199
// 
//Constraints:
//	1 <= num.length <= 35
//	num consists only of digits.
// 
//Follow up: How would you handle overflow for very large input integers?
class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        for (int i = 1; i <= n / 2; i++) {
            for (int j = i + 1; j <= n - i; j++) {
                long first = Long.parseLong(num.substring(0, i));
                long second = Long.parseLong(num.substring(i, j));
                long sum = first + second;
                StringBuilder sb = new StringBuilder();
                sb.append(first).append("+").append(second);
                int k = j;
                while (k < n) {
                    long next = sum;
                    sum = first + second;
                    first = second;
                    second = next;
                    sb.append("+").append(second);
                    if (!sb.toString().equals(num.substring(j, k + 1))) break;
                    k++;
                }
                if (k == n) return true;
            }
        }
        return false;
        
    }
}