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
        int sum = 0, count[10] = {0};
        for (int d : digits) {
            sum += d;
            count[d]++;
        }
        
        // Find the largest multiple of 3 that can be formed by using the digits
        int target = (sum / 3) * 3;
        int remain = sum % 3;
        string res = "";
        for (int i = 9; i >= 0; i--) {
            while (count[i] > 0 && target >= i) {
                res += to_string(i);
                count[i]--;
                target -= i;
            }
        }
        
        // Handle the remaining digits to form the largest multiple of 3
        if (remain == 1) {
            if (count[6] > 0) {
                res += '6';
                count[6]--;
            } else if (count[9] > 0) {
                res += '9';
                count[9]--;
            } else {
                res += '1';
            }
        } else if (remain == 2) {
            if (count[3] > 0 && count[6] > 0) {
                res += '63';
                count[3]--;
                count[6]--;
            } else if (count[3] > 0 && count[9] > 0) {
                res += '93';
                count[3]--;
                count[9]--;
            } else if (count[6] > 0 && count[9] > 0) {
                res += '69';
                count[6]--;
                count[9]--;
            } else {
                res += '12';
            }
        }
        
        // Remove unnecessary leading zeros
        while (!res.empty() && res[0] == '0') {
            res.erase(0, 1);
        }
        
        return res;

    }
};