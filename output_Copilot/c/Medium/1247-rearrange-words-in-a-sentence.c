/**https://leetcode.com/problems/rearrange-words-in-a-sentence/ */
//Given a sentence text (A sentence is a string of space-separated words) in the following format:
//	First letter is in upper case.
//	Each word in text are separated by a single space.
//Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.
//Return the new text following the format shown above.
// 
//Example 1:
//Input: text = "Leetcode is cool"
//Output: "Is cool leetcode"
//Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
//Output is ordered by length and the new first word starts with capital letter.
//Example 2:
//Input: text = "Keep calm and code on"
//Output: "On and keep calm code"
//Explanation: Output is ordered as follows:
//"On" 2 letters.
//"and" 3 letters.
//"keep" 4 letters in case of tie order by position in original text.
//"calm" 4 letters.
//"code" 4 letters.
//Example 3:
//Input: text = "To be or not to be"
//Output: "To be or to be not"
// 
//Constraints:
//	text begins with a capital letter and then contains lowercase letters and single space between words.
//	1 <= text.length <= 10^5
char* arrangeWords(char* text) {
    int i, j, k, n, m;
    char *p, *q, *r, *s, *t;
    n = strlen(text);
    p = (char *)malloc(n + 2);
    q = (char *)malloc(n + 2);
    r = (char *)malloc(n + 2);
    s = (char *)malloc(n + 2);
    t = (char *)malloc(n + 2);
    strcpy(p, text);
    for (i = 0; i < n; i++) {
        if (p[i] == ' ') {
            break;
        }
    }
    p[i] = '\0';
    for (i = 0; i < n; i++) {
        if (p[i] >= 'A' && p[i] <= 'Z') {
            p[i] += 32;
        }
    }
    for (i = 0; i < n; i++) {
        q[i] = p[i];
    }
    q[i] = '\0';
    for (i = 0; i < n; i++) {
        if (q[i] == ' ') {
            break;
        }
    }
    q[i] = '\0';
    for (i = 0; i < n; i++) {
        if (p[i] >= 'a' && p[i] <= 'z') {
            p[i] -= 32;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        if (p[i] == ' ') {
            break;
        }
    }
    for (j = i + 1; j < n; j++) {
        if (p[j] >= 'a' && p[j] <= 'z') {
            p[j] -= 32;
        }
    }
    for (j = i + 1; j < n; j++) {
        if (p[j] == ' ') {
            break;
        }
    }
    p[j] = '\0';
    for (j = i + 1; j < n; j++) {
        if (q[j] >= 'a' && q[j] <= 'z') {
            q[j] -= 32;
        }
    }
    for (j = i + 1; j < n; j++) {
        if (q[j] == ' ') {
            break;
        }
        }
        q[j] = '\0';

        // Split words and store their lengths
        char *words[100000];
        int lengths[100000];
        int wordCount = 0;
        char *token = strtok(p, " ");
        while (token != NULL) {
        words[wordCount] = token;
        lengths[wordCount] = strlen(token);
        wordCount++;
        token = strtok(NULL, " ");
        }

        // Sort words by length and original order
        for (i = 0; i < wordCount - 1; i++) {
        for (j = i + 1; j < wordCount; j++) {
            if (lengths[i] > lengths[j] || (lengths[i] == lengths[j] && i > j)) {
            char *tempWord = words[i];
            int tempLength = lengths[i];
            words[i] = words[j];
            lengths[i] = lengths[j];
            words[j] = tempWord;
            lengths[j] = tempLength;
            }
        }
        }

        // Construct the result string
        r[0] = '\0';
        for (i = 0; i < wordCount; i++) {
        strcat(r, words[i]);
        if (i < wordCount - 1) {
            strcat(r, " ");
        }
        }

        // Capitalize the first letter of the result
        r[0] = r[0] - 32;

        // Copy the result to the output
        strcpy(t, r);
        return t;   
}