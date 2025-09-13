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

int maxSubstrings(char* word) {
    int n = strlen(word);
    std::vector<std::pair<int, int>> substrings;

    // Find all valid substrings
    for (int i = 0; i < n; i++) {
        for (int j = i + 3; j < n; j++) {
            if (word[i] == word[j]) {
                substrings.push_back({i, j});
            }
        }
    }

    // Sort substrings by their ending index
    std::sort(substrings.begin(), substrings.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    // Find the maximum number of non-intersecting substrings
    int count = 0;
    int lastEnd = -1;
    for (const auto& [start, end] : substrings) {
        if (start > lastEnd) {
            count++;
            lastEnd = end;
        }
    }

    return count;
}