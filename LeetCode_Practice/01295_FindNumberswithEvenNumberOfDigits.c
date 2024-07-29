/*
Given an array nums of integers, return how many of them contain an even number of digits.

 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 105

*/


int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if(countEven(nums[i]) == 0)
            count++;
    }
    return count;
}

int countEven(int n){
    int count = 0;
    while(n>0){
        n=n/10;
        count++;
    }
    if(count%2==0)
        return 0;
    else
        return 1;
}

#if 0

int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if((nums[i]>9) && (nums[i]<100))
            count++;
        if((nums[i]>999) && (nums[i]<10000))
            count++;
        if((nums[i]>99999) && (nums[i]<1000000))
            count++;
    }
    return count;
}


#endif
