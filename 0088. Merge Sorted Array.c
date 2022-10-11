void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (n == 0)return;
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1; //sort from the last, from the biggest to the smallest.
    
    while (i >= 0 && j >= 0){
        if (nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        }else{ //if (nums1[i] <= nums2[j])
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
    while(i >= 0){
        nums1[k--] = nums1[i--];
    }
    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
}

// Runtime: 7 ms, faster than 46.03% of C online submissions for Merge Sorted Array.
// Memory Usage: 6.4 MB, less than 8.47% of C online submissions for Merge Sorted Array

// optized solution

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (n == 0)return;
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
    while (i >= 0 && j >= 0){
        if (nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        }else{ //if (nums1[i] <= nums2[j])
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
//     if only nums1 is left -->all the rest of nums1 is smaller. we do not need to copy and just leave them in-place.
    // while(i >= 0){
    //     nums1[k--] = nums1[i--];
    // }
//     if only nums2 is left -->all the rest of nums2 is smaller. we need to copy to nums1.    
    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
}

// Runtime: 4 ms, faster than 72.75% of C online submissions for Merge Sorted Array.
// Memory Usage: 6.3 MB, less than 33.36% of C online submissions for Merge Sorted Array.
