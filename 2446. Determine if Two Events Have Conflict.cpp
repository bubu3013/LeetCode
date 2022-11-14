class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return helper(event1, event2);
    }
private:
    bool helper(vector<string>& event1, vector<string>& event2){
        // event 2 happens earlier and ends earlier
        if (event1[0] >= event2[0] && event1[0] <= event2[1] && event1[1] >= event2[0] && event1[1] >= event2[1]){
            return true;
        }
        // event 2 happens later and ends later
        else if (event1[0] <= event2[0] && event1[0] <= event2[1] && event1[1] >= event2[0] && event1[1] <= event2[1]){
            return true;
        }
        // event 2 happens later and ends earlier
        else if (event1[0] <= event2[0] && event1[0] <= event2[1] && event1[1] >= event2[0] && event1[1] >= event2[1]){
            return true;
        }
        // event 2 happens earlier and ends later
        else if (event1[0] >= event2[0] && event1[0] <= event2[1] && event1[1] >= event2[0] && event1[1] <= event2[1]){
            return true;
        }

        return false;
    }
};

// Runtime 4 ms Beats 59.3%
// Memory 11.5 MB Beats 12.12%
