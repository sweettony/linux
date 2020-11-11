ROOT := $(shell pwd)
OBJ_DIR  := $(ROOT)/obj
DEP_DIR  := $(ROOT)/dep
INC_DIR  := $(ROOT)/inc
SRC_DIR  := $(ROOT)/src

SRC_FILE := $(wildcard  $(SRC_DIR)/*.cpp $(SRC_DIR)/*.c)
OBJ_FILE := $(patsubst  $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILE)) 
OBJ_FILE := $(patsubst  $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(OBJ_FILE))

SERVER := server
CLIENT := client
CLIENT_OBJ_FILE := $(filter-out $(OBJ_DIR)/server.o, $(OBJ_FILE))
SERVER_OBJ_FILE := $(filter-out $(OBJ_DIR)/client.o, $(OBJ_FILE))

CPP := g++
CC  := gcc
CFAGS := -g -I$(INC_DIR)
HI = @$(CPP) $(CFAGS) $^ -o $@

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(CLIENT_OBJ_FILE)
	$(HI)
$(SERVER) : $(SERVER_OBJ_FILE)
	$(HI)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(DEP_DIR) $(OBJ_DIR)
	@$(CPP) $(CFAGS) -MM $< -MT $(DEP_DIR)/$*.d -MT $(OBJ_DIR)/$*.o -o $(DEP_DIR)/$*.d
	@$(CPP) $(CFAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(DEP_DIR) $(OBJ_DIR)
	@$(CC) $(CFAGS) -MM $< -MT $(DEP_DIR)/$*.d -MT $(OBJ_DIR)/$*.o -o $(DEP_DIR)/$*.d
	@$(CC) $(CFAGS) -c $< -o $@

$(DEP_DIR) $(OBJ_DIR) : 
	@mkdir -p $@

clean:
	@rm -rf $(DEP_DIR) $(OBJ_DIR) $(CLIENT) $(SERVER)

ifneq (clean, $(MAKECMDGOALS))
include $(wildcard $(DEP_DIR)/*.d)
endif