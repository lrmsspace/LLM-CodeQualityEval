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
        int n = digits.size();
        int sum = 0;
        int mod[3] = {0};
        for (int i = 0; i < n; i++) {
            sum += digits[i];
            mod[digits[i] % 3]++;
        }
        while (sum % 3 != 0) {
            if (sum % 3 == 1) {
                if (mod[1] > 0) {
                    mod[1]--;
                    sum -= 1;
                } else {
                    mod[2]--;
                    sum -= 2;
                }
            } else {
                if (mod[2] > 0) {
                    mod[2]--;
                    sum -= 2;
                } else {
                    mod[1]--;
                    sum -= 1;
                }
            }
        }
        string res = "";
        if (mod[0] == 0 && sum == 0) {
            return res;
        }
        for (int i = 9; i >= 0; i--) {
            if (i % 3 == 0) {
                for (int j = 0; j < mod[0]; j++) {
                    res += '0' + i;
                }
            } else if (i % 3 == 1) {
                for (int j = 0; j < mod[1]; j++) {
                    res += '0' + i;
                }
            } else {
                for (int j = 0; j < mod[2]; j++) {
                    res += '0' + i;
                }
            }
        }
        if (res[0] == '0') {
            return "0";
        } else {
            return res;
    
            //return res;
        }
    }
};