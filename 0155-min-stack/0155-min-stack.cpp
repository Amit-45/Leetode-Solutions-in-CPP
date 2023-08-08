class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            int mn = val;
            st.push({val,val});
        }
        else{
            int mn = min(st.top().second,val);
            st.push({val,mn});
        }
        
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return 0;
        }
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};