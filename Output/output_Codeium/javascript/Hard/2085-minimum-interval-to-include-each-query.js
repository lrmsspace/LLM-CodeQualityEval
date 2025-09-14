/**https://leetcode.com/problems/minimum-interval-to-include-each-query/ */
//You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
//You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
//Return an array containing the answers to the queries.
// 
//Example 1:
//Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
//Output: [3,3,1,4]
//Explanation: The queries are processed as follows:
//- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
//- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
//- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
//- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
//Example 2:
//Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
//Output: [2,-1,4,6]
//Explanation: The queries are processed as follows:
//- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
//- Query = 19: None of the intervals contain 19. The answer is -1.
//- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
//- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
// 
//Constraints:
//	1 <= intervals.length <= 105
//	1 <= queries.length <= 105
//	intervals[i].length == 2
//	1 <= lefti <= righti <= 107
//	1 <= queries[j] <= 107
/**
 * @param {number[][]} intervals
 * @param {number[]} queries
 * @return {number[]}
 */
var minInterval = function(intervals, queries) {
    intervals.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    let answers = new Array(queries.length).fill(-1);
    let minHeap = new MinHeap();
    let i = 0;

    let sortedQueries = queries.map((query, index) => [query, index]).sort((a, b) => a[0] - b[0]);

    for (let [query, originalIndex] of sortedQueries) {
        while (i < intervals.length && intervals[i][0] <= query) {
            const [start, end] = intervals[i];
            minHeap.insert([end - start + 1, end]);
            i++;
        }

        while (!minHeap.isEmpty() && minHeap.peek()[1] < query) {
            minHeap.extractMin();
        }

        if (!minHeap.isEmpty()) {
            answers[originalIndex] = minHeap.peek()[0];
        }
    }
    
    return answers;
};

class MinHeap {
    constructor() {
        this.heap = [];
    }

    insert(val) {
        this.heap.push(val);
        this.bubbleUp(this.heap.length - 1);
    }

    extractMin() {
        if (this.heap.length === 1) return this.heap.pop();
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        return min;
    }

    peek() {
        return this.heap[0];
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    bubbleUp(index) {
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            if (this.heap[parentIndex][0] <= this.heap[index][0]) break;
            [this.heap[parentIndex], this.heap[index]] = [this.heap[index], this.heap[parentIndex]];
            index = parentIndex;
        }
    }

    bubbleDown(index) {
        const length = this.heap.length;
        while (true) {
            let left = 2 * index + 1;
            let right = 2 * index + 2;
            let smallest = index;

            if (left < length && this.heap[left][0] < this.heap[smallest][0]) smallest = left;
            if (right < length && this.heap[right][0] < this.heap[smallest][0]) smallest = right;
            if (smallest === index) break;

            [this.heap[smallest], this.heap[index]] = [this.heap[index], this.heap[smallest]];
            index = smallest;
        }
    }
}