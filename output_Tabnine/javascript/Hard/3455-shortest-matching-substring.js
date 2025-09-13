/*
 You are given a string s and a pattern string p, where p contains exactly two '*' characters.
 The '*' in p matches any sequence of zero or more characters.
 Return the length of the shortest substring in s that matches p. If there is no such substring, return -1.
 Note: The empty substring is considered valid.
 Example 1:
 Input: s = "abaacbaecebce", p = "ba*c*ce"
 Output: 8
 Explanation:
 The shortest matching substring of p in s is "baecebce".
 Example 2:
 Input: s = "baccbaadbc", p = "cc*baa*adb"
 Output: -1
 Explanation:
 There is no matching substring in s.
 Example 3:
 Input: s = "a", p = "**"
 Output: 0
 Explanation:
 The empty substring is the shortest matching substring.
 Example 4:
 Input: s = "madlogic", p = "*adlogi*"
 Output: 6
 Explanation:
 The shortest matching substring of p in s is "adlogi".
 Constraints:
 1 <= s.length <= 105
 2 <= p.length <= 105
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly two '*'.
*/

/**
 * @param {string} s
 * @param {string} p
 * @return {number}
 */
var shortestMatchingSubstring = function(s, p) {
    // Find the index of the first '*' in p
    let starIndex = p.indexOf('*');
    if (starIndex === -1) {
        return -1; // No '*' found in p
    }
    
    // Create a map to store the frequency of each character in p
    let pMap = new Map();
    for (let i = 0; i < p.length; i++) {
        if (p[i] === '*') {
            continue;
        }
        pMap.set(p[i], (pMap.get(p[i]) || 0) + 1);
    }
    
    // Create a map to store the frequency of each character in the current substring
    let currentMap = new Map();
    let count = 0;
    
    // Initialize the variables
    let start = 0;
    let minLength = Infinity;
    
    // Iterate through s
    for (let end = 0; end < s.length; end++) {
        let char = s[end];
        
        // Update the frequency of the current character in the current substring
        if (currentMap.has(char)) {
            currentMap.set(char, currentMap.get(char) + 1);
        } else {
            currentMap.set(char, 1);
        }
        
        // If the frequency of the current character in pMap is greater than or equal to the current frequency in currentMap,
        // increment the count
        if (pMap.has(char) && currentMap.get(char) >= pMap.get(char)) {
            count++;
        }
        
        // If the count of characters in pMap is equal to the number of '*' in p,
        // update the start index and calculate the length of the current substring
        if (count === p.match(/[*]/g).length) {
            while (start < end && currentMap.get(s[start]) < pMap.get(s[start])) {
                currentMap.set(s[start], currentMap.get(s[start]) - 1);
                start++;
            }
            
            let length = end - start + 1;
            if (length < minLength) {
                minLength = length;
            }
        }
    }
    return minLength === Infinity? -1 : minLength; // Return -1 if no matching substring is found
    
};