/*
 You are given two strings s and t, both of which are anagrams of each other, and an integer k.
 Your task is to determine whether it is possible to split the string s into k equal-sized substrings, rearrange the substrings, and concatenate them in any order to create a new string that matches the given string t.
 Return true if this is possible, otherwise, return false.
 An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
 A substring is a contiguous non-empty sequence of characters within a string.
 Example 1:
 Input: s = "abcd", t = "cdab", k = 2
 Output: true
 Explanation:
 Split s into 2 substrings of length 2: ["ab", "cd"].
 Rearranging these substrings as ["cd", "ab"], and then concatenating them results in "cdab", which matches t.
 Example 2:
 Input: s = "aabbcc", t = "bbaacc", k = 3
 Output: true
 Explanation:
 Split s into 3 substrings of length 2: ["aa", "bb", "cc"].
 Rearranging these substrings as ["bb", "aa", "cc"], and then concatenating them results in "bbaacc", which matches t.
 Example 3:
 Input: s = "aabbcc", t = "bbaacc", k = 2
 Output: false
 Explanation:
 Split s into 2 substrings of length 3: ["aab", "bcc"].
 These substrings cannot be rearranged to form t = "bbaacc", so the output is false.
 Constraints:
 1 <= s.length == t.length <= 2 * 105
 1 <= k <= s.length
 s.length is divisible by k.
 s and t consist only of lowercase English letters.
 The input is generated such that s and t are anagrams of each other.
*/

bool isPossibleToRearrange(char* s, char* t, int k) {

    // Create a frequency array for s
    int freq[26] = {0};
    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }
    
    // Count the number of characters in t that have a frequency greater than 0
    int count = 0;
    for (int i = 0; t[i]; i++) {
        if (freq[t[i] - 'a'] > 0) {
            count++;
        }
    }
    
    // If there are more than k distinct characters in t, it is not possible to rearrange s into k equal-sized substrings
    if (count > k) {
        return false;
    }
    
    // Create a priority queue to store the characters in t with their frequencies
    priority_queue<pair<int, char>> pq;
    for (int i = 0; t[i]; i++) {
        pq.push({freq[t[i] - 'a'], t[i]});
    }
    
    // Create a deque to store the rearranged substrings
    deque<string> substrings;
    while (!pq.empty()) {   
        // Pop the character with the highest frequency from the priority queue
        pair<int, char> top = pq.top();
        pq.pop();
        
        // Create a substring of length k and add it to the deque
        string substring(k, top.second);
        substrings.push_back(substring);
        
        // Decrement the frequency of the character
        top.first--;
        
        // If the frequency of the character is greater than 0, push it back into the priority queue
        if (top.first > 0) {
            pq.push(top);
        }
    }
    
    // Concatenate the rearranged substrings to form a new string
    string result;
    for (auto& substring : substrings) {
        result += substring;
    }
    
    // Check if the new string matches t
    return result == t; 
    
}