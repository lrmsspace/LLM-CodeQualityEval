/**https://leetcode.com/problems/satisfiability-of-equality-equations/ */
//You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
//Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.
// 
//Example 1:
//Input: equations = ["a==b","b!=a"]
//Output: false
//Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
//There is no way to assign the variables to satisfy both equations.
//Example 2:
//Input: equations = ["b==a","a==b"]
//Output: true
//Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
// 
//Constraints:
//	1 <= equations.length <= 500
//	equations[i].length == 4
//	equations[i][0] is a lowercase letter.
//	equations[i][1] is either '=' or '!'.
//	equations[i][2] is '='.
//	equations[i][3] is a lowercase letter.
/**
 * @param {string[]} equations
 * @return {boolean}
 */
var equationsPossible = function(equations) {
    let map = new Map();
    for(let i=0;i<equations.length;i++){
        let [a,b] = equations[i].split('==');
        if(map.has(a)){
            map.set(a,map.get(a).concat(b));
        }else{
            map.set(a,[b]);
        }
        if(map.has(b)){
            map.set(b,map.get(b).concat(a));
        }else{
            map.set(b,[a]);
        }
    }
    for(let [key,value] of map){
        if(value.includes(key)){
           return false;
        }
    }
    return true;
};