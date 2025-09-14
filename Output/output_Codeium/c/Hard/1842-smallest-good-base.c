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
    for (int k = log2(num) + 1; k >= 2; k--) {
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += pow(k, i);
        }
        if (sum == num) {
            char* ret = (char*)malloc(20);
            sprintf(ret, "%d", k);
            return ret;
        }
    }
    char* ret = (char*)malloc(20);
    sprintf(ret, "%lld", num);
    return ret;
}