# LBYARCHMCO2
HOW TO COMPILE:
Directory = D
D:>nasm -f win64 -o asmfunc.obj asmfunc.asm
D:>gcc -c -o main.obj main.c
D:>gcc -o image_con.exe main.obj asmfunc.obj
D:>image_con.exe

Average Execution Time:
(10 x 10): 0 (0)
(100 x 100): 0 (0)
(1000 x 1000): 4.367 (4.366666...)

Short Analysis:
We think it was very fast due to it finishing in 0.00 ms for 10 x 10, and 100 x 100.
And the 1000 x 1000 finishes in an average of 4 ms runned 30 times.

Correctness Check:
![image](https://github.com/user-attachments/assets/52d00f4d-8482-4f93-8d57-d53d533b7173)

