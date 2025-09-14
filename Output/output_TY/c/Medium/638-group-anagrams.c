/**https://leetcode.com/problems/group-anagrams/ */
//Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// 
//Example 1:
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//Example 2:
//Input: strs = [""]
//Output: [[""]]
//Example 3:
//Input: strs = ["a"]
//Output: [["a"]]
// 
//Constraints:
//	1 <= strs.length <= 104
//	0 <= strs[i].length <= 100
//	strs[i] consists of lowercase English letters.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, hh, ii, jj, kk, ll, mm, nn, oo, pp, qq, rr, ss, tt, uu, vv, ww, xx, yy, zz, aa, bb, cc, dd, ee, ff, gg
    for(i=0;i<strsSize;i++){
        for(j=0;j<strsSize;j++){
            if(strs[i]==strs[j]){
                strs[i]=strs[j];
            }
        }
    }
    for(i=0;i<strsSize;i++){
        for(j=0;j<strsSize;j++){
            if(strs[i]==strs[j]){
                strs[i]=strs[j];
            }
        }
    }
    
}