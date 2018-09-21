class Solution {
public:
    //想要吃透这道题背后的数学问题不容易，可以先看以下链接理解以下，我至今还没有吃透
    // https://blog.csdn.net/joylnwang/article/details/6769160
    // https://brilliant.org/wiki/egg-dropping/#2-eggs-100-floors
    

    int DroppingMax(int eggs, int times){
        if(eggs == 1)
        {
            return times;
        }

        if(eggs >= times)
        {
            return (unsigned int)pow(2, times) - 1;
        }

        return DroppingMax(eggs, times -1) + DroppingMax(eggs -1, times - 1) + 1;
    }

    
    int superEggDrop(int K, int N) {
        int times = 1;
 
        while( DroppingMax(K, times) < N)
        {
            ++times;
        }

        return times;
    }
    
    
    
    //常见的另外两种解法
    /*
    int superEggDrop(int K, int N) {
        int dp[K + 1];
        for( int i = 0; i <= K; i++ )
            dp[i] = 1;
        int r = 0;
        while( dp[K] < N + 1 ){
            for( int i = K; i > 0; i-- )
                dp[i] += dp[i-1];
            r++;
        }
        return r;
    }


    int superEggDrop(int K, int N) {
        vector<int> dp(K+1);
        int step = 0;
        for (; dp[K] < N; step++) {
            for (int i = K; i > 0; i--)
                dp[i] += (1+ dp[i-1]);
        }
        return step;
    }*/
    
};