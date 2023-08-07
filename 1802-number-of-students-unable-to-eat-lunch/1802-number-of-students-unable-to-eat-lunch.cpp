class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(auto s:students){
            q.push(s);
        }
        int i=0, c=0;
        while(i<sandwiches.size()){
            if(sandwiches[i]==q.front()){
                q.pop();
                i++;
            } else {
                int x=q.front();
                q.pop();
                q.push(x);
            }
            c++;
            if(c==10001)
                break;
        }
        return q.size();
    }
};