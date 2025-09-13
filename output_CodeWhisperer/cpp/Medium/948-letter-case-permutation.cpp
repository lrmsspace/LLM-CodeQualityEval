/**https://leetcode.com/problems/letter-case-permutation/ */
//Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
//Return a list of all possible strings we could create. Return the output in any order.
// 
//Example 1:
//Input: s = "a1b2"
//Output: ["a1b2","a1B2","A1b2","A1B2"]
//Example 2:
//Input: s = "3z4"
//Output: ["3z4","3Z4"]
// 
//Constraints:
//	1 <= s.length <= 12 
//	s consists of lowercase English letters, uppercase English letters, and digits.
class Solution {
    public:
        vector<string> letterCasePermutation(string s) {
            queue<string> q;
            q.push("");
            
            for (int i = 0; i < s.length(); i++) {
                int size = q.size();
                
                for (int j = 0; j < size; j++) {
                    string current = q.front();
                    q.pop();
                    
                    if (isdigit(s[i])) {
                        // If it's a digit, just append it
                        q.push(current + s[i]);
                    } else {
                        // If it's a letter, append both lowercase and uppercase
                        q.push(current + (char)tolower(s[i]));
                        q.push(current + (char)toupper(s[i]));
                    }
                }
            }
            
            // Convert queue to vector
            vector<string> result;
            while (!q.empty()) {
                result.push_back(q.front());
                q.pop();
            }
            
            return result;
        }
    };
    