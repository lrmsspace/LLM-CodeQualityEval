/**https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/ */
//You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
//Return the maximum possible length of s.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: arr = ["un","iq","ue"]
//Output: 4
//Explanation: All the valid concatenations are:
//- ""
//- "un"
//- "iq"
//- "ue"
//- "uniq" ("un" + "iq")
//- "ique" ("iq" + "ue")
//Maximum length is 4.
//Example 2:
//Input: arr = ["cha","r","act","ers"]
//Output: 6
//Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
//Example 3:
//Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
//Output: 26
//Explanation: The only string in arr has all 26 characters.
// 
//Constraints:
//	1 <= arr.length <= 16
//	1 <= arr[i].length <= 26
//	arr[i] contains only lowercase English letters.
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> masks(n, 0);
        for(int i = 0; i < n; i++){
            for(auto ch : arr[i]){
                int bit = ch - 'a';
                if(masks[i] & (1 << bit)) return 0;
                masks[i] |= (1 << bit);
            }
        }
        int ans = 0;
        for(int i = 0; i < (1 << n); i++){
            int mask = 0;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)) mask |= masks[j];
            }
            if(mask == (1 << 26) - 1) ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};