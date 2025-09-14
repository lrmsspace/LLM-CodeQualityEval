/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    typedef struct {
        int value;
        int listIndex;
        int elementIndex;   
    } Node;

    typedef struct {
        Node* heap;
        int size;
    } MinHeap;

    void swap(Node* a, Node* b) {
        Node temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapify(MinHeap* heap, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap->size && heap->heap[left].value < heap->heap[smallest].value)
            smallest = left;
        if (right < heap->size && heap->heap[right].value < heap->heap[smallest].value)
            smallest = right;

        if (smallest != i) {
            swap(&heap->heap[i], &heap->heap[smallest]);
            heapify(heap, smallest);
        }
    }

    Node extractMin(MinHeap* heap) {
        Node root = heap->heap[0];
        heap->heap[0] = heap->heap[heap->size - 1];
        heap->size--;
        heapify(heap, 0);
        return root;
    }

    void insertHeap(MinHeap* heap, Node node) {
        heap->size++;
        int i = heap->size - 1;
        heap->heap[i] = node;

        while (i != 0 && heap->heap[(i - 1) / 2].value > heap->heap[i].value) {
            swap(&heap->heap[i], &heap->heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
        MinHeap heap;
        heap.size = numsSize;
        heap.heap = malloc(numsSize * sizeof(Node));

        int maxVal = INT_MIN;
        for (int i = 0; i < numsSize; i++) {
            heap.heap[i].value = nums[i][0];
            heap.heap[i].listIndex = i;
            heap.heap[i].elementIndex = 0;
            if (nums[i][0] > maxVal) maxVal = nums[i][0];
        }

        for (int i = (numsSize - 1) / 2; i >= 0; i--) {
            heapify(&heap, i);
        }

        int minRange = INT_MAX;
        int start = 0, end = 0;

        while (1) {
            Node minNode = extractMin(&heap);
            int minVal = minNode.value;

            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
                start = minVal;
                end = maxVal;
            }

            if (minNode.elementIndex + 1 < numsColSize[minNode.listIndex]) {
                minNode.elementIndex++;
                minNode.value = nums[minNode.listIndex][minNode.elementIndex];
                if (minNode.value > maxVal) maxVal = minNode.value;
                insertHeap(&heap, minNode);
            } else {
                break;
            }
        }

        free(heap.heap);

        result[0] = start;
        result[1] = end;
        *returnSize = 2;
        return result;
    }
}