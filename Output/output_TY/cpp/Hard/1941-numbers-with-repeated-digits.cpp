/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int res = 0, len = s.size();
        for (int i = 1; i < len; i++)
            res += 9 * perm(9, i - 1);
        unordered_set<int> st;
        for (int i = 0; i < len; i++)
        {
            int low = i == 0 ? 1 : 0, high = s[i] - '0';
            for (int j = low; j <= high; j++)
                if (st.find(j) != st.end())
                    res += perm(high - j, len - i - 1);
            st.insert(s[i] - '0');
            if (i > 0 && s[i -1] == s[i])
                return res;
        }
        return n - res;
    }
};