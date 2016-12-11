import sys

def parse(string):
    encryped = "".join(string.split('-')[:-1])
    number = string.split('-')[-1].split('[')[0]
    code = string.split('-')[-1].split('[')[1][:-1]
    print encryped, number, code

for line in sys.stdin.readlines():
    parse(line.strip())
