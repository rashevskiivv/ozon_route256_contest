t = int(input())
for _ in range(t):
    nums = list(map(int, input().strip().split()))
    d = {1: 0, 2: 0, 3: 0, 4: 0}
    for i in range(10):
        if nums[i] == 1:
            d[1] += 1
        if nums[i] == 2:
            d[2] += 1
        if nums[i] == 3:
            d[3] += 1
        if nums[i] == 4:
            d[4] += 1
    if d[1] != 4:
        print('NO')
        continue
    if d[2] != 3:
        print('NO')
        continue
    if d[3] != 2:
        print('NO')
        continue
    if d[4] != 1:
        print('NO')
        continue
    print('YES')
