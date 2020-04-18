n = int(input())
data_list = list(map(int, input().split(" ")))

temp_data = 0
max_data = [0, data_list[0], data_list[-1]]

left = -1
zero_flag = 0
for index, num in enumerate(data_list):

    if num <= 0 and temp_data + num <= 0:
        temp_data = 0
        left = index
        if num == 0:
            zero_flag = 1
    else:
        temp_data += num

    if temp_data > max_data[0]:
        max_data = [temp_data, data_list[left+1], num]

if max_data[0] == 0 and zero_flag == 1:
    print('0 0 0')
else:
    print(str(max_data[0]) + " " + str(max_data[1]) + " " + str(max_data[2]))