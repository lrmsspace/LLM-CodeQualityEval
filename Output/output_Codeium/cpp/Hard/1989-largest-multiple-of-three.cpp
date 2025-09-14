/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
// 
//Example 1:
//Input: digits = [8,1,9]
//Output: "981"
//Example 2:
//Input: digits = [8,6,7,1,0]
//Output: "8760"
//Example 3:
//Input: digits = [1]
//Output: ""
// 
//Constraints:
//	1 <= digits.length <= 104
//	0 <= digits[i] <= 9
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int count[10] = {0};
        int sum = 0;
        for (int d : digits) {
            count[d]++;
            sum += d;
        }
        if (sum % 3 == 1) {
            for (int i = 1; i < 10; i += 3) {
                if (count[i] > 0) {
                    count[i]--;
                    sum -= i;
                    break;
                }
            }
        }
        if (sum % 3 == 2) {
            for (int i = 2; i < 10; i += 3) {
                if (count[i] > 0) {
                    count[i]--;
                    sum -= i;
                    break;
                }
            }
            if (sum % 3 != 0) {
                for (int i = 1; i < 10; i += 3) {
                    if (count[i] >= 2) {
                        count[i] -= 2;
                        sum -= 2 * i;
                        break;
                    }
                }
            }
        }
        string ans;
        for (int i = 9; i >= 0; i--) {
            while (count[i]-- > 0) {
                ans += to_string(i);
            }
        }
        return ans.empty() ? "" : ans;
    }
};