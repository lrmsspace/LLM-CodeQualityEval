/**https://leetcode.com/problems/minimum-number-of-frogs-croaking/ */
//You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
//Return the minimum number of different frogs to finish all the croaks in the given string.
//A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
// 
//Example 1:
//Input: croakOfFrogs = "croakcroak"
//Output: 1 
//Explanation: One frog yelling "croak" twice.
//Example 2:
//Input: croakOfFrogs = "crcoakroak"
//Output: 2 
//Explanation: The minimum number of frogs is two. 
//The first frog could yell "crcoakroak".
//The second frog could yell later "crcoakroak".
//Example 3:
//Input: croakOfFrogs = "croakcrook"
//Output: -1
//Explanation: The given string is an invalid combination of "croak" from different frogs.
// 
//Constraints:
//	1 <= croakOfFrogs.length <= 105
//	croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.
/**
 * @param {string} croakOfFrogs
 * @return {number}
 */
var minNumberOfFrogs = function(croakOfFrogs) {
    const count = { c: 0, r: 0, o: 0, a: 0, k: 0 };
    let frogs = 0;
    let maxFrogs = 0;

    for (const char of croakOfFrogs) {
        count[char]++;
        if (char === 'c') {
            frogs++;
            maxFrogs = Math.max(maxFrogs, frogs);
        } else if (char === 'r') {
            if (count.c <= count.r) return -1;
            frogs++;
        } else if (char === 'o') {
            if (count.r <= count.o) return -1;
            frogs--;
        } else if (char === 'a') {
            if (count.o <= count.a) return -1;
            frogs--;
        } else if (char === 'k') {
            if (count.a <= count.k) return -1;
            frogs--;
        }
    }

    return frogs === 0 ? maxFrogs : -1;    
};