#ID: ishan_sang
#PROG: FCTRL2
#LANG: Python               

def fact(n):
    ans=1
    for n in range(n,1,-1):
        ans*=n
    return ans

t=int(input())

for t in range(t,0,-1):
    n=int(input())
    print(fact(n),"\n")
