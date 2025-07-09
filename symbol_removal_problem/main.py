string = input("\033[92mEnter the string to process: ")

def remover(string,num, k):
    string = string[:num] + string[num+1:]  # remove the character at index num
    
    if string[num] == " ":
        num += 1 # skip the space at index num
    
    while k >= 1 and num < len(string):
        if string[num] in ["*", "$", "#"]:
            string = remover(string, num, k + 1)
        else:
            string = string[:num] + string[num+1:]  # remove the character at the next index
        k -= 1
    
    return string

i = 0
length = len(string)

while i<length:
    if string[i] in ["*", "$", "#"]:
        string = remover(string, i, 1)
    
    length = len(string)
    i += 1

print(f"Formatted string: {string}\033[0m")
