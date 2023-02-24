def dfs(start):
    if len(arr)==M:
        print(' '.join(map(str,arr)))
        return
    
    for i in range(start,N+1):
        if i not in arr:
            arr.append(i)
            dfs(i+1)
            arr.pop() #각 숫자를 넣고 DFS가 끝나면 다시 비워주기... 이걸 이해하는데 오래걸렸던...


N,M=map(int,input().split())
arr = []

dfs(1)