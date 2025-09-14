/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
/**
 * @param {string} s
 * @return {string}
 */
var originalDigits = function(s) {
    let map = new Map();
    for(let i=0;i<s.length;i++){
        if(map.has(s[i])){
            map.set(s[i],map.get(s[i])+1);
        }else{
            map.set(s[i],1);
        }
    }
    let ans = "";
    let map2 = new Map();
    map2.set("z",map.get("z"));
    map2.set("w",map.get("w"));
    map2.set("u",map.get("u"));
    map2.set("x",map.get("x"));
    map2.set("g",map.get("g"));
    map2.set("h",map.get("h")-map2.get("g"));
    map2.set("f",map.get("f")-map2.get("u"));
    map2.set("o",map.get("o")-map2.get("u")-map2.get("x")-map2.get("g"));
    map2.set("s",map.get("s")-map2.get("h"));
    map2.set("i",map.get("i")-map2.get("x")-map2.get("g")-map2.get("f"));
    for(let [key,value] of map2){
        for(let i=0;i<value;i++){
            ans+=key;
        }
    }
    return ans;
};