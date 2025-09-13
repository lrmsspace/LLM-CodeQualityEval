/**https://leetcode.com/problems/reconstruct-itinerary/ */
//You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
//All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
//	For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
// 
//Example 1:
//Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
//Output: ["JFK","MUC","LHR","SFO","SJC"]
//Example 2:
//Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
//Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
// 
//Constraints:
//	1 <= tickets.length <= 300
//	tickets[i].length == 2
//	fromi.length == 3
//	toi.length == 3
//	fromi and toi consist of uppercase English letters.
//	fromi != toi
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    char **A, **B, **C, **D, **E, **F, **G, **H, **I, **J, **K, **L, **M, **N, **O, **P, **Q, **R, **S, **T, **U, **V, **W, **X, **Y, **Z;
    A = tickets;
    B = malloc(sizeof(char *) * ticketsSize);
    for (i = 0; i < ticketsSize; i++) {
        B[i] = malloc(sizeof(char) * 3);
        strcpy(B[i], A[i][0]);
    }
    C = malloc(sizeof(char *) * ticketsSize);
    for (i = 0; i < ticketsSize; i++) {
        C[i] = malloc(sizeof(char) * 3);
    }
    return findItinerary(B, ticketsSize, C, 0);
}