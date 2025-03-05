from cyaron import *
import random as rd


for cas in range(1, 51):
    io = IO(file_prefix="D", data_id=cas) # 生成D1.in, D2.in, ... D50.in
    n = (cas - 1) // 10 + 1
    ismine = [[rd.randint(0, 1) for j in range(n + 2)] for i in range(n + 2)]
    cnt = [[0 for j in range(n + 2)] for i in range(n + 2)]
    for i in range(n + 2):
        for j in range(n + 2):
            if i == 0 or i == n + 1 or j == 0 or j == n + 1:
                ismine[i][j] = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            cnt[i][j] = ismine[i - 1][j - 1] + ismine[i - 1][j] + ismine[i - 1][j + 1] + ismine[i][j - 1] + ismine[i][j + 1] + ismine[i + 1][j - 1] + ismine[i + 1][j] + ismine[i + 1][j + 1]
    io.input_writeln(n)
    for i in range(1, n + 1):
        line = ''
        for j in range(1, n + 1):
            masked = rd.randint(0, 1)
            if masked:
                line += '?'
            elif ismine[i][j]:
                line += '*'
            else:
                line += str(cnt[i][j])
        io.input_writeln(line)
    io.output_gen("std")
    