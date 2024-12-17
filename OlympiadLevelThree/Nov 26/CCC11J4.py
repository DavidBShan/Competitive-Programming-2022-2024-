import sys
DoNot = [[0,-1],[0,-2],[0,-3],[1,-3],[2,-3],[3,-3],[3,-4],[3,-5],[4,-5],[5,-5],[5,-4],[5,-3],[6,-3],[7,-3],[7,-4],[7,-5],[7,-6],[7,-7],[6,-7],[5,-7],[4,-7],[3,-7],[2,-7],[1,-7],[1,-6],[1,-5]]
A = ""
C = ""
B = 0
A,C = input().split()
B = int(C)
x = -1
y = -5
flag = True
def safe(DoNot,x,y):
    if [x,y] in DoNot:
        return False
    return True

while A!="q":
    if A == "d":
        if [1,-5] in DoNot:
            DoNot.remove([1,-5])
        for i in range(B):
            y-=1
            if (safe(DoNot,x,y)):
                DoNot.append([x,y])
                if [1,-5] in DoNot:
                    DoNot.remove([1,-5])
            else:
                flag = False
        if flag == True:
            print(str(x)+" "+str(y)+" safe")
        else:
            print(str(x)+" "+str(y)+" DANGER")
            sys.exit()
    elif A == "u":
        for i in range(B):
            y+=1
            if (safe(DoNot,x,y)):
                DoNot.append([x,y])
                if [1,-5] in DoNot:
                    DoNot.remove([1,-5])
            else:
                flag = False
        if flag == True:
            print(str(x)+" "+str(y)+" safe")
        else:
            print(str(x)+" "+str(y)+" DANGER")
            sys.exit()
    elif A == "l":
        for i in range(B):
            x-=1
            if (safe(DoNot,x,y)):
                DoNot.append([x,y])
                if [1,-5] in DoNot:
                    DoNot.remove([1,-5])
            else:
                flag = False
        if flag == True:
            print(str(x)+" "+str(y)+" safe")
        else:
            print(str(x)+" "+str(y)+" DANGER")
            sys.exit()
    elif A == "r":
        for i in range(B):
            x+=1
            if (safe(DoNot,x,y)):
                DoNot.append([x,y])
                if [1,-5] in DoNot:
                    DoNot.remove([1,-5])
            else:
                flag = False
        if flag == True:
            print(str(x)+" "+str(y)+" safe")
        else:
            print(str(x)+" "+str(y)+" DANGER")
            sys.exit()
    if [-1,-5] not in DoNot:
        DoNot.append([-1,-5])
    A,C = input().split()
    B = int(C)