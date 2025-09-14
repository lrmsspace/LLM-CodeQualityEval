/*
 You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:
 subs has a size of at least k.
 Character a has an odd frequency in subs.
 Character b has a non-zero even frequency in subs.
 Return the maximum difference.
 Note that subs can contain more than 2 distinct characters.
 Example 1:
 Input: s = "12233", k = 4
 Output: -1
 Explanation:
 For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.
 Example 2:
 Input: s = "1122211", k = 3
 Output: 1
 Explanation:
 For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.
 Example 3:
 Input: s = "110", k = 3
 Output: -1
 Constraints:
 3 <= s.length <= 3 * 104
 s consists only of digits '0' to '4'.
 The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
 1 <= k <= s.length
*/

int maxDifference(char* s, int k) {
    int freq[5] = {0}; // Frequency of characters '0' to '4'
    int n = strlen(s);
    int maxDiff = -1;

    for (int i = 0; i <= n - k; i++) {
        memset(freq, 0, sizeof(freq)); // Reset frequency array for each substring
        for (int j = i; j < i + k; j++) {
            freq[s[j] - '0']++;
        }

        int oddFreq = -1, evenFreq = -1;
        for (int d = 0; d < 5; d++) {
            if (freq[d] % 2 == 1) { // Odd frequency
                oddFreq = freq[d];
            } else if (freq[d] > 0 && freq[d] % 2 == 0) { // Non-zero even frequency
                evenFreq = freq[d];
            }
        }

        if (oddFreq != -1 && evenFreq != -1) {
            maxDiff = fmax(maxDiff, oddFreq - evenFreq);
        }
    }

    return maxDiff;    
}