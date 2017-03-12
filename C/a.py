input_data = raw_input()

split_data = input_data.split(' ')

result = 0 

print split_data
for i in split_data:
    if not i == '':
        result += 1

print result
