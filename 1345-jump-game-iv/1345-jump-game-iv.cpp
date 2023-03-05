class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) return 0;
        unordered_map<int, vector<int>> map;
        int step = 0;

        // fill the map
        for(int i = 0; i < n; i++){
            map[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            step++;
            int size = q.size();
            while(size--){
                int j = q.front();
                q.pop();

                if(j - 1 >= 0 && map.count(arr[j - 1])){
                    q.push(j - 1);
                }

                if(j + 1 < n && map.count(arr[j + 1])){
                    if(j + 1 == n - 1) return step;
                    q.push(j + 1);
                }

                if(map.count(arr[j])){
                    for(int k : map[arr[j]]){
                        if(k != j){
                            if(k == n - 1) return step;
                            q.push(k);
                        }
                    }
                    map.erase(arr[j]);
                }
            }
        }

        return step;
    }
};