/*
 A word is considered valid if:
 It contains a minimum of 3 characters.
 It contains only digits (0-9), and English letters (uppercase and lowercase).
 It includes at least one vowel.
 It includes at least one consonant.
 You are given a string word.
 Return true if word is valid, otherwise, return false.
 Notes:
 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
 A consonant is an English letter that is not a vowel.
 Example 1:
 Input: word = "234Adas"
 Output: true
 Explanation:
 This word satisfies the conditions.
 Example 2:
 Input: word = "b3"
 Output: false
 Explanation:
 The length of this word is fewer than 3, and does not have a vowel.
 Example 3:
 Input: word = "a3$e"
 Output: false
 Explanation:
 This word contains a '$' character and does not have a consonant.
 Constraints:
 1 <= word.length <= 20
 word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
*/

class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false; // Must be at least 3 characters long
        }

        boolean hasVowel = false;
        boolean hasConsonant = false;

        for (char c : word.toCharArray()) {
            if (Character.isDigit(c)) {
                continue; // Digits are allowed
            }
            if (Character.isLetter(c)) {
                char lowerC = Character.toLowerCase(c);
                if ("aeiou".indexOf(lowerC) >= 0) {
                    hasVowel = true; // Found a vowel
                } else {
                    hasConsonant = true; // Found a consonant
                }
            } else {
                return false; // Invalid character found
            }
        }

        return hasVowel && hasConsonant; // Must have at least one vowel and one consonant
        
    }
}