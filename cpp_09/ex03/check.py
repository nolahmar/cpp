if __name__ == "__main__":
    file = open("res", "r")
    arr = []
    read = False

    for line in file:
        if line.startswith("Time"):
            continue
        if read:
            res = line.split(' ')
            for n in res:
                arr.append(int(n))
            continue
        if line.startswith("After"):
            read = True
            res = line.split(' ')
            for i in range(1, len(res)):
                arr.append(int(res[i]))
    
    sorted_arr = sorted(arr)
    if sorted_arr == arr:
        print("\033[92m OK\033[00m")
    else:
        print("\033[91m KO\033[00m")
        