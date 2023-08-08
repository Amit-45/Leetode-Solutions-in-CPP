class MinStack {
public:
    stack<int> vals, mn;

    void push(int val) {
        vals.push(val);
        if (mn.empty() || val <= mn.top()) {
            mn.push(val);
        }
    }

    void pop() {
        if (vals.top() == mn.top()) {
            mn.pop();
        }
        vals.pop();
    }

    int top() {
        return vals.top();
    }

    int getMin() {
        return mn.top();
    }
};
