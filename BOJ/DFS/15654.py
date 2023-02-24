def dfs(start):
    if len(arr)==M:
        print(' '.join(map(str,arr)))
        return
    
    for i in range(0,N):
        if lst[i] not in arr:
            arr.append(lst[i])
            dfs(i)
            arr.pop() 


N,M=map(int,input().split())
lst = list(map(int, input().split()))
lst.sort()

arr = []

dfs(0)