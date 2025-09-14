/*
 Given a string s and an integer k, partition s into k substrings such that the letter changes needed to make each substring a semi-palindrome are minimized.
 Return the minimum number of letter changes required.
 A semi-palindrome is a special type of string that can be divided into palindromes based on a repeating pattern. To check if a string is a semi-palindrome:​
 Choose a positive divisor d of the string's length. d can range from 1 up to, but not including, the string's length. For a string of length 1, it does not have a valid divisor as per this definition, since the only divisor is its length, which is not allowed.
 For a given divisor d, divide the string into groups where each group contains characters from the string that follow a repeating pattern of length d. Specifically, the first group consists of characters at positions 1, 1 + d, 1 + 2d, and so on; the second group includes characters at positions 2, 2 + d, 2 + 2d, etc.
 The string is considered a semi-palindrome if each of these groups forms a palindrome.
 Consider the string "abcabc":
 The length of "abcabc" is 6. Valid divisors are 1, 2, and 3.
 For d = 1: The entire string "abcabc" forms one group. Not a palindrome.
 For d = 2:
 Group 1 (positions 1, 3, 5): "acb"
 Group 2 (positions 2, 4, 6): "bac"
 Neither group forms a palindrome.
 For d = 3:
 Group 1 (positions 1, 4): "aa"
 Group 2 (positions 2, 5): "bb"
 Group 3 (positions 3, 6): "cc"
 All groups form palindromes. Therefore, "abcabc" is a semi-palindrome.
 Example 1: 
 Input:   s = "abcac", k = 2 
 Output:   1 
 Explanation:  Divide s into "ab" and "cac". "cac" is already semi-palindrome. Change "ab" to "aa", it becomes semi-palindrome with d = 1.
 Example 2: 
 Input:   s = "abcdef", k = 2 
 Output:   2 
 Explanation:  Divide s into substrings "abc" and "def". Each needs one change to become semi-palindrome.
 Example 3: 
 Input:   s = "aabbaa", k = 3 
 Output:   0 
 Explanation:  Divide s into substrings "aa", "bb" and "aa". All are already semi-palindromes.
 Constraints:
 2 <= s.length <= 200
 1 <= k <= s.length / 2
 s contains only lowercase English letters.
*/

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX_LEN 201
#define INF 0x3f3f3f3f

// 检查一个长度是否是另一个数的因子
int isDivisor(int len, int d) {
    return len % d == 0;
}

// 计算将子串变成半回文串所需的最小操作次数
int calcSemiPalindromeChanges(char* s, int start, int len) {
    if (len == 1) return 0;
    
    int minChanges = INF;
    
    // 尝试所有可能的除数d
    for (int d = 1; d < len; d++) {
        if (!isDivisor(len, d)) continue;
        
        int changes = 0;
        int groupSize = len / d;
        
        // 对于每个组检查是否为回文
        for (int i = 0; i < d; i++) {
            // 收集当前组的所有字符
            char group[MAX_LEN];
            int idx = 0;
            
            for (int j = 0; j < groupSize; j++) {
                group[idx++] = s[start + i + j * d];
            }
            
            // 检查组是否为回文
            for (int l = 0, r = groupSize - 1; l < r; l++, r--) {
                if (group[l] != group[r]) {
                    changes++;
                }
            }
        }
        
        minChanges = MIN(minChanges, changes);
    }
    
    return minChanges;
}

int minimumChanges(char* s, int k) {
    int n = strlen(s);
    
    // dp[i][j]表示将前i个字符分成j段的最小操作次数
    int dp[MAX_LEN][MAX_LEN];
    // cost[i][j]表示将子串s[i...j]变成半回文串的最小操作次数
    int cost[MAX_LEN][MAX_LEN];
    
    // 初始化dp数组
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    
    // 预计算所有可能子串的cost
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cost[i][j-1] = calcSemiPalindromeChanges(s, i, j - i);
        }
    }
    
    // 动态规划
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= MIN(i, k); j++) {
            if (j == 1) {
                dp[i][j] = cost[0][i-1];
                continue;
            }
            
            // 尝试所有可能的分割点
            for (int last = j-1; last < i; last++) {
                dp[i][j] = MIN(dp[i][j], 
                             dp[last][j-1] + cost[last][i-1]);
            }
        }
    }
    
    return dp[n][k];
}
