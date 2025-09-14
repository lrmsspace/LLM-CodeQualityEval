/**https://leetcode.com/problems/nth-magical-number/ */
//A positive integer is magical if it is divisible by either a or b.
//Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 1, a = 2, b = 3
//Output: 2
//Example 2:
//Input: n = 4, a = 2, b = 3
//Output: 6
// 
//Constraints:
//	1 <= n <= 109
//	2 <= a, b <= 4 * 104    
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nthMagicalNumber(int n, int a, int b) {
    const int MOD = 1e9 + 7;
    long long lcm = (long long)a / gcd(a, b) * b; // least common multiple
    long long low = 0, high = (long long)n * fmin(a, b);
    
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (mid / a + mid / b - mid / lcm < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low % MOD;
}

