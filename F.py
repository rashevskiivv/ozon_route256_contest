def solution():
    k = int(input())

    arr = input().split(',')

    used = [0] * 105
    for x in arr:
        try:
            value = int(x)
            used[value] = 1
        except:
            l, r = map(int, x.split('-'))

            for i in range(l, r + 1):
                used[i] = 1

    pred = 0
    used[0] = 1
    used[k + 1] = 1

    ans = []
    cur = []
    for i in range(1, k + 2):
        if used[i] == 1 and used[i - 1] == 0:
            ans.append((cur[0], cur[-1]))
            cur = []

        if used[i] == 0:
            cur.append(i)

    length = len(ans)
    for i in range(length):
        l, r = ans[i]

        if l == r:
            print(l, end='')
        else:
            print(l, '-', r, end='', sep='')
        if i != (length - 1):
            print(',', end='')
        else:
            print()


t = int(input())

for _ in range(t):
    solution()
