n = int(input())
k = int(input())

dp = [[0 for j in range(k)] for i in range(n)]

for j in range(1, k):
  dp[0][j] = 1

for i in range(1, n):
  for j in range(k):
    for l in range(k):
      if not (j == 0 and l == 0):
        dp[i][j] += dp[i-1][l]

print(sum(dp[n-1]))