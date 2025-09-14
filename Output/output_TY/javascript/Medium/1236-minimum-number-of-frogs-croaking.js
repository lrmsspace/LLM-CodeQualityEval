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
    let croak = "croak";
    let map = new Map();
    let count = 0;
    let max = 0;
    for(let i = 0; i < croakOfFrogs.length; i++){
        if(!map.has(croakOfFrogs[i])){
            map.set(croakOfFrogs[i], 1);
        }else{
            map.set(croakOfFrogs[i], map.get(croakOfFrogs[i]) + 1);
        }
        if(croak.includes(croakOfFrogs[i])){
            count++;
        }
        if(croak.includes(croakOfFrogs[i]) && croakOfFrogs[i] === "c")
            max = Math.max(max, count);
        else if(croak.includes(croakOfFrogs[i]) && croakOfFrogs[i] === "k"){
            count--;
            if(map.get("c") < map.get("k"))
                return -1;
        }
    }
    return max;

};