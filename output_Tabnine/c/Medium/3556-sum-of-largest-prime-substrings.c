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
    int primes[n+1];
    memset(primes, 0, sizeof(primes));
    
    for (int i = 0; i < n; i++) {
        int num = 0;
        while (s[i]!= '\0') {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        
        bool isPrime = true;
        for (int j = 2; j <= sqrt(num); j++) {
            if (num % j == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime && primes[num] == 0) {
            primes[num] = 1;
        }
    }
    
    int count = 0;
    for (int i = n; i >= 0; i--) {
        if (primes[i] == 1) {
            count++;
            if (count == 3) {
                return i;
            }
        }
    }
    return 0;
    
}