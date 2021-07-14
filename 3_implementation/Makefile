PROJECT_NAME = grocery billing system

SRC =src/1.c \
src/2.c \
src/3.c \
src/4.c \
src/5.c \
src/6.c \


BUILD = build

#INC=inc
UNI=unity/unity.c

INC	= inc\
-Iunity\

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
TEST_SRC = test/test


PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

INCLUDE_LIBS = -lcunit
