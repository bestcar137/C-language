cmake_minimum_required(VERSION 3.30)
project(C_language C)

set(CMAKE_C_STANDARD 11)

# --------------------
# main
# --------------------
add_executable(C_language main.c)

# --------------------
# ch2
# --------------------
add_executable(2_3 CH_code/ch2/2_3.c)
add_executable(2_4 CH_code/ch2/2_4.c)
add_executable(2_5 CH_code/ch2/2_5.c)

# --------------------
# ch3
# --------------------
add_executable(3_1 CH_code/ch3/3_1.c)
add_executable(3_2 CH_code/ch3/3_2.c)
add_executable(3_3 CH_code/ch3/3_3.c)
add_executable(3_4 CH_code/ch3/3_4.c)
add_executable(3_5 CH_code/ch3/3_5.c)
add_executable(3_6 CH_code/ch3/3_6.c)
add_executable(3_7 CH_code/ch3/3_7.c)
add_executable(3_8 CH_code/ch3/3_8.c)
add_executable(3_9 CH_code/ch3/3_9.c)

# --------------------
# ch4
# --------------------
add_executable(program4_1        CH_code/ch4/program4_1.c)
add_executable(program4_2        CH_code/ch4/program4_2.c)
add_executable(program4_3        CH_code/ch4/program4_3.c)
add_executable(program4_4        CH_code/ch4/program4_4.c)
add_executable(program4_5        CH_code/ch4/program4_5.c)
add_executable(program4_6        CH_code/ch4/program4_6.c)
add_executable(program4_7        CH_code/ch4/program4_7.c)
add_executable(program4_8        CH_code/ch4/program4_8.c)
add_executable(program4_9        CH_code/ch4/program4_9.c)

add_executable(HW4_1             CH_code/ch4/HW4_1.c)
add_executable(HW4_1_comment     CH_code/ch4/HW4_1_commet.c)
add_executable(HW4_2             CH_code/ch4/HW4_2.c)
add_executable(HW4_3             CH_code/ch4/HW4_3.c)
add_executable(HW4_4             CH_code/ch4/HW4_4.c)
add_executable(HW4_4_comment     CH_code/ch4/HW4_4_comment.c)
add_executable(factorial_int     CH_code/ch4/factorial_int_c.c)

# --------------------
# ch5
# --------------------
add_executable(5_1               CH_code/ch5/5_1.c)
add_executable(5_3               CH_code/ch5/5_3.c)
add_executable(5_4               CH_code/ch5/5_4.c)
add_executable(5_5               CH_code/ch5/5_5.c)

add_executable(HW5_1             CH_code/ch5/HW5_1.c)
add_executable(HW5_2             CH_code/ch5/HW5_2.c)
add_executable(HW5_3             CH_code/ch5/HW5_3.c)
add_executable(HW5_4             CH_code/ch5/HW5_4.c)
add_executable(HW5_5             CH_code/ch5/HW5_5.c)

add_executable(HW_5_2            CH_code/ch5/HW_5_2.c)
add_executable(HW_5_3            CH_code/ch5/HW_5_3.c)
add_executable(HW_5_4            CH_code/ch5/HW_5_4.c)

# --------------------
# ch6
# --------------------
add_executable(6_1               CH_code/ch6/6_1.c)
add_executable(6_7               CH_code/ch6/6_7.c)

# --------------------
# ch7
# --------------------
add_executable(HW7_1             CH_code/ch07/HW7_1.c)
add_executable(HW7_2             CH_code/ch07/HW7_2.c)

# --------------------
# ch11
# --------------------
add_executable(11_7              CH_code/ch11/11_7.c)
add_executable(11_8              CH_code/ch11/11_8.c)
add_executable(11_9              CH_code/ch11/11_9.c)
add_executable(11_10             CH_code/ch11/11_10.c)
add_executable(11_11             CH_code/ch11/11_11.c)
add_executable(11_13             CH_code/ch11/11_13.c)

# --------------------
# ch12
# --------------------
add_executable(12_1              CH_code/ch12/12_1.c)
add_executable(12_2              CH_code/ch12/12_2.c)
add_executable(12_3              CH_code/ch12/12_3.c)
add_executable(12_4              CH_code/ch12/12_4.c)
add_executable(12_5              CH_code/ch12/12_5.c)
add_executable(12_6              CH_code/ch12/12_6.c)
add_executable(12_6_1            CH_code/ch12/12_6_1.c)
add_executable(12_7              CH_code/ch12/12_7.c)
add_executable(12_8              CH_code/ch12/12_8.c)
add_executable(12_9              CH_code/ch12/12_9.c)
add_executable(12_10             CH_code/ch12/12_10.c)
add_executable(12_11             CH_code/ch12/12_11.c)

add_executable(CH_code_ch13_13_1 CH_code/ch13/13_1.c)
add_executable(CH_code_ch13_13_2 CH_code/ch13/13_2.c)
add_executable(CH_code_ch13_13_4 CH_code/ch13/13_4.c)
add_executable(CH_code_ch13_13_5 CH_code/ch13/13_5.c)
add_executable(CH_code_ch13_13_6 CH_code/ch13/13_6.c)
add_executable(CH_code_ch13_13_7 CH_code/ch13/13_7.c)
add_executable(CH_code_ch13_13_8 CH_code/ch13/13_8.c)
add_executable(CH_code_ch13_13_9 CH_code/ch13/13_9.c)
add_executable(CH_code_ch13_13_10 CH_code/ch13/13_10.c)
add_executable(CH_code_ch13_13_11 CH_code/ch13/13_11.c)
add_executable(CH_code_ch13_13_12 CH_code/ch13/13_12.c)
add_executable(CH_code_ch14_14_1 CH_code/ch14/14_1.c)
add_executable(CH_code_ch14_14_2 CH_code/ch14/14_2.c)
add_executable(CH_code_ch14_14_3 CH_code/ch14/14_3.c)
add_executable(CH_code_ch14_14_4 CH_code/ch14/14_4.c)
add_executable(CH_code_ch14_14_5 CH_code/ch14/14_5.c)
add_executable(CH_code_ch14_14_6 CH_code/ch14/14_6.c)
add_executable(CH_code_ch14_14_7 CH_code/ch14/14_7.c)
add_executable(CH_code_ch14_14_8 CH_code/ch14/14_8.c)
add_executable(CH_code_ch14_14_9 CH_code/ch14/14_9.c)
add_executable(CH_code_ch14_14_10 CH_code/ch14/14_10.c)