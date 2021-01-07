def pow(n, p):
    if p == 'S':
        return n
    elif p == 'D':
        return n * n
    elif p == 'T':
        return n * n * n

def solution(dartResult):
    answer = 0
    idx = -1
    a = [0 for _ in  range(3)]
    size = len(dartResult)

    i = 0
    while i < size:
        cur = dartResult[i]

        if cur == 'S' or cur == 'D' or cur == 'T':
            a[idx] = pow(a[idx], cur)
        elif cur == '*':
            if idx != 0:
                a[idx - 1] *= 2
            a[idx] *= 2
        elif cur == '#':
            a[idx] *= -1
        else:
            n = ord(cur) - ord('0')
            if cur == '1' and dartResult[i + 1] == '0':
                n = 10
                i += 1
            idx += 1
            a[idx] = n
        i += 1
    for i in range(3):
        print(a[i])
        answer += a[i]
    return answer

print(solution("1S2D*3T"))