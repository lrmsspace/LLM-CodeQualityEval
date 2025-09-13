/*
 You are given a string word and a non-negative integer k.
 Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
 Example 1:
 Input: word = "aeioqq", k = 1
 Output: 0
 Explanation:
 There is no substring with every vowel.
 Example 2:
 Input: word = "aeiou", k = 0
 Output: 1
 Explanation:
 The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".
 Example 3:
 Input: word = "ieaouqqieaouqq", k = 1
 Output: 3
 Explanation:
 The substrings with every vowel and one consonant are:
 word[0..5], which is "ieaouq".
 word[6..11], which is "qieaou".
 word[7..12], which is "ieaouq".
 Constraints:
 5 <= word.length <= 250
 word consists only of lowercase English letters.
 0 <= k <= word.length - 5
*/

int countOfSubstrings(char* word, int k) {
    int n = strlen(word), i, j, count = 0, vowel[5] = {0}, consonant = 0;   
    for (i = 0; i < n; i++) { 
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') { 
            vowel[0]++; 
        } else { 
            consonant++; 
        }
    }
    for (i = 0; i < n; i++) { 
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') { 
            vowel[0]--; 
        } else { 
            consonant--; 
        }
        for (j = i + 1; j < n; j++) { 
            if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') { 
                vowel[j - i]++; 
            }
        }
    }
    for (i = 0; i < n; i++) { 
        if (vowel[i] == k) { 
            ans++; 
        } 
    }
    return ans;
    
}