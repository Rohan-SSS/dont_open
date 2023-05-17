def toh(n, a, b, c):
    if n>0:
        toh(n-1, a, c, b)
        print(f"{n} from {a} to {c}")
        toh(n-1, b, a, c)

if __name__=='__main__':
    n = int(input("n "))
    toh(n, 'A', 'B', 'C')