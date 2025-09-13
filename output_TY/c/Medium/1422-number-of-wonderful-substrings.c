/**https://leetcode.com/problems/number-of-wonderful-substrings/ */
//A wonderful string is a string where at most one letter appears an odd number of times._x000D_
//_x000D_
//_x000D_
//	For example, "ccjjc" and "abab" are wonderful, but "ab" is not._x000D_
//_x000D_
//_x000D_
//Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately._x000D_
//_x000D_
//A substring is a contiguous sequence of characters in a string._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: word = "aba"_x000D_
//Output: 4_x000D_
//Explanation: The four wonderful substrings are underlined below:_x000D_
//- "aba" -> "a"_x000D_
//- "aba" -> "b"_x000D_
//- "aba" -> "a"_x000D_
//- "aba" -> "aba"_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: word = "aabb"_x000D_
//Output: 9_x000D_
//Explanation: The nine wonderful substrings are underlined below:_x000D_
//- "aabb" -> "a"_x000D_
//- "aabb" -> "aa"_x000D_
//- "aabb" -> "aab"_x000D_
//- "aabb" -> "aabb"_x000D_
//- "aabb" -> "a"_x000D_
//- "aabb" -> "abb"_x000D_
//- "aabb" -> "b"_x000D_
//- "aabb" -> "bb"_x000D_
//- "aabb" -> "b"_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: word = "he"_x000D_
//Output: 2_x000D_
//Explanation: The two wonderful substrings are underlined below:_x000D_
//- "he" -> "h"_x000D_
//- "he" -> "e"_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= word.length <= 105_x000D_
//	word consists of lowercase English letters from 'a' to 'j'._x000D_
long long wonderfulSubstrings(char * word){
    int n = strlen(word);
    long long ans = 0;
    int mask = 0;
    for (int i = 0; i < n; i++) {
        int x = word[i] - 'a';
        mask ^= 1 << x;
        ans += __builtin_popcount(mask) + 1;
        for (int j = 0; j < 10; j++) {
            ans +=__builtin_popcount(mask ^ (1 << j));
        }
    }
    return ans;
}