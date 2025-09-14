/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.
// 
//Example 1:
//Input: n = 1
//Output: true
//Example 2:
//Input: n = 10
//Output: false
// 
//Constraints:
//	1 <= n <= 109
bool reorderedPowerOf2(int n) {
    int count[10] = {0};
    while (n) {
        count[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 31; i++) {
        int tmp = 1 << i;
        int tmpCount[10] = {0};
        while (tmp) {
            tmpCount[tmp % 10]++;
            tmp /= 10;
        }
        int j = 0;
        for (; j < 10; j++) {
            if (count[j] != tmpCount[j]) {
                break;
            }
        }
        if (j == 10) {
            return true;
        }
    }
    return false;    
}