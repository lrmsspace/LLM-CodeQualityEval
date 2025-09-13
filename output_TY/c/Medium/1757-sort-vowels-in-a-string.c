/**https://leetcode.com/problems/sort-vowels-in-a-string/ */
//Given a 0-indexed string s, permute s to get a new string t such that:
//	All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
//	The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
//Return the resulting string.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.
// 
//Example 1:
//Input: s = "lEetcOde"
//Output: "lEOtcede"
//Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
//Example 2:
//Input: s = "lYmpH"
//Output: "lYmpH"
//Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists only of letters of the English alphabet in uppercase and lowercase.
char * sortVowels(char * s){
    int i, j, k, n, m, a[5], b[5], c[5], d[5], e[5], f[5], g[5], h[5], l[5], o[5], u[5], v[5], w[5], x[5], y[5], z[5];
    for (i = 0, j = 0, k = 0, n = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'A') {
            a[j++] = i;
            n++;
        }
        else if (s[i] == 'e' || s[i] == 'E') {
            b[k++] = i;
        }
    }
    for (i = 0; i < j; i++) {
        s[a[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[b[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'i' || s[i] == 'I') {
            c[j++] = i;
            m++;
        }
        else if (s[i] == 'o' || s[i] == 'O') {
            d[k++] =i;
        }
    }
    for (i = 0; i < j; i++) {
        s[c[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[d[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'u' || s[i] == 'U') {
            e[j++] = i;
            m++;
        }
        else if (s[i] == 'y' || s[i] == 'Y') {
            f[k++] =i;
        }
    }
    for (i = 0; i < j; i++) {
        s[e[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[f[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'l' || s[i] == 'L') {
            g[j++] = i;
            m++;
        }
        else if (s[i] == 't' || s[i] == 'T') {
            h[k++] =i;
        }
    }
    for (i = 0; i < j; i++) {
        s[g[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[h[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'c' || s[i] == 'C') {
            l[j++] = i;
            m++;
        }
        else if (s[i] == 'd' || s[i] == 'D') {
            o[k++] =i;
        }
    }
    for (i = 0; i < j; i++) {
        s[l[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[o[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'n' || s[i] == 'N') {
            u[j++] = i;
            m++;
        }
        else if (s[i] == 'p' || s[i] == 'P') {
            v[k++] =i;
        }
    }
    for (i = 0; i < j; i++) {
        s[u[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[v[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'w' || s[i] == 'W') {
            w[j++] = i;
            m++;
        }
        else if (s[i] == 'x' || s[i] == 'X') {
            x[k++] =i;
        }
    }
    for (i = 0; i < j; i++) {
        s[w[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[x[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == 'h' || s[i] == 'H') {
            y[j++] = i;
            m++;
        }
        else if (s[i] == 'z' || s[i] == 'Z') {
            z[k++] =i;
        }
    }
    for (i = 0; i < j; i++) {
        s[y[i]] = ' ';
    }
    for (i = 0; i < k; i++) {
        s[z[i]] = ' ';
    }
    for (i = 0, j = 0, k = 0, m = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            continue;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    return s;
}