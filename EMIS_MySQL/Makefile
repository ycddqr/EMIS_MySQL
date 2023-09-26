CC=g++
STD=-std=gnu++11
FLAG=-Wall -Werror
LIB=-lmysqlclient
OBJ=department.o emis.o employee.o main.o manager.o manager_ctrl_impl.o manager_mode_impl.o manager_view_impl.o service_ctrl_impl.o service_mode_impl.o service_view_impl.o tools.o my_sql.o
BIN=EMIS.bin

all:$(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(BIN) && ./$(BIN)

%.o:%.cpp
	$(CC) $(FLAG) $(STD) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BIN) *.h.gch *~
