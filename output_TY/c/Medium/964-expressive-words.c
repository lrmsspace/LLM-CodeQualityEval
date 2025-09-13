/**https://leetcode.com/problems/expressive-words/ */
//Sometimes people repeat letters to represent extra feeling. For example:
//	"hello" -> "heeellooo"
//	"hi" -> "hiiii"
//In these strings like "heeellooo", we have groups of adjacent letters that are all the same: "h", "eee", "ll", "ooo".
//You are given a string s and an array of query strings words. A query word is stretchy if it can be made to be equal to s by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is three or more.
//	For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has a size less than three. Also, we could do another extension like "ll" -> "lllll" to get "helllllooo". If s = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = s.
//Return the number of query strings that are stretchy.
// 
//Example 1:
//Input: s = "heeellooo", words = ["hello", "hi", "helo"]
//Output: 1
//Explanation: 
//We can extend "e" and "o" in the word "hello" to get "heeellooo".
//We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
//Example 2:
//Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
//Output: 3
// 
//Constraints:
//	1 <= s.length, words.length <= 100
//	1 <= words[i].length <= 100
//	s and words[i] consist of lowercase letters.
int expressiveWords(char * s, char ** words, int wordsSize){
    int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h, i1, j1, k1, l1, m1, n1, o1, p1, q1, r1, t1, u1, v1, w1, x1, y1, z1; 
    int count, count1;  
    count = 0;
    for (i = 0; i < wordsSize; i++) {
        j = 0;
        k = 0;
        l = 0;
        m = 0;
        n = 0;
        o = 0;
        p = 0;
        q = 0;
        r = 0;
        t = 0;
        u = 0;
        v = 0;
        w = 0;
    }   
    for (i = 0; i < queriesSize; i++) { 
        count1 = 0; 
        for (j = 0; j < wordsSize; j++) {
            a = 0;
            b = 0;  
            for (k = 0; k < strlen(words[j]); k++) {
                if (words[j][k] == queries[i][a]) {
                    a++;
                    b++;
                }
            }
        }
    }   
    return count1;
}