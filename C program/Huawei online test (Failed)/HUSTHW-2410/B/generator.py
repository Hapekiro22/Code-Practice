from cyaron import *
import random as rd

for cas in range(1, 21):
    io = IO(file_prefix="B", data_id=cas) # 生成B1.in, B2.in, ... B20.in
    st = [rd.randint(-10 ** 3, 10 ** 3) for i in range(2)]
    ed = [rd.randint(-10 ** 3, 10 ** 3) for i in range(2)]
    dist = abs(st[0] - ed[0]) + abs(st[1] - ed[1])
    k = rd.randint(0, dist * 6)
    io.input_writeln(k)
    io.input_writeln(st)
    io.input_writeln(ed)
    io.output_gen("std")