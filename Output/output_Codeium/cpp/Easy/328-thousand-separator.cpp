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
        string res = to_string(n);
        int count = 0;
        for (int i = res.size() - 1; i > 0; i--) {
            if (++count % 3 == 0) res.insert(i, 1, '.')
        }
        return res;
    }
};