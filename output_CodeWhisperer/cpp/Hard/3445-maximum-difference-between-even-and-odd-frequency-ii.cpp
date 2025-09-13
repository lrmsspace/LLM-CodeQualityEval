/*
 You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:
 subs has a size of at least k.
 Character a has an odd frequency in subs.
 Character b has a non-zero even frequency in subs.
 Return the maximum difference.
 Note that subs can contain more than 2 distinct characters.
 Example 1:
 Input: s = "12233", k = 4
 Output: -1
 Explanation:
 For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.
 Example 2:
 Input: s = "1122211", k = 3
 Output: 1
 Explanation:
 For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.
 Example 3:
 Input: s = "110", k = 3
 Output: -1
 Constraints:
 3 <= s.length <= 3 * 104
 s consists only of digits '0' to '4'.
 The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
 1 <= k <= s.length
*/

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int max_diff = -1;
        for(int i = 0; i < n; i++){
            for(int j = i + k - 1; j < n; j++){
                unordered_map<char, int> freq;
                for(int l = i; l <= j; l++){
                    freq[s[l]]++;
                }
                int max_freq = 0;
                int min_freq = INT_MAX;
                for(auto it : freq){
                    if(it.second > max_freq && it.second % 2 != 0){
                        max_freq = it.second;
                    }
                    if(it.second < min_freq && it.second % 2 == 0 && it.second != 0){
                        min_freq = it.second;
                    }
                }
                if(max_freq != 0 && min_freq != INT_MAX){
                    max_diff = max(max_diff, max_freq - min_freq);
                }
            }
        }
        return max_diff;        
    }
};