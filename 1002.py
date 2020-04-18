line1 = input()
line2 = input()
count1, str1 = line1.split(" ", 1)
count2, str2 = line2.split(" ", 1)
list1 = str1.split(" ")
list2 = str2.split(" ")
dict1 = {}
for i in range(0, 2*int(count1), 2):
    if list1[i] in dict1:
        if dict1[list1[i]] + float(list1[i+1]) == 0:
            dict1.pop(list1[i])
        else:
            dict1[list1[i]] += float(list1[i+1])
    else:
        dict1[list1[i]] = float(list1[i+1])

for i in range(0, 2*int(count2), 2):
    if list2[i] in dict1:
        if dict1[list2[i]] + float(list2[i+1]) == 0:
            dict1.pop(list2[i])
        else:
            dict1[list2[i]] += float(list2[i+1])
    else:
        dict1[list2[i]] = float(list2[i+1])

resList = list(dict1)
resList = [int(item) for item in resList]
resList.sort(reverse=True)
length = len(resList)
resStr = str(length)
print(resStr, end="")

for i in range(length):
    print(" " + str(resList[i]) + " " + "{:.1f}".format(dict1[str(resList[i])]), end="")

