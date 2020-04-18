def getNum(num, radix):
    sum = 0
    count = 0
    for i in num[::-1]:
        if i <= '9':
            sum += int(i)*pow(radix, count)
        else:
            sum += (ord(i)-87)*pow(radix, count)
        count += 1
    return sum

num0 = 0
num1 = 0  
data_list = input().split(" ")

if data_list[2] == '1':
    num0 = getNum(data_list[0], int(data_list[3]))
    num1 = data_list[1]
else:
    num0 = getNum(data_list[1], int(data_list[3]))
    num1 = data_list[0]

if len(num1) == 1 and getNum(num1, 36) < num0:
    print("Impossible")
    exit()

max_c = max(num1)
if max_c > '9':
    max_c = ord(max_c) - 87
else:
    max_c = int(max_c)

radix = max_c + 1
result = getNum(num1, radix)

basic = 5
while result < num0:
    radix *= basic
    result = getNum(num1, radix)
    if result > num0:
        radix //= basic
        basic = radix // 2
        result = getNum(num1, radix)
        while result < num0:
            if basic == 0:
                break
            radix += basic
            result = getNum(num1, radix)
            if result > num0:
                radix -= basic
                result = getNum(num1, radix)
                basic //= 2

if result == num0:
    print(radix)
else:
    print("Impossible")
