// https://leetcode.com/problems/median-of-two-sorted-arrays/
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    
    
    // start with base cases
    if(nums1.length + nums2.length == 0) return 0;
    if(nums1.length + nums2.length == 1) return nums1.length > nums2.length ? nums1[0] : nums2[0];
    
    let i = 0, j = 0, combined = [];
    
    // create combined array by keeping it sorted
    while( i < nums1.length && j < nums2.length){
        if(nums1[i] < nums2[j]){
            combined.push(nums1[i]);
            ++i;
        }
        else{
            combined.push(nums2[j]);
            ++j;
        }
    }
    
    // just concat the rest of the longer array
    if(i < nums1.length){
        combined = combined.concat(nums1.slice(i));
    }
    if(j < nums2.length){
        combined = combined.concat(nums2.slice(j));
    }

    
    // handle both cases for median 
    if(combined.length % 2 == 0){
        // median will be avg of middle two numbers
        return (combined[(combined.length / 2)] + combined[(combined.length / 2) - 1]) / 2;
    }
    else{
        return combined[(combined.length - 1)/ 2];
    }
};
