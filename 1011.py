def func(output):
    max = 0
    index = -1
    line = list(map(float, input().split(" ")))
    for i, num in enumerate(line):
        if max < num:
            max = num
            index = i
    if index == 0:
        output[0] += 'W '
    elif index == 1:
        output[0] += 'T '
    else:
        output[0] += 'L '
    return max

output = ['']
sum = 1
sum *= func(output)
sum *= func(output)
sum *= func(output)
print(output[0] + '{:.2f}'.format((sum*0.65-1)*2))