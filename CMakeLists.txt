cmake_minimum_required(VERSION 3.30)
project(C_language C)

set(CMAKE_C_STANDARD 11)

# 메인 타겟
add_executable(C_language main.c)

# --------------------
# ch2
# --------------------
add_executable(2_3 ch2/2_3.c)
add_executable(2_4 ch2/2_4.c)
add_executable(2_5 ch2/2_5.c)

# --------------------
# ch3
# --------------------
add_executable(3_1 ch3/3_1.c)
add_executable(3_2 ch3/3_2.c)
add_executable(3_3 ch3/3_3.c)
add_executable(3_4 ch3/3_4.c)
add_executable(3_5 ch3/3_5.c)
add_executable(3_6 ch3/3_6.c)
add_executable(3_7 ch3/3_7.c)
add_executable(3_8 ch3/3_8.c)
add_executable(3_9 ch3/3_9.c)

# --------------------
# ch4
# --------------------
add_executable(program4_1 ch4/program4_1.c)
add_executable(program4_2 ch4/program4_2.c)
add_executable(program4_3 ch4/program4_3.c)
add_executable(program4_4 ch4/program4_4.c)
add_executable(program4_5 ch4/program4_5.c)
add_executable(program4_6 ch4/program4_6.c)
add_executable(program4_7 ch4/program4_7.c)
add_executable(program4_8 ch4/program4_8.c)
add_executable(program4_9 ch4/program4_9.c)

add_executable(HW4_1 ch4/HW4_1.c)
add_executable(HW4_1_comment ch4/HW4_1_commet.c)
add_executable(HW4_2 ch4/HW4_2.c)
add_executable(HW4_3 ch4/HW4_3.c)
add_executable(HW4_4 ch4/HW4_4.c)
add_executable(HW4_4_comment ch4/HW4_4_comment.c)
add_executable(factorial_int_c ch4/factorial_int_c.c)  # 수정된 파일 이름 사용 (구 int factorial(int n).c)

# --------------------
# ch5
# --------------------
add_executable(5_1 ch5/5_1.c)
add_executable(5_3 ch5/5_3.c)
add_executable(5_4 ch5/5_4.c)
add_executable(5_5 ch5/5_5.c)

add_executable(HW5_1 ch5/HW5_1.c)
add_executable(HW5_2 ch5/HW5_2.c)
add_executable(HW5_3 ch5/HW5_3.c)
add_executable(HW5_4 ch5/HW5_4.c)
add_executable(HW5_5 ch5/HW5_5.c)

add_executable(HW_5_2 ch5/HW_5_2.c)
add_executable(HW_5_3 ch5/HW_5_3.c)
add_executable(HW_5_4 ch5/HW_5_4.c)

# --------------------
# ch6
# --------------------
add_executable(6_1 ch6/6_1.c)
add_executable(6_7 ch6/6_7.c)

add_executable(ch4_factorial_int_c ch4/factorial_int_c.c)