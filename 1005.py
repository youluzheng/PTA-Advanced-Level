digit_to_english = {0:'zero', 1:'one', 2:'two', 3:'three', 4:'four',
                    5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine'}

n = str(sum(map(int, input())))
for i in n[:-1]:
    print(digit_to_english[int(i)], end=' ')

print(digit_to_english[int(n[-1])], end='')

