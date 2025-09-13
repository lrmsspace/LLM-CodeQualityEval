/**https://leetcode.com/problems/next-greater-numerically-balanced-number/ */
//An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
//Given an integer n, return the smallest numerically balanced number strictly greater than n.
// 
//Example 1:
//Input: n = 1
//Output: 22
//Explanation: 
//22 is numerically balanced since:
//- The digit 2 occurs 2 times. 
//It is also the smallest numerically balanced number strictly greater than 1.
//Example 2:
//Input: n = 1000
//Output: 1333
//Explanation: 
//1333 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times. 
//It is also the smallest numerically balanced number strictly greater than 1000.
//Note that 1022 cannot be the answer because 0 appeared more than 0 times.
//Example 3:
//Input: n = 3000
//Output: 3133
//Explanation: 
//3133 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times.
//It is also the smallest numerically balanced number strictly greater than 3000.
// 
//Constraints:
//	0 <= n <= 106
class Solution {
public:
    int nextBeautifulNumber(int n) {
        string s = to_string(n);
        int m = s.size();
        int ans = -1;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (s[i] == s[j]) {
                    continue;
                }
                swap(s[i], s[j]);
                if (s[0] != '0') {
                    int x = stoi(s);
                    if (x > n && isBalanced(x)) {
                        if (ans == -1 || x < ans) {
                            ans = x;
                        }
                    }
                }
                swap(s[i], s[j]);
            }
        }
        return ans;        
    }
};