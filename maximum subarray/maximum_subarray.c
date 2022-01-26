

int maxSubArray(int* nums, int numsSize){
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < numsSize;i++){
        if (sum >= 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }
        
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}