line = input()
lineList = line.split(" ")
res = eval(lineList[0] + "+" +lineList[1])
print("{:,}".format(res))