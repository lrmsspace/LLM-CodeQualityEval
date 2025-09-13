/**https://leetcode.com/problems/total-appeal-of-a-string/ */
//The appeal of a string is the number of distinct characters found in the string.
//	For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
//Given a string s, return the total appeal of all of its substrings.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "abbca"
//Output: 28
//Explanation: The following are the substrings of "abbca":
//- Substrings of length 1: "a", "b", "b", "c", "a" have an appeal of 1, 1, 1, 1, and 1 respectively. The sum is 5.
//- Substrings of length 2: "ab", "bb", "bc", "ca" have an appeal of 2, 1, 2, and 2 respectively. The sum is 7.
//- Substrings of length 3: "abb", "bbc", "bca" have an appeal of 2, 2, and 3 respectively. The sum is 7.
//- Substrings of length 4: "abbc", "bbca" have an appeal of 3 and 3 respectively. The sum is 6.
//- Substrings of length 5: "abbca" has an appeal of 3. The sum is 3.
//The total sum is 5 + 7 + 7 + 6 + 3 = 28.
//Example 2:
//Input: s = "code"
//Output: 20
//Explanation: The following are the substrings of "code":
//- Substrings of length 1: "c", "o", "d", "e" have an appeal of 1, 1, 1, and 1 respectively. The sum is 4.
//- Substrings of length 2: "co", "od", "de" have an appeal of 2, 2, and 2 respectively. The sum is 6.
//- Substrings of length 3: "cod", "ode" have an appeal of 3 and 3 respectively. The sum is 6.
//- Substrings of length 4: "code" has an appeal of 4. The sum is 4.
//The total sum is 4 + 6 + 6 + 4 = 20.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
long long appealSum(char * s){
    int i, j, k, n, m, a[26], b[26], c[26], d[26], e[26], f[26], g[26], h[26], l[26], r[26], t[26], u[26], v[26], w[26], x[26], y[26], z[26], sum = 0;
    n = strlen(s);
    for (i = 0; i < 26; i++) a[i] = b[i] = c[i] = d[i] = e[i] = f[i] = g[i] = h[i] = l[i] = r[i] = t[i] = u[i] = v[i] = w[i] = x[i] = y[i] = z[i] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - l[j];
                l[j] = i;
            }
            else {
                sum += i - r[j];
                r[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - t[j];
                t[j] = i;
            }
            else {
                sum += i - u[j];
                u[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - v[j];
                v[j] = i;
            }
            else {
                sum += i - w[j];
                w[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - x[j];
                x[j] = i;
            }
            else {
                sum += i - y[j];
                y[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - z[j];
                z[j] = i;
            }
            else {
                sum += i - a[j];
                a[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - b[j];
                b[j] = i;
            }
            else {
                sum += i - c[j];
                c[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - d[j];
                d[j] = i;
            }
            else {
                sum += i - e[j];
                e[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - f[j];
                f[j] = i;
            }
            else {
                sum += i - g[j];
                g[j] = i;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            if (j == s[i] - ' a ') {
                sum += i - h[j];
                h[j] = i;
            }
            else {
                sum += i - l[j];
                l[j] = i;
            }
        }
    }
    return sum;
}