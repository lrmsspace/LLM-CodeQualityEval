/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
char* longestDupSubstring(char* s) {
    int n = strlen(s);
    int* nums = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        nums[i] = s[i] - 'a';
    }

    int a = 26;

    long mod = 1000000007;

    int left = 1, right = n;


    while (left <= right) {
        int mid = left + (right - left) / 2;

        long h = 1;

        for (int i = 0; i < mid; ++i) {
            h = (h * a) % mod;
        }

        long currentHash = 0;

        unordered_set<long> seen;

        for (int i = 0; i < n; ++i) {
            currentHash = (currentHash * a + nums[i]) % mod;

            if (i >= mid) {
                currentHash = (currentHash - nums[i - mid] * h % mod + mod) % mod;
            }

            if (i >= mid - 1) {
                if (seen.find(currentHash) != seen.end()) {
                    return strndup(s + i - mid + 1, mid);
                }

                seen.insert(currentHash);
            }
        }

        if (currentHash != 0) {
            return strndup(s + n - mid, mid);
        }

        right = mid - 1;
    }

    return strdup("");  
    
}