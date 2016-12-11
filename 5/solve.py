import md5

puzzle = "ffykfhsq"

indices = []
ans = [] * 8
result = list("XXXXXXXX")

currentNumber = -1
while len(indices) < 8:
    currentNumber += 1
    h = md5.new(puzzle + str(currentNumber)).hexdigest()
    if h[:5] == "00000" and h[5] >= '0' and h[5] <= '7':
        place_pos = int(h[5])
        if place_pos in indices:
            continue
        indices.append(place_pos)
        result[place_pos] = h[6]
        print result
print "".join(result)
        
