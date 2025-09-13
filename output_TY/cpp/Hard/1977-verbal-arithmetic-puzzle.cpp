/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//	Each character is decoded as one digit (0 - 9).
//	No two characters can map to the same digit.
//	Each words[i] and result are decoded as one number without leading zeros.
//	Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
// 
//Example 1:
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//Constraints:
//	2 <= words.length <= 5
//	1 <= words[i].length, result.length <= 7
//	words[i], result contain only uppercase English letters.
//	The number of different characters used in the expression is at most 10.
class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        int n = words.size();
        int m = result.size();
        int maxLen = max(m, n);
        vector<int> sum(maxLen, 0);
        vector<int> num(10, 0);
        for (int i = 0; i < n; i++) {
            int len = words[i].size();
            for (int j = 0; j < len; j++) {
                sum[j] += words[i][len - 1 - j] - 'A';
            }
        }
        int len = result.size();
        for (int i = 0; i < len; i++) {
            sum[i] += result[len - 1 - i] - 'A';
        }
        for (int i= 0; i < maxLen; i++) {
            if (sum[i] > 35) return false;
            if (sum[i] == 0) continue;
            for (int j = 0; j < 10; j++) {
                if (num[j] == 0 && sum[i] + j <= 35) {
                    num[j] = sum[i] + j;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int len = words[i].size();
            for (int j = 0; j < len; j++) {
                if (num[words[i][len - 1 - j] - 'A'] == 0) return false;
                words[i][len - 1 - j] = '0' + num[words[i][len - 1 - j] - 'A'];
            }
        }
        for (int i = 0; i < len; i++) {
            if (num[result[len - 1 - i] - 'A'] == 0) return false;
            result[len - 1- i] = '0' + num[result[len - 1 - i]];
        }
        return true;
    }
};