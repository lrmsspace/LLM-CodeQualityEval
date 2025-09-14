/**https://leetcode.com/problems/replace-the-substring-for-balanced-string/ */
//You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
//A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
//Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
// 
//Example 1:
//Input: s = "QWER"
//Output: 0
//Explanation: s is already balanced.
//Example 2:
//Input: s = "QQWE"
//Output: 1
//Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
//Example 3:
//Input: s = "QQQW"
//Output: 2
//Explanation: We can replace the first "QQ" to "ER". 
// 
//Constraints:
//	n == s.length
//	4 <= n <= 105
//	n is a multiple of 4.
//	s contains only 'Q', 'W', 'E', and 'R'.
int balancedString(char* s) {
    int n = strlen(s);
    int count[4] = {0};
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'Q': count[0]++; break;
            case 'W': count[1]++; break;
            case 'E': count[2]++; break;
            case 'R': count[3]++; break;
        }
    }
    int target = n / 4;
    if (count[0] <= target && count[1] <= target && count[2] <= target && count[3] <= target) {
        return 0;
    }
    int minLen = n;
    int left = 0;
    for (int right = 0; right < n; right++) {
        switch (s[right]) {
            case 'Q': count[0]--; break;
            case 'W': count[1]--; break;
            case 'E': count[2]--; break;
            case 'R': count[3]--; break;
        }
        while (count[0] <= target && count[1] <= target && count[2] <= target && count[3] <= target) {
            minLen = fmin(minLen, right - left + 1);
            switch (s[left]) {
                case 'Q': count[0]++; break;
                case 'W': count[1]++; break;
                case 'E': count[2]++; break;
                case 'R': count[3]++; break;
            }
            left++;
        }
    }
    return minLen;
}