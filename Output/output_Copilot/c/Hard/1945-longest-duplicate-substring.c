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
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        nums[i] = s[i] - 'a';
    }
    int base = 26;
    int mod = 1e9 + 7;
    int left = 1, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        long long hash = 0, p = 1;
        for (int i = 0; i < mid; i++) {
            hash = (hash * base + nums[i]) % mod;
            p = p * base % mod;
        }
        bool found = false;
        unordered_map<long long, vector<int>> map;
        map[hash].push_back(0);
        for (int i = 1; i + mid <= n; i++) {
            hash = (hash * base - nums[i - 1] * p % mod + mod) % mod;
            hash = (hash + nums[i + mid - 1]) % mod;
            if (map.count(hash)) {
                for (int j : map[hash]) {
                    if (strncmp(s + i, s + j, mid) == 0) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
            map[hash].push_back(i);
        }
        if (found) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    char* result = (char*)malloc((left + 1) * sizeof(char));
    strncpy(result, s + left - 1, left);
    result[left] = '\0';
    return result;    
}