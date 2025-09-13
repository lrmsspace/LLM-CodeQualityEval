/**https://leetcode.com/problems/ugly-number-iii/ */
//An ugly number is a positive integer that is divisible by a, b, or c.
//Given four integers n, a, b, and c, return the nth ugly number.
// 
//Example 1:
//Input: n = 3, a = 2, b = 3, c = 5
//Output: 4
//Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
//Example 2:
//Input: n = 4, a = 2, b = 3, c = 4
//Output: 6
//Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
//Example 3:
//Input: n = 5, a = 2, b = 11, c = 13
//Output: 10
//Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
// 
//Constraints:
//	1 <= n, a, b, c <= 109
//	1 <= a * b * c <= 1018
//	It is guaranteed that the result will be in range [1, 2 * 109].
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<long long> ugly(n, 0);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; i++) {
            ugly[i] = min({ugly[i2] * a, ugly[i3] * b, ugly[i5] * c});
            if (ugly[i] == ugly[i2] * a) i2++;
            if (ugly[i] == ugly[i3] * b) i3++;
            if (ugly[i] == ugly[i5] * c) i5++;
        }
        
        return ugly[n - 1];
        
    }
};