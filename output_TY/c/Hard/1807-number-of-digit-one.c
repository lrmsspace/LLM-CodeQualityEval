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
int countDigitOne(int n){
    int res = 0;
    long long base = 1;
    while (n / base > 0){
        int digit = n / (base * 10);
        int last = n % (base * 10);
        int first = n / base - digit * base;
        if (last < base){
            res += digit * (first + 1) * base;
        }
        else if (last == base){
            res +=digit * (first + 1) * base + first + 1;
        }
    }
    return res;
}