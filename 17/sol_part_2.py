import md5

def shortest():
    INPUT = "qljzarfv"
    DIRS = [(-1,0),(1,0),(0,-1),(0,1)]
    DIRS_STR = ['U','D','L','R']
    GRID_SIZE = 4

    queue = []
    queue.append(("", (0,0)))

    ret = None
    while len(queue) > 0:
        def open_char(c):
            return c in ('b','c','d','e','f')

        cur = queue.pop(0)

        cur_path = cur[0]
        cur_point = cur[1]

        cr = cur_point[0]
        cc = cur_point[1]

        if cr == GRID_SIZE - 1 and cc == GRID_SIZE - 1:
            ret = cur_path
            continue

        cur_hash = md5.new(INPUT + cur_path).hexdigest()
        for i in xrange(4):
            dr = DIRS[i][0]
            dc = DIRS[i][1]
            nr = cr + dr
            nc = cc + dc
            if nr < 0 or nr > 3 or nc < 0 or nc > 3:
                continue
            if open_char(cur_hash[i]):
                queue.append((cur_path + DIRS_STR[i], (nr, nc)))
    return ret

if __name__ == "__main__":
    print shortest()
