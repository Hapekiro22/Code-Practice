from cyaron import *
from random import randint
from random import choice

for cas in range(1, 21):
    io = IO(file_prefix="A", data_id=cas)
    studenttype = 'U' if cas <= 15 else choice(['M', 'D'])
    entrance = randint(2023, 2024) if cas <= 10 else randint(2020, 2022)
    id = studenttype + str(entrance) + str(randint(10000, 99999))
    io.input_writeln(id)
    io.output_gen("std")
    