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
        string s = to_string(n);
        string ans = "";
        int cnt = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            ans = s[i] + ans;
            cnt++;
            if(cnt == 3 && i != 0){
                ans = "." + ans;
                cnt = 0;
            }
        }
        return ans;
    }
};