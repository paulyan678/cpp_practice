import numpy as np

def mat_mul_order(dims):
    memo = {}

    def recurse(i, j):
        key = (i, j)
        if key in memo:
            return memo[key]
        if i == j:
            return 0, f'M{i}'
        res = np.inf
        order = ""
        for k in range(i, j):
            left_ops, left_order = recurse(i, k)
            right_ops, right_order = recurse(k + 1, j)
            cur_ops = dims[i][0] * dims[k][1] * dims[j][1]
            total_ops = left_ops + right_ops + cur_ops

            if total_ops < res:
                res = total_ops
                order = f'({left_order} x {right_order})'
        
        memo[key] = (res, order)
        return res, order

    min_ops, optimal_order = recurse(0, len(dims) - 1)
    return min_ops, optimal_order

# Example usage
dims = [(2, 3), (3, 4), (4, 2)]
min_ops, optimal_order = mat_mul_order(dims)
print(f"Minimum number of operations: {min_ops}")
print(f"Optimal multiplication order: {optimal_order}")