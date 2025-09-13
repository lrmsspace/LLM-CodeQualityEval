/**https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/ */
//You are given a list of strings of the same length words and a string target.
//Your task is to form target using the given words under the following rules:
//	target should be formed from left to right.
//	To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
//	Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
//	Repeat the process until you form the string target.
//Notice that you can use multiple characters from the same string in words provided the conditions above are met.
//Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: words = ["acca","bbbb","caca"], target = "aba"
//Output: 6
//Explanation: There are 6 ways to form target.
//"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
//"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
//"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
//"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
//"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
//"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
//Example 2:
//Input: words = ["abba","baab"], target = "bab"
//Output: 4
//Explanation: There are 4 ways to form target.
//"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
//"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
//"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
//"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 1000
//	All strings in words have the same length.
//	1 <= target.length <= 1000
//	words[i] and target contain only lowercase English letters.
#define MOD 1000000007

int numWays(char** words, int wordsSize, char* target) {
    int targetLen = strlen(target);
    if (targetLen == 0) return 1;
    if (wordsSize == 0) return 0;
    
    int wordLen = strlen(words[0]); // All words have the same length
    
    // Count the frequency of each character at each position in words
    int** freq = (int**)malloc(wordLen * sizeof(int*));
    for (int i = 0; i < wordLen; i++) {
        freq[i] = (int*)calloc(26, sizeof(int));
    }
    
    for (int j = 0; j < wordsSize; j++) {
        for (int i = 0; i < wordLen; i++) {
            freq[i][words[j][i] - 'a']++;
        }
    }
    
    // Use two arrays for DP to save space
    long long* dp_prev = (long long*)calloc(wordLen + 1, sizeof(long long));
    long long* dp_curr = (long long*)calloc(wordLen + 1, sizeof(long long));
    
    // Base case: empty target can be formed in 1 way
    for (int j = 0; j <= wordLen; j++) {
        dp_prev[j] = 1;
    }
    
    // Fill the dp table
    for (int i = 1; i <= targetLen; i++) {
        dp_curr[0] = 0; // Reset current row
        for (int j = 1; j <= wordLen; j++) {
            // Option 1: Don't use the current position j-1
            dp_curr[j] = dp_curr[j-1];
            
            // Option 2: Use the current position j-1 if it matches target[i-1]
            int targetChar = target[i-1] - 'a';
            if (freq[j-1][targetChar] > 0) {
                dp_curr[j] = (dp_curr[j] + (dp_prev[j-1] * (long long)freq[j-1][targetChar]) % MOD) % MOD;
            }
        }
        
        // Swap pointers for next iteration
        long long* temp = dp_prev;
        dp_prev = dp_curr;
        dp_curr = temp;
    }
    
    int result = dp_prev[wordLen];
    
    // Free memory
    for (int i = 0; i < wordLen; i++) {
        free(freq[i]);
    }
    free(freq);
    free(dp_prev);
    free(dp_curr);
    
    return result;
}
    