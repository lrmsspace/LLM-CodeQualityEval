/**https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/ */
//You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
//	Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
//	Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
//Return the lexicographically smallest string that can be written on the paper.
// 
//Example 1:
//Input: s = "zza"
//Output: "azz"
//Explanation: Let p denote the written string.
//Initially p="", s="zza", t="".
//Perform first operation three times p="", s="", t="zza".
//Perform second operation three times p="azz", s="", t="".
//Example 2:
//Input: s = "bac"
//Output: "abc"
//Explanation: Let p denote the written string.
//Perform first operation twice p="", s="c", t="ba". 
//Perform second operation twice p="ab", s="c", t="". 
//Perform first operation p="ab", s="", t="c". 
//Perform second operation p="abc", s="", t="".
//Example 3:
//Input: s = "bdda"
//Output: "addb"
//Explanation: Let p denote the written string.
//Initially p="", s="bdda", t="".
//Perform first operation four times p="", s="", t="bdda".
//Perform second operation four times p="addb", s="", t="".
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.
class Solution {
public:
string robotWithString(string s) {
    string t = "";      // Robot's string
    string paper = "";  // Result string written on paper
    
    // Create a frequency map to track minimum characters
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    // Find the smallest character in the remaining string
    auto getMin = [&]() {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                return 'a' + i;
            }
        }
        return 'z' + 1; // If no characters remain, return a sentinel value
    };
    
    // Process each character in s
    for (char c : s) {
        // Add current character to robot's string
        t.push_back(c);
        freq[c - 'a']--;
        
        // Get the minimum character in the remaining string
        char minChar = getMin();
        
        // If the top of t is lexicographically smaller than or equal to 
        // the minimum character in the remaining s, write it to paper
        while (!t.empty() && t.back() <= minChar) {
            paper.push_back(t.back());
            t.pop_back();
        }
    }
    
    // Empty the robot's string to the paper
    while (!t.empty()) {
        paper.push_back(t.back());
        t.pop_back();
    }
    
    return paper;
}
    
};
