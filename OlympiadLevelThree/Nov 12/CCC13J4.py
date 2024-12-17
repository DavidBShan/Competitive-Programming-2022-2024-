import itertools
TL = int(input())
N = int(input())
L = []
W = []
B = 0
for i in range(N):
  Y = int(input())
  L.append(Y)

for j in range(0, len(L)+1):
  for subset in itertools.combinations(L, j):
    if sum(subset) <= TL:
      W.append(subset)

for i in range(len(W)):
  if len(W[i]) > B:
    B = len(W[i])

print(B)