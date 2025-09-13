/*
 You are given a string s consisting of lowercase English letters ('a' to 'z'). 
 Your task is to:
 Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
 Find the consonant (all other letters excluding vowels) with the maximum frequency.
 Return the sum of the two frequencies.
 Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
 The frequency of a letter x is the number of times it occurs in the string.
 Example 1:
 Input: s = "successes"
 Output: 6
 Explanation:
 The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
 The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
 The output is 2 + 4 = 6.
 Example 2:
 Input: s = "aeiaeia"
 Output: 3
 Explanation:
 The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
 There are no consonants in s. Hence, maximum consonant frequency = 0.
 The output is 3 + 0 = 3.
 Constraints:
 1 <= s.length <= 100
 s consists of lowercase English letters only.
*/

/**
 * @param {string} s
 * @return {number}
 */
var maxFreqSum = function(s) {
    const vowels = ['a', 'e', 'i', 'o', 'u'];
    const vowelFreq = new Map();
    const consonantFreq = new Map();
    let maxVowelFreq = 0;
    let maxConsonantFreq = 0;
    
    for (let i = 0; i < s.length; i++) {
        const char = s[i];
        if (vowels.includes(char)) {
            vowelFreq.set(char, (vowelFreq.get(char) || 0) + 1);
            maxVowelFreq = Math.max(maxVowelFreq, vowelFreq.get(char));
        } else {
            consonantFreq.set(char, (consonantFreq.get(char) || 0) + 1);
            maxConsonantFreq = Math.max(maxConsonantFreq, consonantFreq.get(char));
        }
    }
    
    let vowelSum = 0;
    let consonantSum = 0;
    
    vowelFreq.forEach((freq, vowel) => {
        if (freq === maxVowelFreq) {
            vowelSum += freq;
        }
    });
    
    consonantFreq.forEach((freq, consonant) => {
        if (freq === maxConsonantFreq) {
            consonantSum += freq;
        }
    });
    
    return vowelSum + consonantSum;
    
};