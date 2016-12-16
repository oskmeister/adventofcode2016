def expand(a):
    b = a[::-1]
    newb = list()
    for e in b:
        newb.append('1' if e == '0' else '0') 
    return a + list('0') + newb

def hash(l):
    i = 0
    r = list()
    while i < len(l):
        r.append('1' if l[i] == l[i+1] else '0') 
        i += 2
    return r

if __name__ == "__main__":
    start_state = "01000100010010111"
    desired_len = 35651584 

    cur = list(start_state)
    while len(cur) <= desired_len:
        cur = expand(cur)
    cur = cur[:desired_len]

    h = hash(cur)
    while len(h) % 2 == 0:
        h = hash(h)

    print "".join(h)
