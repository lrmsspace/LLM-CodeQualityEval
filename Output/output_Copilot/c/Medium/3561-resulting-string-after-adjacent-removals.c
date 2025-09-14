/*
 You are given a string s consisting of lowercase English letters.
 You must repeatedly perform the following operation while the string s has at least two consecutive characters:
 Remove the leftmost pair of adjacent characters in the string that are consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and 'a').
 Shift the remaining characters to the left to fill the gap.
 Return the resulting string after no more operations can be performed.
 Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.
 Example 1:
 Input: s = "abc"
 Output: "c"
 Explanation:
 Remove "ab" from the string, leaving "c" as the remaining string.
 No further operations are possible. Thus, the resulting string after all possible removals is "c".
 Example 2:
 Input: s = "adcb"
 Output: ""
 Explanation:
 Remove "dc" from the string, leaving "ab" as the remaining string.
 Remove "ab" from the string, leaving "" as the remaining string.
 No further operations are possible. Thus, the resulting string after all possible removals is "".
 Example 3:
 Input: s = "zadb"
 Output: "db"
 Explanation:
 Remove "za" from the string, leaving "db" as the remaining string.
 No further operations are possible. Thus, the resulting string after all possible removals is "db".
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters.
*/

char* resultingString(char* s) {
    std::stack<char> stk;
    for (int i = 0; s[i]; i++) {
        if (!stk.empty() && (abs(stk.top() - s[i]) == 1 || (stk.top() == 'a' && s[i] == 'z') || (stk.top() == 'z' && s[i] == 'a'))) ) {
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }

    // Rebuild the resulting string
    std::string result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    std::reverse(result.begin(), result.end());
    char* res = (char*)malloc(result.size() + 1);
    strcpy(res, result.c_str());
    return res;
}