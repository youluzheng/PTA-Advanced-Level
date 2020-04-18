line1 = list(map(float, input().split(' ')[1:]))
line2 = list(map(float, input().split(' ')[1:]))

data_map = {}

for i in range(0, len(line1), 2):
    for j in range(0, len(line2), 2):
        if line1[i] + line2[j] not in data_map:
            data_map[line1[i] + line2[j]] = line1[i+1] * line2[j+1]
        else:
            data_map[line1[i] + line2[j]] += line1[i+1] * line2[j+1]

keys_list = list(data_map.keys())
keys_list.sort(reverse=True)

output = ""

for num in keys_list:
    if data_map[num] != 0:
        output += " " + str(int(num)) + " " + '{:.1f}'.format(data_map[num])
    else:
        data_map.pop(num)

print(str(len(data_map)) + output)