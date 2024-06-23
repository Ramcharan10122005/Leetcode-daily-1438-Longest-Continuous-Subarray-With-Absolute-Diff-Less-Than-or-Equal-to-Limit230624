int longestSubarray(int* nums, int s, int limit) {
    int i = 0, j = 0;
    int maxIdx = 0, minIdx = 0;
    int maxLen = 0;
    int maxheap[100001];
    int minheap[100001]; 

    while (j < s) {
        while (maxIdx > 0 && nums[maxheap[maxIdx - 1]] <= nums[j]) {
            maxIdx--;
        }
        maxheap[maxIdx++] = j;
        while (minIdx > 0 && nums[minheap[minIdx - 1]] >= nums[j]) {
            minIdx--;
        }
        minheap[minIdx++] = j;
        while (nums[maxheap[0]] - nums[minheap[0]] > limit) {
            i = fmin(maxheap[0], minheap[0]) + 1;
            if (maxheap[0] < i) {
                for (int k = 1; k < maxIdx; k++) {
                    maxheap[k - 1] = maxheap[k];
                }
                maxIdx--;
            }
            if (minheap[0] < i) {
                for (int k = 1; k < minIdx; k++) {
                    minheap[k - 1] = minheap[k];
                }
                minIdx--;
            }
        }
        maxLen = fmax(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}
