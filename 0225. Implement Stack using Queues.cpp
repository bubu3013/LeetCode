class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        return;
    }
    
    void push(int x) {
        if (q1.empty() == true){
            q1.push(x);
        }else{
            while (q1.empty() == false){
                int tmp = q1.front(); q1.pop();
                q2.push(tmp);
            }
            q1.push(x);
            while (q2.empty() == false){
                int tmp = q2.front(); q2.pop();
                q1.push(tmp);
            }
        }
        return;
    }
    
    int pop() {
        int tmp = -1;
        if (q1.empty() == true){
            tmp = 0;
        }else {
            tmp = q1.front();
            q1.pop();
        }
        return tmp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// Runtime 0 ms Beats 100% 
// Memory 7 MB Beats 30.98%
