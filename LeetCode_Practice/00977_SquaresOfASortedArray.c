/*

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.



Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.


Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int left=0, right = numsSize-1;
    for(int i=numsSize-1;i>=0;i--){
        if(abs(nums[left])>abs(nums[right])){
            res[i] = nums[left]*nums[left];
            left++;
        }
        else{
            res[i] = nums[right]*nums[right];
            right--;
        }
    }
    return res;
}
