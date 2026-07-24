int uniqueXorTriplets(int* nums, int numsSize) {
    bool pair_xors[2048] = {false};
    bool triplet_xors[2048] = {false};
    
    int active_pairs[2048];
    int active_count = 0;
    
    for (int k = 0; k < numsSize; k++) {
        int val = nums[k];
        for (int i = 0; i <= k; i++) {
            int px = nums[i] ^ val;
            if (!pair_xors[px]) {
                pair_xors[px] = true;
                active_pairs[active_count++] = px;
            }
        }
        for (int j = 0; j < active_count; j++) {
            int p = active_pairs[j];
            triplet_xors[p ^ val] = true;
        }
    }
    int unique_count = 0;
    for (int i = 0; i < 2048; i++) {
        if (triplet_xors[i]) {
            unique_count++;
        }
    }
    
    return unique_count;
}