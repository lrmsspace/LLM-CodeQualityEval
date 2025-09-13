/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
// 
//Example 1:
//Input: digits = [8,1,9]
//Output: "981"
//Example 2:
//Input: digits = [8,6,7,1,0]
//Output: "8760"
//Example 3:
//Input: digits = [1]
//Output: ""
// 
//Constraints:
//	1 <= digits.length <= 104
//	0 <= digits[i] <= 9
char* largestMultipleOfThree(int* digits, int digitsSize) {
    int cnt[10] = {0};
    int sum = 0;
    for (int i = 0; i < digitsSize; i++) {
        cnt[digits[i]]++;
        sum += digits[i];
    }
    if (sum % 3 == 1) {
        if (cnt[1] || cnt[4] || cnt[7]) {
            cnt[1] ? cnt[1]-- : (cnt[4] ? cnt[4]-- : cnt[7]--);
        } else {
            cnt[2] ? cnt[2]-- : cnt[5] ? cnt[5]-- : cnt[8]--;
            cnt[2] ? cnt[2]-- : cnt[5] ? cnt[5]-- : cnt[8]--;
        }
    }
    if (sum % 3 == 2) {
        if (cnt[2] || cnt[5] || cnt[8]) {
            cnt[2] ? cnt[2]-- : (cnt[5] ? cnt[5]-- : cnt[8]--);
        } else {
            cnt[1] ? cnt[1]-- : cnt[4] ? cnt[4]-- : cnt[7]--;
            cnt[1] ? cnt[1]-- : cnt[4] ? cnt[4]-- : cnt[7]--;
        }
    }
    char *ans = (char *)malloc(100000 * sizeof(char));
    int idx = 0;
    for (int i = 9; i >= 0; i--) {
        while (cnt[i]--) {
            ans[idx++] = i + '0';
        }
    }
    ans[idx] = '\0';
    return ans;
}
