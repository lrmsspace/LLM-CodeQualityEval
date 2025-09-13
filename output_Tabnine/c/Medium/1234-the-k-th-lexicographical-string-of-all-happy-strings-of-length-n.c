/**https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/ */
//A happy string is a string that:
//	consists only of letters of the set ['a', 'b', 'c'].
//	s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
//For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
//Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
//Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
// 
//Example 1:
//Input: n = 1, k = 3
//Output: "c"
//Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
//Example 2:
//Input: n = 1, k = 4
//Output: ""
//Explanation: There are only 3 happy strings of length 1.
//Example 3:
//Input: n = 3, k = 9
//Output: "cab"
//Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
// 
//Constraints:
//	1 <= n <= 10
//	1 <= k <= 100
char* getHappyString(int n, int k) {
    // Initialize a 3D array to store the count of each possible character at each position.
    int dp[n + 1][26][3] = {0};
    
    // Initialize the base cases.
    for (int i = 0; i < 3; i++) {
        dp[1][i][0] = 1;
    }
    
    // Calculate the count of each possible character at each position.
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            for (int prev = 0; prev < 3; prev++) {
                if (dp[i - 1][j][prev] > 0) {
                    for (int curr = 0; curr < 3; curr++) {
                        if (curr!= prev) {
                            dp[i][j][curr] += dp[i - 1][j][prev];
                        }
                    }
                }
            }
        }
    }
    
    // Calculate the total count of happy strings.
    int total = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 3; j++) {
            total += dp[n][i][j];
        }
    }
    
    // Check if k is within the valid range.
    if (k > total) {
        return "";
    }
    
    // Initialize an array to store the result.
    char result[n + 1] = {0};
    
    // Fill the result array in lexicographical order.
    for (int i = n - 1; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 3; k++) {
                if (dp[i + 1][j][k] > 0 && count + dp[i + 1][j][k] >= k) {
                    result[i] = 'a' + j;
                    dp[i + 1][j][k]--;
                    break;
                }
                count += dp[i + 1][j][k];
            }
        }
    }
    
    // Convert the result array to a string and return it.
    return result;
    
}