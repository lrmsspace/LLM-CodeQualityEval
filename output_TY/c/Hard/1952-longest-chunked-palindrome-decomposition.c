/**https://leetcode.com/problems/longest-chunked-palindrome-decomposition/ */
//You are given a string text. You should split it to k substrings (subtext1, subtext2, ..., subtextk) such that:
//	subtexti is a non-empty string.
//	The concatenation of all the substrings is equal to text (i.e., subtext1 + subtext2 + ... + subtextk == text).
//	subtexti == subtextk - i + 1 for all valid values of i (i.e., 1 <= i <= k).
//Return the largest possible value of k.
// 
//Example 1:
//Input: text = "ghiabcdefhelloadamhelloabcdefghi"
//Output: 7
//Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
//Example 2:
//Input: text = "merchant"
//Output: 1
//Explanation: We can split the string on "(merchant)".
//Example 3:
//Input: text = "antaprezatepzapreanta"
//Output: 11
//Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tep)(za)(pre)(a)(nt)(a)".
// 
//Constraints:
//	1 <= text.length <= 1000
//	text consists only of lowercase English characters.
int longestDecomposition(char * text){
    int len = strlen(text);
    if (len == 0) return 0;
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int max = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j <= len; j++) {
            for (k = j; k <= len; k++){
                for (l = k; l <= len; l++){
                    for (m = l; m <= len; m++){
                        for (n = m; n <= len; n++){
                            for (p = n; p <= len; p++){
                                for (q = p; q <= len; q++){
                                    for (r = q; r <= len; r++){
                                        for (s= r; s <= len; s++){
                                            for (t = s; t <= len; t++){
                                                for (u = t; u <= len; u++){
                                                    for (v = u; v <= len; v++){
                                                        for (w = v; w <= len; w++){
                                                            for (x = w; x <= len; x++){
                                                                for (y = x; y <= len; y++){
                                                                    for (z = y; z <= len; z++){
                                                                        int l1 = j - i;
                                                                        int l2 = k - j;
                                                                        int l3 = l - k;
                                                                        int l4 = m - l;
                                                                        int l5 = n - m;
                                                                        int l6 = p - n;
                                                                       int l7 = q - p;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return max;
}