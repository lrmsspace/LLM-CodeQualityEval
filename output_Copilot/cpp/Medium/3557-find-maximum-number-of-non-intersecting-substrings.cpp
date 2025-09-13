/*
 You are given a string word.
 Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
 Example 1:
 Input: word = "abcdeafdef"
 Output: 2
 Explanation:
 The two substrings are "abcdea" and "fdef".
 Example 2:
 Input: word = "bcdaaaab"
 Output: 1
 Explanation:
 The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<int> first(26, -1), last(26, -1);
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int idx = word[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int idx = word[i] - 'a';
            if (last[idx] - first[idx] >= 3) {
                count++;
                for (int j = first[idx]; j <= last[idx]; ++j) {
                    visited[j] = true;
                }
            }
        }

        return count;        
    }
};