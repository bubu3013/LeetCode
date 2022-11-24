// solution 1: c

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

// solution 2: c++

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return helper(n);
    }
private:
    int helper(int n){
        int left = 0;
        int right = n;
        int ans = -1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (mid + 1 <= n && isBadVersion(mid) == false && isBadVersion(mid + 1) == true){
                ans = mid + 1;
                break;
            }else if (mid - 1 >= 0 && isBadVersion(mid) == true && isBadVersion(mid - 1) == false){
                ans = mid;
                break;
            }else if (isBadVersion(mid) == false){
                left = mid + 1;
            }else if (isBadVersion(mid) == true){
                right = mid - 1;
            }
        }
        return ans;
    }
};

// solution 2: C++

class Solution {
public:
    int firstBadVersion(int n) {
        return helper(n);
    }
private:
    int helper(int n){
        int left = 0;
        int right = n;
        int ans = -1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (mid - 1 >= 0 && isBadVersion(mid) == true && isBadVersion(mid - 1) == false){
                ans = mid;
                break;
            }else if (isBadVersion(mid) == false){
                left = mid + 1;
            }else if (isBadVersion(mid) == true){
                right = mid - 1;
            }
        }
        return ans;
    }
};

// Runtime 0 ms Beats 100% 
// Memory 6 MB Beats 23.6%
