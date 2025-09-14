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
    
    char s[10];
    sprintf(s, "%d", n);
    int arr[10] = {0};
    for (int i = 0; i < strlen(s); i++) {
        arr[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i] != 0) {
            int num = 0;
            for (int j = 0; j < 10; j++) {
                if (j != i) {
                    num += arr[j] * pow(10, arr[j]);
                }
            }
            if (pow(2, (int)log2(num)) == num) {
                return true;
            }
        }
    }
    return false;
}
