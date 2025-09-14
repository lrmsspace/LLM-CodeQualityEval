/*
 You are given two integers, l and r, represented as strings, and an integer b. Return the count of integers in the inclusive range [l, r] whose digits are in non-decreasing order when represented in base b.
 An integer is considered to have non-decreasing digits if, when read from left to right (from the most significant digit to the least significant digit), each digit is greater than or equal to the previous one.
 Since the answer may be too large, return it modulo 109 + 7.
 Example 1:
 Input: l = "23", r = "28", b = 8
 Output: 3
 Explanation:
 The numbers from 23 to 28 in base 8 are: 27, 30, 31, 32, 33, and 34.
 Out of these, 27, 33, and 34 have non-decreasing digits. Hence, the output is 3.
 Example 2:
 Input: l = "2", r = "7", b = 2
 Output: 2
 Explanation:
 The numbers from 2 to 7 in base 2 are: 10, 11, 100, 101, 110, and 111.
 Out of these, 11 and 111 have non-decreasing digits. Hence, the output is 2.
 Constraints:
 1 <= l.length <= r.length <= 100
 2 <= b <= 10
 l and r consist only of digits.
 The value represented by l is less than or equal to the value represented by r.
 l and r do not contain leading zeros.
*/

class Solution {
public:
    int countNumbers(string l, string r, int b) {
        int ans = 0;
        for (int i = l.size() - 1; i >= 0; i--) {
            int d = l[i] - '0';
            for (int j = i - 1; j >= 0; j--) {
                int d2 = l[j] - '0';
                if (d2 > d) break;
                d = d2;
                for (int k = j - 1; k >= 0; k--) {
                    int d3 = l[k] - '0';
                    if (d3 > d2) break;
                    d2 = d3;
                    for (int m = k - 1; m >= 0; m--) {
                        int d4 = l[m] - '0';
                        if (d4 > d3) break;
                        d3 = d4;
                        for (int n = m - 1; n >= 0; n--) {
                            int d5 = l[n] - '0';
                            if (d5 > d4) break;
                            d4 = d5;
                            for (int o = n - 1; o >= 0; o--) {
                                int d6 = l[o] - '0';
                                if (d6 > d5) break;
                                d5 = d6;
                                for (int p = o - 1; p >= 0; p--) {
                                    int d7 = l[p] - '0';
}
                            }
                        }
}
                }
            }
        }
        return ans;
        
    }
};