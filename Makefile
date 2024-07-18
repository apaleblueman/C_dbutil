TARGET = bin/cdb
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))


default: $(TARGET)

run : clean $(TARGET)
	./$(TARGET)

$(TARGET):$(OBJ)
	gcc -o $@ $?

obj/%.o : src/%.c
	gcc -c $< -o $@ -Iinclude

clean:
	rm -f obj/*.o
	rm -f bin/*
	rm -f *.txt
	rm -f *.db
