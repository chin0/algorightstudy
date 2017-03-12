m = 3
n = 1

for i in range(100):
    if m % n == 0:
        m+=2
        n+=2
        continue
    a = (m ** 2 + n**2)/2
    b = m * n
    c = (m ** 2 - n ** 2)/2
    if 1000 % (a+b+c) == 0:
        d = 1000 / (a+b+c)
        for i in (a,b,c):
            print i*d
        break
    m += 2
    n += 2


