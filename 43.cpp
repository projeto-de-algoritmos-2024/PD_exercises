class Solution {
public:

int trap(vector<int>& height) {
    int ans = 0;
    auto n = height.size();
    vector<int> lm(n);
    vector<int> rm(n);

    lm[0] = height[0];
    for(int i = 1; i < n ; i++) {
        lm[i] = max(lm[i-1], height[i]);
    }
    rm[n-1] = height[n-1];
    for(int i = n - 2; i >= 0; i--) {
        rm[i] = max(rm[i+1],height[i]);
    }
    for(int i = 0; i < n; i++) {
        ans += min(rm[i],lm[i]) - height[i];
    }

    return ans;
    }
};
