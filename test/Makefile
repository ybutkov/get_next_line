NAME = test
CC = cc

CFLAGS = -Wall -Wextra -Werror -g -ggdb3
VALGRIND_FLAGS = --leak-check=yes
VALGRIND_FLAGS_FULL = --leak-check=full --show-leak-kinds=all
#CFLAGS = -g -ggdb3
#C_FILES = test.c 
T_FILE = test.c 
SRC_DIRS = .. .
TEST_FILES	= ../get_next_line.c ../get_next_line_utils.c $(T_FILE)
BONUS_FILES	= ../get_next_line_bonus.c ../get_next_line_utils_bonus.c test.c

BI_FILES = $(TEST_FILES:.c=.o)
BI_BONUS_FILES = $(BONUS_FILES:.c=.o)

d	: debug

v	: debug
	valgrind $(VALGRIND_FLAGS_FULL) ./a.out

debug : $(BI_BONUS_FILES)
	$(CC) $(CFLAGS) -I../ $(BI_BONUS_FILES) 

all : lib $(TEST_FILES)

${NAME} : $(TEST_FILES)

%.o : %.c
	$(CC) $(CFLAGS) -I../ -I.. -c $< -o $@

f :
	rm -f a.out ${BI_FILES} ${BI_BONUS_FILES}

