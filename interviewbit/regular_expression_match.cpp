int Solution::isMatch(const string _A, const string _B) {

    // to make strings one indexed 
    // because we need to consider empty strings too
    // so it is better to make it one indexed
    string A = ' '+ _A;
    string B = ' '+ _B;
    int n = A.size();
    int m = B.size();

    vector<vector<bool>> dp(n,vector<bool>(m,false));
    // dp[i][j] represents matching first i characters of A
    // with first j characters of B

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            // matching empty string
            // if there are two empty strings then 
            // their match would be true
            if(i==0 && j==0){
                dp[i][j] = true;
                continue;
            }
            if(i==0){
                if(B[j]=='*')dp[i][j] = dp[i][j-1];
                // otherwise default value is false
                // if our A is ""(empty string)
                // are our B is "**" then dp[i][2] = dp[i][1] = dp[i][0] = true
                // and if B is "a*" then dp[i][2] = dp[i][1] = false
                continue;
            }
            if(j==0){
                //default value is false
                // i>0 and j = 0 
                // there is no way to match this string
                // A="a", B = ""
                continue;
            }
            if(B[j]=='?'|| A[i]==B[j]){
                // in this case we can match one characters
                // A = aac , B = aa? , then dp[3][3] = dp[2][2] = true
                // A = abc , B = ab? , then dp[3][3] = dp[2][2] = false

                // abc , abc ab = ab  => true
                // A = acb , B = abb, A = ac B = ab  => false
                // A = acb, B = ac? -> acb
                dp[i][j] = dp[i-1][j-1];
            }
            else if (B[j]=='*'){
                // we can match any number of characters including zero
                // zero characters
                // A = aa, B = aa* , then dp[2][3] = dp[2][2] that is dp[i][j-1] = true
                // more than zero characters
                // dp[i][j] = dp[i-1][j]
                // A = acbc, B = aa*, then - > B= aa*c -> B = aabc
                // dp[4][3] = dp[3][3] = true;
                // dp[3][3] = dp[2][3] = true 
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    // returning  the final match value of whole A and B string 
    return dp[n-1][m-1];
}

/*
abc
ab*

Time : O(n*m)
Space : O(n*m)

*/
