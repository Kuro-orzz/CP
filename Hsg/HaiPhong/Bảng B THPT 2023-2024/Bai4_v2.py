t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    a = input()
    if k%2==0:
        print(0, end='')
    else:
        print(1, end='')
