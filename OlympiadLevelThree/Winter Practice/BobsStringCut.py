import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()
pre = [set() for i in range(n)]
for i in range(n):
    if i!=0:
        pre[i] = pre[i-1].copy()
    pre[i].add(s[i])
suf = set()
ans = 0
for i in range(n-1, 0, -1):
    suf.add(s[i])
    ans = max(ans,len(suf.intersection(pre[i-1])))
print(ans)