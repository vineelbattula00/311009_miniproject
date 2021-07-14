SRC = main.c\
src/1.c\
src/2.c\
src/2.c\
src/3.c\
src/4.c\
src/5.c\
src/6.c

INC = inc

new.out : $(SRC)
	gcc $^ -I$(INC)  -o $@

run : new.out
	.\new.out

clean : 
	rm new.out 
