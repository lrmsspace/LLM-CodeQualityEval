/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
// 
//Example 1:
//Input: s1 = "ab", s2 = "ba"
//Output: 1
//Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
//Example 2:
//Input: s1 = "abc", s2 = "bca"
//Output: 2
//Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
// 
//Constraints:
//	1 <= s1.length <= 20
//	s2.length == s1.length
//	s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
//	s2 is an anagram of s1.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var kSimilarity = function(s1, s2) {
    // Convert the strings to arrays for easier manipulation
    const arr1 = Array.from(s1);
    const arr2 = Array.from(s2);
    
    // Initialize a count of swaps and a queue to store the pairs of characters to be swapped
    let swaps = 0;
    const queue = [];
    
    // Iterate through the characters in the strings
    for (let i = 0; i < arr1.length; i++) {
        // If the characters are different, add their indices to the queue
        if (arr1[i]!== arr2[i]) {
            queue.push([i, arr2.indexOf(arr1[i])]);
        }
    }
    
    // While there are pairs to be swapped
    while (queue.length > 0) {
        // Pop the first pair from the queue
        const [i, j] = queue.shift();
        
        // Swap the characters at the popped indices
        [arr1[i], arr1[j]] = [arr1[j], arr1[i]];
        
        // If the swapped characters are different from their original positions, add their indices to the queue
        if (arr1[i]!== s1[i]) {
            queue.push([i, s2.indexOf(arr1[i])]);
        }
        
        // If the swapped characters are different from their original positions, add their indices to the queue
        if (arr1[j]!== s1[j]) {
            queue.push([j, s2.indexOf(arr1[j])]);
        }
        
        // Increment the count of swaps
        swaps++;
    }
    
    // Return the minimum number of swaps needed to make s1 and s2 k-similar
    return swaps;
    
};