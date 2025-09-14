/**https://leetcode.com/problems/thousand-separator/ */
//Given an integer n, add a dot (".") as the thousands separator and return it in string format.
// 
//Example 1:
//Input: n = 987
//Output: "987"
//Example 2:
//Input: n = 1234
//Output: "1.234"
// 
//Constraints:
//	0 <= n <= 231 - 1
class Solution {
    public String thousandSeparator(int n) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        while (n > 0) {
            if (count > 0 && count % 3 == 0) {
                sb.append('.');
            }
            sb.append(n % 10);
            n /= 10;
            count++;
        }
        return sb.reverse().toString();        
    }
}