/*
 Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
 Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
 You are given a string word, which represents the final output displayed on Alice's screen.
 Return the total number of possible original strings that Alice might have intended to type.
 Example 1:
 Input: word = "abbcccc"
 Output: 5
 Explanation:
 The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".
 Example 2:
 Input: word = "abcd"
 Output: 1
 Explanation:
 The only possible string is "abcd".
 Example 3:
 Input: word = "aaaa"
 Output: 4
 Constraints:
 1 <= word.length <= 100
 word consists only of lowercase English letters.
*/

/**
 * @param {string} word
 * @return {number}
 */
var possibleStringCount = function(word) {
    // Initialize a set to store unique original strings
    const originalStrings = new Set();

    // Function to generate all possible original strings by removing one character at a time
    const generateOriginalStrings = (current, index) => {
        if (index === word.length) {
            originalStrings.add(current);
            return;
        }

        // Include the current character
        generateOriginalStrings(current + word[index], index + 1);

        // Exclude the current character (simulate pressing it too long)
        if (current.length > 0) {
            generateOriginalStrings(current, index + 1);
        }
    };

    // Start generating original strings from an empty string and index 0
    generateOriginalStrings("", 0);

    // Return the count of unique original strings
    return originalStrings.size;
    
};