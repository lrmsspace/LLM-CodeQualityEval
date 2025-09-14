/**https://leetcode.com/problems/largest-palindrome-product/ */
//Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.
// 
//Example 1:
//Input: n = 2
//Output: 987
//Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
//Example 2:
//Input: n = 1
//Output: 9
// 
//Constraints:
//	1 <= n <= 8
class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1) return 9;
        long long maxNum = pow(10,n)-1;
        long long minNum = pow(10,n-1);
        for(long long i=maxNum;i>=minNum;i--){
            long long product = i*i;
            long long palindrome = product;
            long long temp = product;
            while(temp>0){
                palindrome = palindrome*10 + temp%10;
                temp /= 10;
            }
            for(long long j=maxNum;j>=minNum;j--){
                if(palindrome%j==0){
                    return palindrome%1337;
                }
            }
        }
        return -1;
    }
};