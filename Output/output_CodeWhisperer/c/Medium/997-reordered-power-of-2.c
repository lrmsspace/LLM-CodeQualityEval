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
    int temp = n;
    while (temp > 0) {
        count[temp % 10]++;
        temp /= 10;
    }
    int power = 1;
    for (int i = 0; i < 31; i++) {
        int temp = power;
        int count2[10] = {0};
        while (temp > 0) {
            count2[temp % 10]++;
            temp /= 10;
        }
        bool flag = true;
        for (int j = 0; j < 10; j++) {
            if (count[j] != count2[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
        power *= 2;
    }
    return false;
}