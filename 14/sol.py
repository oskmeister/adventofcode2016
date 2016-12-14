import md5 
import sys

SALT = "qzyelonm"

hashes = dict()

def do_hash(s):
    if s in hashes:
        return hashes[s]
    h = s
    for i in xrange(2017):
        h = md5.new(h).hexdigest()
    hashes[s] = h
    return h

def solve():
    found_keys = 0
    current_number = 0
    while found_keys < 64:
        h = do_hash(SALT+str(current_number))
        found_char = None
        for i in xrange(len(h) - 2):
            sub_triple = h[i:i+3] 
            if sub_triple == len(sub_triple) * sub_triple[0]:
                found_char = sub_triple[0]
                break
        if found_char:
            found_in_next_thousand = False
            for i in xrange(current_number + 1, current_number + 1001):
                h2 = do_hash(SALT+str(i))
                for j in xrange(len(h2) - 4):
                    sub_quint = h2[j:j+5] 
                    if sub_quint == len(sub_quint) * found_char:
                        found_in_next_thousand = True
                        break
                if found_in_next_thousand == True:
                    break
            if found_in_next_thousand:
                print current_number, h, i, h2
                found_keys += 1
        current_number += 1

if __name__ == "__main__":
    solve()
