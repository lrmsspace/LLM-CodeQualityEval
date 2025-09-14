/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome.
// 
//Example 1:
//Input: s = "abccccdd"
//Output: 7
//Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
//Example 2:
//Input: s = "a"
//Output: 1
//Explanation: The longest palindrome that can be built is "a", whose length is 1.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase and/or uppercase English letters only.
int longestPalindrome(char* s) {
int count[128] = {0}; // Array to store character frequencies
int length = 0;
int hasOdd = 0;

// Count the frequency of each character in the string
for (int i = 0; s[i] != '\0'; i++) {
    count[s[i]]++;
}

// Calculate the length of the longest palindrome
for (int i = 0; i < 128; i++) {
    length += count[i] / 2 * 2; // Add the largest even number <= count[i]
    if (count[i] % 2 == 1) {
        hasOdd = 1; // Check if there is any odd frequency
    }
}

// If there is at least one odd frequency, we can place one extra character in the center
return length + hasOdd;

}