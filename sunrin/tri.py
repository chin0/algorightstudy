n = input()
#n =  9

_max = n/2+1 if (n % 2) else n/2
cnt = 0

debug_cnt = []
debug_cnt2 = []

for i in range(1,n/3+1):
    cur_cnt = 0
    for j in range(_max/2,_max+1):
        temp = n-i-j
        if (i <= j and j <= temp and i+j+temp == n and temp < _max):
            cnt += 1


print cnt



