/*
 Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 Example 1:
 Input: s = "bcbbbcba"
 Output: 4
 Explanation:
 The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 Example 2:
 Input: s = "aaaa"
 Output: 2
 Explanation:
 The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 Constraints:
 2 <= s.length <= 100
 s consists only of lowercase English letters.
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        
        while(j < n){
            mp[s[j]]++;
            
            while(mp.size() > 2){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            
            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
        
    }
};