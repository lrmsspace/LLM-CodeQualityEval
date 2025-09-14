/**https://leetcode.com/problems/smallest-good-base/ */
//Given an integer n represented as a string, return the smallest good base of n.
//We call k >= 2 a good base of n, if all digits of n base k are 1's.
// 
//Example 1:
//Input: n = "13"
//Output: "3"
//Explanation: 13 base 3 is 111.
//Example 2:
//Input: n = "4681"
//Output: "8"
//Explanation: 4681 base 8 is 11111.
//Example 3:
//Input: n = "1000000000000000000"
//Output: "999999999999999999"
//Explanation: 1000000000000000000 base 999999999999999999 is 11.
// 
//Constraints:
//	n is an integer in the range [3, 1018].
//	n does not contain any leading zeros.
char* smallestGoodBase(char* n) {
    long long num = atoll(n);
    long long left = 2, right = num, mid, ans = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        long long power = 1, base = 2;
        while (power <= num) {
            if (power == num) {
                ans = mid;
                break;
            }
            power *= base;
            base++;
        }
        if (power > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    char* result = (char*)malloc(20);
    sprintf(result, "%lld", ans);
    return result;
    
}