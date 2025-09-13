/*
 Given a string s, find the sum of the 3 largest unique prime numbers that can be formed using any of its substrings.
 Return the sum of the three largest unique prime numbers that can be formed. If fewer than three exist, return the sum of all available primes. If no prime numbers can be formed, return 0.
 Note: Each prime number should be counted only once, even if it appears in multiple substrings. Additionally, when converting a substring to an integer, any leading zeros are ignored.
 Example 1:
 Input: s = "12234"
 Output: 1469
 Explanation:
 The unique prime numbers formed from the substrings of "12234" are 2, 3, 23, 223, and 1223.
 The 3 largest primes are 1223, 223, and 23. Their sum is 1469.
 Example 2:
 Input: s = "111"
 Output: 11
 Explanation:
 The unique prime number formed from the substrings of "111" is 11.
 Since there is only one prime number, the sum is 11.
 Constraints:
 1 <= s.length <= 10
 s consists of only digits.
*/

long long sumOfLargestPrimes(char* s) {
    int n = strlen(s);  
    int prime[10] = {0};
    prime[2] = prime[3] = prime[5] = prime[7] = 1;
    for (int i = 4; i < 10; i += 2) prime[i] = 0;
    for (int i = 9; i >= 0; i--) {
        if (prime[i]) {
            for (int j = 2 * i; j < 10; j += i) prime[j] = 0;
        }
    }
    long long ans = 0;  
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = i; j < n; j++) {
            num = num * 10 + (s[j] - '0');
            if (prime[num]) ans += num;
        }
    }
    return ans;

}