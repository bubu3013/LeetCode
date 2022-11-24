class MyQueue {
public:
    stack<int> st_1;
    stack<int> st_2; 
    MyQueue() {
        return; 
    }  
    void push(int x) {
        if (st_1.empty() == true){
            st_1.push(x);
        }else{
            while (st_1.empty() == false){
                int tmp = st_1.top(); 
                st_1.pop();
                st_2.push(tmp);
            }
            st_2.push(x);
            while(st_2.empty() == false){
                int tmp = st_2.top(); 
                st_2.pop();
                st_1.push(tmp);
            }
        }
        return;
    }
    
    int pop() {
        if (st_1.empty() == true){
            return 0;
        }else{
            int tmp = st_1.top();
            st_1.pop();
            return tmp;
        }
    }
    int peek() {
        if (st_1.empty() == true){
            return 0;
        }else{
            return st_1.top();
        }
    }
    bool empty() {
        return st_1.empty();
    }
};


// Runtime 0 ms Beats 100% 
// Memory 7 MB Beats 89.81%
