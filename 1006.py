n = int(input())

if n == 0:
    exit()

min_person = ["", "23:59:59"]
max_person = ["", "00:00:00"]

for i in range(n):
    data = input().split(" ")
    if data[1] <= min_person[1]:
        min_person = [data[0], data[1]]
    
    if data[2] >= max_person[1]:
        max_person = [data[0], data[2]]

print(min_person[0] + " " + max_person[0], end="")