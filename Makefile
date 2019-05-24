CC          = g++
LD          = g++ 
CFLAG       = -Wall
PROG_NAME   = Test_Manager.x

BIN_DIR	= .
SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./object

CFLAGS   +=  -Wall -Werror
CPPFLAGS += -std=c++11

INCLUDE += -I $(INC_DIR)

OBJECT_LIST = $(OBJ_DIR)/main.o \
		$(OBJ_DIR)/main_menu.o \
		$(OBJ_DIR)/add_new_program.o \
		$(OBJ_DIR)/edit_program.o \
		$(OBJ_DIR)/Program_Settings.o \
		$(OBJ_DIR)/delete_program.o \

.PHONY: all clean $(PROG_NAME) compile

all: $(PROG_NAME)

$(PROG_NAME): $(OBJECT_LIST)
	$(CC) $(OBJECT_LIST) -o $(PROG_NAME) $(CPPFLAGS) 


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(BIN_DIR)/$(PROG_NAME) $(BUILD_DIR)/*.o

print-%  : ; @echo $* = $($*)