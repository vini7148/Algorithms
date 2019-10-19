# Uses python3
import sys

#def optimal_summands(n):
    #summands = []
    #write your code here
    #return summands

def optimal_summands(n):
    summands = []
    for i in range(1,n + 1):
        if last_number(i, n):
            #found the last one, append to summands and break.
            summands.append(i)
            break
        
        #otherwise, append i to summands, n = n - i and increase i by 1.
        summands.append(i)
        n = n - i
        i = i +1

    return summands

def last_number(i, n):
    #check that i * 2 >= n. If true, you got the last one
    if i*2>=n:
        return 1
    else:
        return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
