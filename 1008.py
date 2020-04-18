data_list = list(map(int, input().split(" ")[1:]))

time = 0
floor = 0

for num in data_list:
    if num > floor:
        time += 6*(num-floor) + 5
    elif num < floor:
        time += 4*(floor-num) + 5
    else:
        time += 5
    floor = num

print(time)