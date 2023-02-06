t = int(input())
big = 5
small = 4
for _ in range(t):
    s = input().strip()
    k = 0
    idx = 0
    result = []
    usingBig = False
    resultFlag = False
    z = 0
    if len(s) >= small:
        for i in range(len(s)):
            if k == 2:
                usingBig = False
                if s[i].isdigit():
                    usingBig = True
                if usingBig:
                    if len(s[idx:idx + big]) != big or (len(s[idx + big:]) < small and len(s[idx + big:]) != 0):
                        resultFlag = True
                        break
                    c = s[idx:idx + big]
                    if c[0].isalpha() and c[1].isdigit() and c[2].isdigit() and c[3].isalpha() and c[4].isalpha():
                        result.append(s[idx:idx + big])
                        idx += big
                        k -= big
                    else:
                        resultFlag = True
                        break
                else:
                    if len(s[idx:idx + small]) != small or (len(s[idx + small:]) < small and len(s[idx + small:]) != 0):
                        resultFlag = True
                        break
                    c = s[idx:idx + small]
                    if c[0].isalpha() and c[1].isdigit() and c[2].isalpha() and c[3].isalpha():
                        result.append(s[idx:idx + small])
                        idx += small
                        k -= small
                    else:
                        resultFlag = True
                        break
            k += 1
    else:
        resultFlag = True
    if resultFlag:
        print('-')
    else:
        for s in result:
            print(s, end='')
            print(' ', end='')
        print()
