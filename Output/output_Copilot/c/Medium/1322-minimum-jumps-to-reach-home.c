/**https://leetcode.com/problems/minimum-jumps-to-reach-home/ */
//A certain bug's home is on the x-axis at position x. Help them get there from position 0.
//The bug jumps according to the following rules:
//	It can jump exactly a positions forward (to the right).
//	It can jump exactly b positions backward (to the left).
//	It cannot jump backward twice in a row.
//	It cannot jump to any forbidden positions.
//The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.
//Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1.
// 
//Example 1:
//Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
//Output: 3
//Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
//Example 2:
//Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
//Output: -1
//Example 3:
//Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
//Output: 2
//Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7) will get the bug home.
// 
//Constraints:
//	1 <= forbidden.length <= 1000
//	1 <= a, b, forbidden[i] <= 2000
//	0 <= x <= 2000
//	All the elements in forbidden are distinct.
//	Position x is not forbidden.
        typedef struct {
            int position;
            bool backward;
            int steps;
        } State;

        typedef struct {
            State* data;
            int front;
            int rear;
            int size;
            int capacity;
        } Queue;

        void initQueue(Queue* q, int capacity) {
            q->data = (State*)malloc(sizeof(State) * capacity);
            q->front = 0;
            q->rear = 0;
            q->size = 0;
            q->capacity = capacity;
        }

        bool isEmpty(Queue* q) {
            return q->size == 0;
        }

        void enqueue(Queue* q, State s) {
            q->data[q->rear] = s;
            q->rear = (q->rear + 1) % q->capacity;
            q->size++;
        }

        State dequeue(Queue* q) {
            State s = q->data[q->front];
            q->front = (q->front + 1) % q->capacity;
            q->size--;
            return s;
        }

        void freeQueue(Queue* q) {
            free(q->data);
        }

        int minimumJumps(int* forbidden, int forbiddenSize, int a, int b, int x) {
            int maxLimit = 6000; // To account for overshooting beyond x
            bool visited[maxLimit][2];
            memset(visited, 0, sizeof(visited));

            for (int i = 0; i < forbiddenSize; i++) {
                visited[forbidden[i]][0] = true;
                visited[forbidden[i]][1] = true;
            }

            Queue q;
            initQueue(&q, maxLimit);
            enqueue(&q, (State){0, false, 0});
            visited[0][0] = true;

            while (!isEmpty(&q)) {
                State current = dequeue(&q);

                if (current.position == x) {
                    freeQueue(&q);
                    return current.steps;
                }

                int forward = current.position + a;
                if (forward < maxLimit && !visited[forward][0]) {
                    visited[forward][0] = true;
                    enqueue(&q, (State){forward, false, current.steps + 1});
                }

                int backward = current.position - b;
                if (backward >= 0 && !current.backward && !visited[backward][1]) {
                    visited[backward][1] = true;
                    enqueue(&q, (State){backward, true, current.steps + 1});
                }
            }

            freeQueue(&q);
            return -1;
        }   
