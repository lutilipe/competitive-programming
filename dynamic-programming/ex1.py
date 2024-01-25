def sum(dp, n):
    dp[0] = 0;
    for i in range(1, n+1):
        dp[i] = dp[i-1]+i

n = 60
dp = [0]*(n+1)
sum(dp, n)
print(dp[n])