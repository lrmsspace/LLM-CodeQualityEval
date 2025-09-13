/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeInvalidParentheses(char* s, int* returnSize) {
    int n = strlen(s);
    bool left[n], right[n];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            cnt++;
            left[i] = (cnt > 0);
        } else if (s[i] == ')') {
            if (cnt > 0) {
                cnt--;
            }
            right[i] = (cnt == 0);
        }
    }
    cnt = 0;
    vector<string> res;
    for (int i = 0; i < n; i++) {
        if ((s[i] == '(' && !left[i]) || (s[i] == ')' && !right[i])) {
            continue;
        }
        if (s[i] == '(') {
            cnt++;
        } else if (s[i] == ')') {
            cnt--;
        }
        if (cnt == 0) {
            string t(s);
            t.erase(t.begin() + i);
            res.push_back(t);
        }
    }
    *returnSize = res.size();
    char** ans = (char**)malloc(res.size() * sizeof(char*));
    for (int i = 0; i < res.size(); i++) {
        ans[i] = (char*)malloc(res[i].size() + 1);
        strcpy(ans[i], res[i].c_str());
    }
    return ans;
}