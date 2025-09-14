/**https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/ */
//You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
//	Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
//	Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
//Return the lexicographically smallest string that can be written on the paper.
// 
//Example 1:
//Input: s = "zza"
//Output: "azz"
//Explanation: Let p denote the written string.
//Initially p="", s="zza", t="".
//Perform first operation three times p="", s="", t="zza".
//Perform second operation three times p="azz", s="", t="".
//Example 2:
//Input: s = "bac"
//Output: "abc"
//Explanation: Let p denote the written string.
//Perform first operation twice p="", s="c", t="ba". 
//Perform second operation twice p="ab", s="c", t="". 
//Perform first operation p="ab", s="", t="c". 
//Perform second operation p="abc", s="", t="".
//Example 3:
//Input: s = "bdda"
//Output: "addb"
//Explanation: Let p denote the written string.
//Initially p="", s="bdda", t="".
//Perform first operation four times p="", s="", t="bdda".
//Perform second operation four times p="addb", s="", t="".
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.
char * robotWithString(char * s){
    int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
    int a[26] = {0};
    int b[26] = {0};
    int c[26] = {0};
    int d[26] = {0};
    int e[26] = {0};
    int f[26] = {0};
    for (i = 0; s[i]; i++) {
        a[s[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
        b[i] = a[i];
    }
    for (i = 0; i < 26; i++) {
        c[i] = b[i];
    }
    for (i = 0; i < 26; i++) {
        d[i] = c[i];
    }
    for (i = 0; i < 26; i++) {
        e[i] = d[i];
    }
    for (i = 0; i < 26; i++) {
        f[i] = e[i];
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (f[i] < f[j]) {
                t = f[i];
                f[i] = f[j];
                f[j] = t;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (f[i] == a[j]) {
                a[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (f[i] == b[j]) {
                b[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (f[i] == c[j]) {
                c[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (f[i] == d[j]) {
                d[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (f[i] == e[j]) {
                e[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (f[i] == f[j]) {
                f[j] = 0;
                break;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        if (a[i] != 0) {
            return "zzzzzzzzzz}
    }
}
}
}