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
    int len = strlen(s);
    int* primes = (int*)malloc(sizeof(int) * len);
    int primeCount = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            char* substr = (char*)malloc(sizeof(char) * (j - i + 2));
            strncpy(substr, s + i, j - i + 1);
            substr[j - i + 1] = '\0';

            int num = atoi(substr);
            if (num == 0) {
                free(substr);
                continue;
            }

            int isPrime = 1;
            for (int k = 2; k * k <= num; k++) {
                if (num % k == 0) {
                    isPrime = 0;
                    break;
                }
            }

            if (isPrime) {
                int isDuplicate = 0;
                for (int k = 0; k < primeCount; k++) {
                    if (primes[k] == num) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    primes[primeCount++] = num;
                }
            }

            free(substr);
        }
    }

    if (primeCount == 0) {
        free(primes);
        return 0;
    }

    qsort(primes, primeCount, sizeof(int), (int(*)(const void*, const void*))cmp);

    int sum = 0;
    for (int i = primeCount - 1; i >= primeCount - 3 && i >= 0; i--) {
        sum += primes[i];
    }

    free(primes);
    return sum;
}
        