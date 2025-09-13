/**https://leetcode.com/problems/repeated-string-match/ */
//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
// 
//Example 1:
//Input: a = "abcd", b = "cdabcdab"
//Output: 3
//Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
//Example 2:
//Input: a = "a", b = "aa"
//Output: 2
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist of lowercase English letters.
int repeatedStringMatch(char * a, char * b){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    n = 0;
    o = 0;
    p = 0;
    q = 0;
    r =0;
    s = 0;
    t = 0;
    u = 0;
    v = 0;
    w = 0;
    x = 0;
    y = 0;
    z = 0;
    while(a[i] != '\0'){
        i++;
    }
    while(b[j] != '\0'){
        j++;
    }
    if(j > i){
        return -1;
    }
    for(k = 0; k < j; k++){
        for(l = 0; l < i; l++){
            if(a[l] == b[k]){
                m++;
                break;
            }
        }
    }
    if(m != j){
        return -1;
    }
    for(n = 0; n < i; n++){
        if(a[n] == b[0]){
            o++;
        }
    }
    return (o + j - 1);
}