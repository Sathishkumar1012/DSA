class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        if(ops.size()==1) {
            return stoi(ops[0]);
        }
        
        stack<int>st;
        int i=0;
        while(i<n) {
            if(ops[i]=="+") {
                int t=st.top();
                st.pop();
                int s=st.top()+t;
                st.push(t);
                st.push(s);
            }
            
            else if(ops[i]=="D") {
                int t=2*st.top();
                st.push(t);
            }
            
            else if(ops[i]=="C")
                st.pop();
            else 
                st.push(stoi(ops[i]));
            i++;
        }
        
        int res=0;
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};