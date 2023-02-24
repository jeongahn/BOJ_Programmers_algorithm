
def dfs():
    if len(arr)==M:
        if arr not in total:
            print(' '.join(map(str,arr)))
        return
    remember = 0
    for i in range(0,N):
        if not visited[i] and remember != lst[i]:
            visited[i] = True
            arr.append(lst[i])
            remember = lst[i]
            dfs()
            visited[i] = False
            arr.pop() 


N,M=map(int,input().split())
lst = list(map(int, input().split()))
lst.sort()

arr = []
total = []
visited = [False] * N

dfs()