def max_coin(nums):
    memo = {}
    nums = [1] + nums + [1]
    def recurse(i, j):
        key = (i, j)
        if key in memo:
            return memo[key]
        if i > j:
            return 0
        
        res = 0
        for k in range(i, j + 1):
            left = recurse(i, k-1)
            right  = recurse(k+1, j)
            cur = nums[k-1]*nums[k]*nums[k+1]
            res = max(res, cur + left + right)
        
        memo[key] = res
        return res
    return recurse(1, len(nums) - 2)

def max_coin_bottom_up(nums):
    nums = [1] + nums + [1]
    dp = [[0]*len(nums) for _ in range(len(nums))]
    
    for length in range(1, len(nums) - 2):
        for i in range(1, len(nums)- length - 1):
            j = i + length - 1
            
            for k in range(i, j+1):
                left = dp[i][k-1] if k - 1 >= i else 0
                right = dp[k+1][j] if k + 1 <= j else 0
                cur = nums[i-1]*nums[k]*nums[j+1]
                dp[i][j] = max(dp[i][j], right + left + cur)
    
    return dp[1][len(nums)-2]

print(max_coin_bottom_up([1,5]))