// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int bad = -1;
int firstBadVersion(int n) {
    return find(0, n);
}
int find(unsigned int left, unsigned int right){  
    
    while (left <= right){
        int mid = (left + right) / 2;
//       find the first bad version: mid is bad and mid-1 is not bad
        if (isBadVersion(mid) == true && isBadVersion(mid - 1) == false){
            return mid;
        }
        else if (isBadVersion(mid) == false){
            left = mid + 1;
        }else if (isBadVersion(mid) == true){
            right = mid - 1;
        } 
    }
    return -1;
}


// Runtime: 0 ms, faster than 100.00% of C online submissions for First Bad Version.
// Memory Usage: 5.5 MB, less than 46.81% of C online submissions for First Bad Version.
