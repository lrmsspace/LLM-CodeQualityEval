/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// 
//Example 1:
//Input: n = 13
//Output: 6
//Example 2:
//Input: n = 0
//Output: 0
// 
//Constraints:
//	0 <= n <= 109
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        long long base = 1;
        while (n / base > 0)
        {
            int digit = n / (base * 10);
            int last = n % (base * 10);
            int first = n / base - digit * 10;
            if (last >= 0 && last < 10)
            {
                res += digit * base + last;
            }
            else if (last >= 10 && last < 20)
            {
                res += digit * base + 10 - 1;
            }
            else if (last >= 20 && last < 30)
            {
                res += digit * base + 20 -1;
            }
        }
        return res;
    }
};