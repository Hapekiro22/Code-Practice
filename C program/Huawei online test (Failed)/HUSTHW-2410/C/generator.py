from cyaron import *
import random as rd

for cas in range(1, 21):
    io = IO(file_prefix="C", data_id=cas)
    n = 1000 if cas <= 16 else 10 ** 5
    k = randint(1, n)
    io.input_writeln(n, k)
    score = [rd.randint(0, 100) for i in range(n)]
    credits = [rd.randint(1, 6) for i in range(n)]
    for i in range(n):
        io.input_writeln(score[i], credits[i])
    io.output_gen("std")