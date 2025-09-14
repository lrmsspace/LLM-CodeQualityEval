/**https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/ */
//Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
//An integer y is a power of three if there exists an integer x such that y == 3x.
// 
//Example 1:
//Input: n = 12
//Output: true
//Explanation: 12 = 31 + 32
//Example 2:
//Input: n = 91
//Output: true
//Explanation: 91 = 30 + 32 + 34
//Example 3:
//Input: n = 21
//Output: false
// 
//Constraints:
//	1 <= n <= 107
bool checkPowersOfThree(int n) {
    int powers[20] = {1};
    int index = 0;
    int sum = 0;
    while (powers[index] <= n) {
        sum += powers[index];
        if (sum == n) {
            return true;
        }
        if (sum > n) {
            return false;
        }
        powers[++index] = powers[index - 1] * 3;
    }

    return false;
    
}