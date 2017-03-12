a = raw_input()
result = a.split(" ")

blank = []
for i in result:
    if len(i) != 0:
        blank.append(i)

print len(blank)
