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
        int ans = 0;
        int i = 0;
        while(i < n){
            int j = i;
            set<char> st;
            while(j < n && st.find(word[j]) == st.end()){
                st.insert(word[j]);
                j++;
            }
            ans++;
            i = j;
        }
        return ans;
        
    }
};