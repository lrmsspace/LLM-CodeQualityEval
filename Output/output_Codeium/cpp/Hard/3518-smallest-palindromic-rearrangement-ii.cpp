/*
 You are given a palindromic string s and an integer k.
 Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
 Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
 Example 1:
 Input: s = "abba", k = 2
 Output: "baab"
 Explanation:
 The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
 Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
 Example 2:
 Input: s = "aa", k = 2
 Output: ""
 Explanation:
 There is only one palindromic rearrangement: "aa".
 The output is an empty string since k = 2 exceeds the number of possible rearrangements.
 Example 3:
 Input: s = "bacab", k = 1
 Output: "abcba"
 Explanation:
 The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
 Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 Constraints:
 1 <= s.length <= 104
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
 1 <= k <= 106
*/

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        unordered_map<char, int> char_count;
        for (char c : s) {
            char_count[c]++;
        }

        string half = "", middle = "";
        for (auto &[ch, count] : char_count) {
            if (count % 2 == 1) {
                middle += ch;
            }
            half += string(count / 2, ch);
        }

        if (middle.size() > 1) {
            return "";
        }

        sort(half.begin(), half.end());

        set<string> permutations;
        do {
            string pal = half + middle + string(half.rbegin(), half.rend());
            permutations.insert(pal);
        } while (next_permutation(half.begin(), half.end()));

        if (k > permutations.size()) {
            return "";
        }

        auto it = permutations.begin();
        advance(it, k - 1);
        return *it;

    }
};