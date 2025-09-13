/**https://leetcode.com/problems/replace-the-substring-for-balanced-string/ */
//You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
//A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
//Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
// 
//Example 1:
//Input: s = "QWER"
//Output: 0
//Explanation: s is already balanced.
//Example 2:
//Input: s = "QQWE"
//Output: 1
//Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
//Example 3:
//Input: s = "QQQW"
//Output: 2
//Explanation: We can replace the first "QQ" to "ER". 
// 
//Constraints:
//	n == s.length
//	4 <= n <= 105
//	n is a multiple of 4.
//	s contains only 'Q', 'W', 'E', and 'R'.
/**
 * @param {string} s
 * @return {number}
 */
var balancedString = function(s) {
    let map = new Map();
    let count = 0;
    let min = Number.MAX_SAFE_INTEGER;
    for(let i=0;i<s.length;i++){
        if(map.has(s[i])){
            map.set(s[i],map.get(s[i])+1);
        }else{
            map.set(s[i],1);
        }
    }
    for(let i=0;i<s.length;i++){
        if(map.get(s[i])>s.length/4){
            count++;
        }
    }
    if(count==0){
        return 0;
   }
   for(let i=0;i<s.length;i++){
       let j=i;
       let count1=0;
       let count2=0;
       let count3=0;
       let count4=0;
       while(j<s.length){
           if(s[j]=='Q'){
               count1++;
           }
           if(s[j]=='W'){
               count2++;
           }
           if(s[j]=='E'){
               count3++;
           }
           if(s[j]=='R'){
               count4++;
           }
       }
   }
   return min;
};