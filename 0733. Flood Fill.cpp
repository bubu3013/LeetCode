class Solution {
public:
    int m = -1;
    int n = -1;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        
        flood(image, sr, sc, image[sr][sc], color);
        return image;
    }
private:
    void flood(vector<vector<int>> &img, int row, int col, int old_, int new_ ){
//      base case 
        if (row < 0 || row >= m || col < 0 || col >= n){
            return;
        }
//      we only paint when img[row][col] is old_ 
        if (img[row][col] == new_ || img[row][col] != old_){
            return;
        }
        
        img[row][col] = new_;
        
//      recursive case
        flood(img, row - 1, col, old_, new_);//up
        flood(img, row + 1, col, old_, new_);//down
        flood(img, row, col - 1, old_, new_);//left
        flood(img, row, col + 1, old_, new_);//right
    }
};

Runtime: 7 ms, faster than 96.76% of C++ online submissions for Flood Fill.
Memory Usage: 14 MB, less than 48.03% of C++ online submissions for Flood Fill.

// Runtime: 9 ms, faster than 90.66% of C++ online submissions for Flood Fill.
// Memory Usage: 14 MB, less than 79.27% of C++ online submissions for Flood Fill.
