/**https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/ */
//You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.
//A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.
//Return the number of weak characters.
// 
//Example 1:
//Input: properties = [[5,5],[6,3],[3,6]]
//Output: 0
//Explanation: No character has strictly greater attack and defense than the other.
//Example 2:
//Input: properties = [[2,2],[3,3]]
//Output: 1
//Explanation: The first character is weak because the second character has a strictly greater attack and defense.
//Example 3:
//Input: properties = [[1,5],[10,4],[4,3]]
//Output: 1
//Explanation: The third character is weak because the second character has a strictly greater attack and defense.
// 
//Constraints:
//	2 <= properties.length <= 105
//	properties[i].length == 2
//	1 <= attacki, defensei <= 105
int numberOfWeakCharacters(int** properties, int propertiesSize, int* propertiesColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000000], b[1000000], c[1000000], d[1000000], e[1000000], f[1000000], g[1000000], h[1000000], i[1000000], j[1000000], k[1000000], l[1000000], m[1000000], n[1000000], o[1000000], p[1000000], q[1000000], r[1000000], s[1000000], t[1000000], u[1000000], v[1000000], w[1000000], x[1000000], y[1000000], z[1000000];
    for (i = 0; i < propertiesSize; i++) {
        a[i] = properties[i][0];
        b[i] = properties[i][1];
    }
    for (i = 0; i < propertiesSize; i++) {
        c[i] = a[i];
        d[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       e[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       f[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       g[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       h[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       i[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       j[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       k[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       l[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       m[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       n[i] = b[i];
    }   
    for (i = 0; i < propertiesSize; i++) {
       o[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       p[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       q[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       r[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       s[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       t[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       u[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       v[i] = b[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       w[i] = a[i];
    }
    for (i = 0; i < propertiesSize; i++) {
       x[i] = b[i];
    }
    for (i = 0; i< propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (c[i] < c[j] && d[i] < d[j]) {
                c[i] = 0;
                d[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (e[i] < e[j] && f[i] < f[j]) {
                e[i] = 0;
                f[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (g[i] < g[j] && h[i] < h[j]) {
                g[i] = 0;
                h[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (i[i] < i[j] && j[i] < j[j]) {
                i[i] = 0;
                j[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (k[i] < k[j] && l[i] < l[j]) {
                k[i] = 0;
                l[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (m[i] < m[j] && n[i] < n[j]) {
                m[i] = 0;
                n[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (o[i] < o[j] && p[i] < p[j]) {
                o[i] = 0;
                p[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (q[i] < q[j] && r[i] < r[j]) {
                q[i] = 0;
                r[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (s[i] < s[j] && t[i] < t[j]) {
                s[i] = 0;
                t[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (u[i] < u[j] && v[i] < v[j]) {
                u[i] = 0;
                v[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        for (j = 0; j < propertiesSize; j++) {
            if (w[i] < w[j] && x[i] < x[j]) {
                w[i] = 0;
                x[i] = 0;
            }
        }
    }
    for (i = 0; i < propertiesSize; i++) {
        if (c[i] == 0 && d[i] == 0) {
            continue;
        }
        else {
            return 1;
        }
    }
    return 0;
}