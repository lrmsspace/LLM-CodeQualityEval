/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//	The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//	A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.
// 
//Example 1:
//Input: s = "adefaddaccc"
//Output: ["e","f","ccc"]
//Explanation: The following are all the possible substrings that meet the conditions:
//[
//  "adefaddaccc"
//  "adefadda",
//  "ef",
//  "e",
//  "f",
//  "ccc",
//]
//If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
//Example 2:
//Input: s = "abbaccd"
//Output: ["d","bb","cc"]
//Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** maxNumOfSubstrings(char * s, int* returnSize){
    int i, j, k, l, len, *start, *end, *pos, *cnt, *max, *max_pos;
    len = strlen(s);
    start = (int *)malloc(sizeof(int) * len);
    end = (int *)malloc(sizeof(int) * len);
    pos = (int *)malloc(sizeof(int) * len);
    cnt = (int *)malloc(sizeof(int) * 26);
    max = (int *)malloc(sizeof(int) * len);
    max_pos = (int *)malloc(sizeof(int) * len);
   for (i = 0; i < len; i++) {
        start[i] = len;
   }
   for (i = 0; i < len; i++) {
        end[i] = -1;
   }
   for (i = 0; i < len; i++) {
        pos[i] = -1;
   }
   for (i = 0; i < len; i++) {
        cnt[s[i] - 'a']++;
        if (start[s[i] - 'a'] == len) {
            start[s[i] - 'a'] = i;
        }
        end[s[i] - 'a'] = i;
   }
   for (i = 0; i < 26; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        for (j = start[i]; j <= end[i]; j++) {
            pos[j] = i;
        }
   }
   for (i = 0; i < len; i++) {
        if (pos[i] == -1) {
            continue;
        }
        j = i;
        while (j <= end[pos[i]]) {
            if (pos[j] != pos[i]) {
                break;
            }
            j++;
        }
        k = j - 1;
        while (i <= k) {
            if (pos[i] != pos[k]) {
                break;
            }
        }
   }
   for (i = 0; i < len; i++) {
        max[i] = -1;
   }
   for (i = 0; i < len; i++) {
        if (pos[i] == -1) {
            continue;
        }
        j = i;
        while (j <= end[pos[i]]) {
            if (pos[j] != pos[i]) {
                break;
            }
        }
   }
   for (i = 0; i < len; i++) {
        if (pos[i] == -1) {
            continue;
        }
        j = i;
        while (j <= end[pos[i]]) {
            if (pos[j] != pos[i]) {
                break;
            }
            j++;
        }
        k = j - 1;
        while (i <= k) {
            if (pos[i] != pos[k]) {
                break;
            }
        }
   }
   for (i = 0; i < len; i++) {
        if (pos[i] == -1) {
            continue;
        }
        j = i;
        while (j <= end[pos[i]]) {
            if (pos[j] != pos[i]) {
                break;
            }
            j++;
        }
   }
   for (i = 0; i < len; i++) {
       if (pos[i] == -1) {
           j = i;
       }
   }
   for (i = j; i <= end[pos[i]]; i++) {
       if (pos[i] != pos[j]) {
           break;
       }
   }
   k = i - 1;
   while (j <= k) {
       if (pos[j] != pos[k]) {
           break;
       }
   }
   for (i = 0; i < len; i++) {
       if (pos[i] == -1) {
           continue;
       }
       j = i;
       while (j <= end[pos[i]]) {
           if (pos[j] != pos[i]) {
               break;
           }
           j++;
       }
   }
   for (i = 0; i < len; i++) {
       if (pos[i] == -1) {
           continue;
       }
       j = i;
       while (j <= end[pos[i]]) {
           if (pos[j] != pos[i]) {
               break;
           }
           j++;
       }
   }
   return NULL;
}