# Uses python3
import sys

def select_max_index(values,weights):
    ma=-1
    j=-1
    for i in range(n):
        if weights[i]!=0:
            if ma<values[i]/weights[i]:
                ma=values[i]/weights[i]
                j=i
    return j

def get_optimal_value(capacity, weights, values):
    value = 0.

    if capacity == 0:
        return 0
    for i in range(n):
        max_index = select_max_index(values, weights)
        if max_index >= 0:
            available_weights = min(capacity, weights[max_index])
            value = value + available_weights * values[max_index]/weights[max_index]
            weights[max_index] = weights[max_index] - available_weights
            capacity = capacity - available_weights
            
    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
