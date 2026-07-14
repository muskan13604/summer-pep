class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        set<int>st;
        q.push({start, 0});
        st.insert(start);
        while(!q.empty()){
            pair<int, int>p=q.front();
            int element = p.first;
            int steps = p.second;
            q.pop();
            
            if(element==end){
                return steps;
            }
            for(int value:arr){
                int multiply = (element*value)%1000;
                if(st.find(multiply) == st.end()){
                    q.push({multiply, steps+1});
                    st.insert(multiply);
                }
            }
        }
        return -1;
    }
};`