/*
 You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
 If the character is 'z', replace it with the string "ab".
 Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
 Return the length of the resulting string after exactly t transformations.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: s = "abcyy", t = 2
 Output: 7
 Explanation:
 First Transformation (t = 1):
 'a' becomes 'b'
 'b' becomes 'c'
 'c' becomes 'd'
 'y' becomes 'z'
 'y' becomes 'z'
 String after the first transformation: "bcdzz"
 Second Transformation (t = 2):
 'b' becomes 'c'
 'c' becomes 'd'
 'd' becomes 'e'
 'z' becomes "ab"
 'z' becomes "ab"
 String after the second transformation: "cdeabab"
 Final Length of the string: The string is "cdeabab", which has 7 characters.
 Example 2:
 Input: s = "azbk", t = 1
 Output: 5
 Explanation:
 First Transformation (t = 1):
 'a' becomes 'b'
 'z' becomes "ab"
 'b' becomes 'c'
 'k' becomes 'l'
 String after the first transformation: "babcl"
 Final Length of the string: The string is "babcl", which has 5 characters.
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters.
 1 <= t <= 105
*/
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        long long zCount = 0;
        long long nonZCount = 0;
        
        // Count initial z's and non-z's
        for(char c : s) {
            if(c == 'z') zCount++;
            else nonZCount++;
        }
        
        // For each transformation
        while(t--) {
            // Previous z's become "ab" pairs
            long long newZCount = nonZCount; // Count of new z's from previous non-z chars
            long long newNonZCount = (zCount * 2) % MOD; // Each z becomes "ab"
            
            // Update counts for next iteration
            zCount = newZCount;
            nonZCount = newNonZCount;
        }
        
        // Final length is sum of z's and non-z's
        return (zCount + nonZCount) % MOD;
    }
};                    
