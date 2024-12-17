N = int(input())
ListSun = [[0]*N]*N
TempSun = []
TempL = [0]*3
for i in range(N):
    ListSun[i] = list(input().split())
    for j in range(N):
        ListSun[i][j] = int(ListSun[i][j])

def checkListGood(L,N):
    for i in range(N):
        if sorted(L,key=lambda x: (x[i])) != L:
            return False
    for i in range(N):
        if sorted(L[i]) != L[i]:
            return False
    return True

def CheckRotations(Temp,L,N):
    TempL = []
    if checkListGood(L,N):
        return L
    TempL = []
    for i in range(N):
        for j in range(N):
            TempL.append(L[j][N-1-i])
        Temp.append(TempL[:])
        TempL = []
    if checkListGood(Temp,N):
        return Temp
    else:
        Temp = []
    TempL = []
    for i in range(N):
        for j in range(N):
            TempL.append(L[N-1-i][N-1-j])
        Temp.append(TempL[:])
        TempL = []
    if checkListGood(Temp,N):
        return Temp
    else:
        Temp = []
    TempL = []
    for i in range(N):
        for j in range(N):
            TempL.append(L[N-1-j][i])
        Temp.append(TempL[:])
        TempL = []
    if checkListGood(Temp,N):
        return Temp
    else:
        Temp = []
GoodL = CheckRotations(TempSun,ListSun,N)
for i in range(len(GoodL)):
    for j in range(len(GoodL[i])):
        GoodL[i][j] = str(GoodL[i][j])

print(*(' '.join(row) for row in GoodL), sep='\n')
