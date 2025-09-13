/**https://leetcode.com/problems/count-the-repetitions/ */
//We define str = [s, n] as the string str which consists of the string s concatenated n times.
//	For example, str == ["abc", 3] =="abcabcabc".
//We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
//	For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
//You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].
//Return the maximum integer m such that str = [str2, m] can be obtained from str1.
// 
//Example 1:
//Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
//Output: 2
//Example 2:
//Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
//Output: 1
// 
//Constraints:
//	1 <= s1.length, s2.length <= 100
//	s1 and s2 consist of lowercase English letters.
//	1 <= n1, n2 <= 106
/**
 * @param {string} s1
 * @param {number} n1
 * @param {string} s2
 * @param {number} n2
 * @return {number}
 */
var getMaxRepetitions = function(s1, n1, s2, n2) {
    var s1_len = s1.length;
    var s2_len = s2.length;
    var s1_map = new Array(s1_len).fill(0);
    var s2_map = new Array(s2_len).fill(0);
    var s1_map_index = 0;
    var s2_map_index = 0;
    var s1_map_count = 0;
    var s2_map_count = 0;
    var s1_map_start = 0;
    var s2_map_start = 0;
    var s1_map_end = 0;
    var s2_map_end = 0;
    while(s1_map_count < n1){
        s1_map[s1_map_index]++;
        s1_map_index++;
        s1_map_index %= s1_len;
        s2_map[s2_map_index]++;
        s2_map_index++;
        s2_map_index %= s2_len;
        if(s1[s1_map_index] === s2[s2_map_index]){
            s1_map_end = s1_map_index;
            s2_map_end = s2_map_index;
            s1_map_start = s1_map_index;
        }
    }
    if(s1_map_end === 0){
        return 0;
    }
    var s1_map_len = s1_map_end - s1_map_start;
    var s2_map_len = s2_map_end - s2_map_start;
    var s1_map_cycle_len = s1_map_len * (n1 - 1);
    var s2_map_cycle_len = s2_map_len * (n2 - 1);
    var s1_map_cycle_count = Math.floor(s1_map_count / s1_map_cycle_len);
    var s2_map_cycle_count = Math.floor(s2_map_count / s2_map_cycle_len);
    var s1_map_cycle_remain = s1_map_count - s1_map_cycle_count * s1_map_cycle_len;
    var s2_map_cycle_remain = s2_map_count - s2_map_cycle_count * s2_map_cycle_len;
    while(s1_map_cycle_remain >= s1_map_len){
        s1_map_cycle_remain -= s1_map_len;
    }


    return 0;
};