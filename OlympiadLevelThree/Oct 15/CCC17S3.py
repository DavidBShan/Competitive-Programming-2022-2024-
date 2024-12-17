N = int(input())
B = map(int, input().split())
LN = [0]*2001
W = [0]*4002
for i in B:
  LN[i] += 1
for x in range(len(LN) - 1):
    for y in range(x, len(LN)):
      if LN[x] != 0:
        if x == y:
          W[x+y] += LN[x]//2
        else:
          W[x+y] += min(LN[x], LN[y])

print(max(W), W.count(max(W)))