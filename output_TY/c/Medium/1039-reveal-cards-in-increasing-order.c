/**https://leetcode.com/problems/reveal-cards-in-increasing-order/ */
//You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].
//You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.
//You will do the following steps repeatedly until all cards are revealed:
//	Take the top card of the deck, reveal it, and take it out of the deck.
//	If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
//	If there are still unrevealed cards, go back to step 1. Otherwise, stop.
//Return an ordering of the deck that would reveal the cards in increasing order.
//Note that the first entry in the answer is considered to be the top of the deck.
// 
//Example 1:
//Input: deck = [17,13,11,2,3,5,7]
//Output: [2,13,3,11,5,17,7]
//Explanation: 
//We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
//After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
//We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
//We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
//We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
//We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
//We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
//We reveal 13, and move 17 to the bottom.  The deck is now [17].
//We reveal 17.
//Since all the cards revealed are in increasing order, the answer is correct.
//Example 2:
//Input: deck = [1,1000]
//Output: [1,1000]
// 
//Constraints:
//	1 <= deck.length <= 1000
//	1 <= deck[i] <= 106
//	All the values of deck are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    a = (int *)malloc(sizeof(int) * deckSize);
    b = (int *)malloc(sizeof(int) * deckSize);
    c = (int *)malloc(sizeof(int) * deckSize);
    d = (int *)malloc(sizeof(int) * deckSize);
    e = (int *)malloc(sizeof(int) * deckSize);
    f = (int *)malloc(sizeof(int) * deckSize);
    g = (int *)malloc(sizeof(int) * deckSize);
    h = (int *)malloc(sizeof(int) * deckSize);
    i = (int *)malloc(sizeof(int) * deckSize);
    j = (int *)malloc(sizeof(int) * deckSize);
    k = (int *)malloc(sizeof(int) * deckSize);
    l = (int *)malloc(sizeof(int) * deckSize);
    m = (int *)malloc(sizeof(int) * deckSize);
    n = (int *)malloc(sizeof(int) * deckSize);
    o = (int *)malloc(sizeof(int) * deckSize);
    p = (int *)malloc(sizeof(int) * deckSize);
    q = (int *)malloc(sizeof(int) * deckSize);
    r = (int *)malloc(sizeof(int) * deckSize);
    s = (int *)malloc(sizeof(int) * deckSize);
    t = (int *)malloc(sizeof(int) * deckSize);
    u = (int *)malloc(sizeof(int) * deckSize);
    v = (int *)malloc(sizeof(int) * deckSize);
    w = (int *)malloc(sizeof(int) * deckSize);
    x = (int *)malloc(sizeof(int) * deckSize);
    y = (int *)malloc(sizeof(int) * deckSize);
    z = (int *)malloc(sizeof(int) * deckSize);
    for (i = 0; i < deckSize; i++) {
        o[i] = i;
    }
    for (i = 0; i < deckSize; i++) {
        t[i] = o[i];
    }
    for (i = 0; i < deckSize; i++) {
        u[i] = t[i];
    }
    for (i = 0; i < deckSize; i++) {
        w[i] = u[i];
    }
    for (i = 0; i < deckSize; i++) {
        x[i] = w[i];
    }
    for (i = 0; i < deckSize; i++) {
        y[i] = x[i];
    }
    for (i = 0; i < deckSize; i++) {
        z[i] = y[i];
    }
    for (i = 0; i < deckSize; i++) {
        if (z[i] != o[i]) {
            return false;
        }
    }
    return true;
}