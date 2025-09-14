/**https://leetcode.com/problems/path-with-maximum-probability/ */
//You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
//Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
//If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
// 
//Example 1:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
//Output: 0.25000
//Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
//Example 2:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
//Output: 0.30000
//Example 3:
//Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
//Output: 0.00000
//Explanation: There is no path between 0 and 2.
// 
//Constraints:
//	2 <= n <= 10^4
//	0 <= start, end < n
//	start != end
//	0 <= a, b < n
//	a != b
//	0 <= succProb.length == edges.length <= 2*10^4
//	0 <= succProb[i] <= 1
//	There is at most one edge between every two nodes.  
        typedef struct {
            int node;
            double prob;
        } HeapNode;

        typedef struct {
            HeapNode* data;
            int size;
            int capacity;
        } MaxHeap;

        void swap(HeapNode* a, HeapNode* b) {
            HeapNode temp = *a;
            *a = *b;
            *b = temp;
        }

        void heapifyDown(MaxHeap* heap, int index) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < heap->size && heap->data[left].prob > heap->data[largest].prob)
                largest = left;
            if (right < heap->size && heap->data[right].prob > heap->data[largest].prob)
                largest = right;

            if (largest != index) {
                swap(&heap->data[index], &heap->data[largest]);
                heapifyDown(heap, largest);
            }
        }

        void heapifyUp(MaxHeap* heap, int index) {
            int parent = (index - 1) / 2;

            if (index > 0 && heap->data[index].prob > heap->data[parent].prob) {
                swap(&heap->data[index], &heap->data[parent]);
                heapifyUp(heap, parent);
            }
        }

        void push(MaxHeap* heap, int node, double prob) {
            if (heap->size == heap->capacity) {
                heap->capacity *= 2;
                heap->data = realloc(heap->data, heap->capacity * sizeof(HeapNode));
            }
            heap->data[heap->size].node = node;
            heap->data[heap->size].prob = prob;
            heap->size++;
            heapifyUp(heap, heap->size - 1);
        }

        HeapNode pop(MaxHeap* heap) {
            HeapNode top = heap->data[0];
            heap->data[0] = heap->data[heap->size - 1];
            heap->size--;
            heapifyDown(heap, 0);
            return top;
        }

        double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start_node, int end_node) {
            // Create adjacency list
            double** graph = malloc(n * sizeof(double*));
            for (int i = 0; i < n; i++) {
                graph[i] = calloc(n, sizeof(double));
            }
            for (int i = 0; i < edgesSize; i++) {
                int a = edges[i][0];
                int b = edges[i][1];
                graph[a][b] = succProb[i];
                graph[b][a] = succProb[i];
            }

            // Max heap for Dijkstra's algorithm
            MaxHeap heap = {malloc(n * sizeof(HeapNode)), 0, n};
            double* probabilities = calloc(n, sizeof(double));
            probabilities[start_node] = 1.0;
            push(&heap, start_node, 1.0);

            while (heap.size > 0) {
                HeapNode current = pop(&heap);
                int node = current.node;
                double prob = current.prob;

                if (node == end_node) {
                    free(probabilities);
                    for (int i = 0; i < n; i++) free(graph[i]);
                    free(graph);
                    free(heap.data);
                    return prob;
                }

                for (int i = 0; i < n; i++) {
                    if (graph[node][i] > 0) {
                        double newProb = prob * graph[node][i];
                        if (newProb > probabilities[i]) {
                            probabilities[i] = newProb;
                            push(&heap, i, newProb);
                        }
                    }
                }
            }

            free(probabilities);
            for (int i = 0; i < n; i++) free(graph[i]);
            free(graph);
            free(heap.data);
            return 0.0;
        }
