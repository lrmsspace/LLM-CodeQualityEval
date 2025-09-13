/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//	Each character is decoded as one digit (0 - 9).
//	No two characters can map to the same digit.
//	Each words[i] and result are decoded as one number without leading zeros.
//	Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
// 
//Example 1:
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//Constraints:
//	2 <= words.length <= 5
//	1 <= words[i].length, result.length <= 7
//	words[i], result contain only uppercase English letters.
//	The number of different characters used in the expression is at most 10.
bool isSolvable(char ** words, int wordsSize, char * result){   
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, num[10], sum[10], flag = 0, len = strlen(result);
    memset(num, 0, sizeof(num));
    memset(sum, 0, sizeof(sum));
    for(i = 0; i < wordsSize; i++) {

        for(j = 0; j < strlen(words[i]); j++) {

            for(k = 0; k < 10; k++) {

                if(num[k] == 0 && words[i][j] - 'A' == k) {

                    num[k] = 1;
                    break;
                }
            }
        }
    }
    for(i = 0; i < len; i++) {

        for(j = 0; j < 10; j++) {

            if(num[j] == 0 && result[i] - 'A' == j) {

                num[j] = 1;
                break;
            }
        }
    }
    for(i = 0; i < wordsSize; i++) {

        for(j = 0; j < strlen(words[i]); j++) {

            for(k = 0; k < 10; k++) {

                if(num[k] == 0 && words[i][j] - 'A' == k) {

                    num[k] = 1;
                    break;
                }
            }
        }
    }
    for(i = 0; i < wordsSize; i++) {

        for(j = 0; j < strlen(words[i]); j++) {

            for(k = 0; k < 10; k++) {

                if(words[i][j] - 'A' == k) {

                    sum[k] += pow(10, strlen(words[i]) - j - 1);
                }
            }
        }
    }
    for(i = 0; i < len; i++) {

        for(j = 0; j < 10; j++) {

            if(result[i] - 'A' == j) {

                sum[j] += pow(10, len - i - 1);
            }
        }
    }
    for(i = 0; i < wordsSize; i++) {

        for(j = 0; j < strlen(words[i]); j++) {

            for(k = 0; k < 10; k++) {

                if(words[i][j] - 'A' == k) {

                    sum[k] -= pow(10, strlen(words[i]) - j - 1);
                }
            }
        }
    }
    for(i = 0; i < len; i++) {

        for(j = 0; j < 10; j++) {

            if(result[i] - 'A' == j) {

                sum[j] -= pow(10, len - i - 1);
            }
        }
    }
    for(i = 0; i < 10; i++) {

        if(sum[i] != 0) {

            flag = 1;
            break;
        }
    }
    if(flag == 1) {

        return false;
    }
    for(i = 0; i < 10; i++) {

        for(j = 0; j < 10; j++) {

            for(k = 0; k < 10; k++) {

                for(l = 0; l < 10; l++) {

                    for(m = 0; m < 10; m++) {

                        for(n = 0; n < 10; n++) {
                            for(o = 0; o < 10; o++) {
                                for(p = 0; p < 10; p++) {
                                    for(q = 0; q < 10; q++) {
                                        for(r = 0; r < 10; r++) {
                                            for(s = 0; s < 10; s++) {
                                                for(t = 0; t < 10; t++) {
                                                    for(u = 0; u < 10; u++) {
                                                        for(v = 0; v < 10; v++) {
                                                            for(w = 0; w < 10; w++) {
                                                                for(x = 0; x < 10; x++) {
                                                                    for(y = 0; y < 10; y++) {
                                                                       for(z = 0; z < 10; z++)   {

                                                                        if(num[i] == 1 && num[j] == 2 && num[k] == 3 && num[l] == 4 && num[m] == 5 && num[n] == 6 && num[o] == 7 && num[p] == 8 && num[q] == 9 && num[r] == 0 && num[s] == 1 && num[t] == ) {

                                                                            a = i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + n * 1000 + o * 100 + p * 10 + q;
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
        }
    }
    return true;
}