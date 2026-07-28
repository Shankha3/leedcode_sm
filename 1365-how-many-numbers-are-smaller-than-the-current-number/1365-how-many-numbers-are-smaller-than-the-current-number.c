int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int count[101] = {0};
    int* result = (int*) malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    int running_sum = 0;
    int smaller[101] = {0};
    for (int i = 0; i <= 100; i++) {
        smaller[i] = running_sum;
        running_sum += count[i];
    }

    for (int i = 0; i < numsSize; i++) {
        result[i] = smaller[nums[i]];
    }

    *returnSize = numsSize;
    return result;
}