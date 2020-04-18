data_num, output_num = map(int, input().split(" "))
data_list = []
for i in range(data_num):
    input_line = input().split(" ")
    line_data = [input_line[0]]
    line_data.extend(list(map(int, input_line[1:])))
    line_data.append((round(sum(line_data[1:])/3)))
    data_list.append(line_data)

def courseSort(data_list, line_id):
    data_list.sort(key=lambda i:i[line_id], reverse=True)
    sort_dict = {}
    rank = 1
    score = -1
    for index, item in enumerate(data_list):
        if item[line_id] != score:
            score = item[line_id]
            rank = index+1
        sort_dict[item[0]] = rank
    return sort_dict

c_sort = courseSort(data_list, 1)
m_sort = courseSort(data_list, 2)
e_sort = courseSort(data_list, 3)
a_sort = courseSort(data_list, 4)

output = ''
for i in range(output_num):
    sno = input()
    if sno not in a_sort:
        output += "N/A\n"
    else:
        max_rank = min([a_sort[sno], c_sort[sno], m_sort[sno], e_sort[sno]])
        if a_sort[sno] == max_rank:
            output += str(max_rank) + " A\n"
        elif c_sort[sno] == max_rank:
            output += str(max_rank) + " C\n"
        elif m_sort[sno] == max_rank:
            output += str(max_rank) + " M\n"
        else:
            output += str(max_rank) + " E\n"

print(output.rstrip())