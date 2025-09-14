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
        if(n == 0) return "0";
        string res = "";
        int count = 0;
        while(n){
            if(count == 3){
                res = "." + res;
                count = 0;
            }
            res = to_string(n % 10) + res;
            n /= 10;
            count++;
        }
        return res;        
    }
};