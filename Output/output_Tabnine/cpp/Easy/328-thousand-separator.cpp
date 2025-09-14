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
public:
    string thousandSeparator(int n) {
        string result = "";
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (result.size() > 0 && result.size() % 3 == 0) {
                result = "." + result;
            }
            result = to_string(digit) + result;
        }
        return result.size() > 0? result : "0";  // If n is 0, return "0" directly.
        
    }
};