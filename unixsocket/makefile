ROOT := $(shell pwd)
DIR  := unixsocket

ifeq ($(PROJ), unixsocket)
	DIR := unixsocket
endif
OBJ_DIR  := $(ROOT)/obj
DEP_DIR  := $(ROOT)/dep
SRC_FILE := $(wildcard $(ROOT)/$(DIR)/*.cpp $(ROOT)/$(DIR)/*.c)
OBJ_FILE := $(patsubst  $(ROOT)/$(DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILE)) $(patsubst  $(ROOT)/$(DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILE))

TARGET := a.out

CPP := g++
CC  := gcc
CFAGS := -g -I$(ROOT)/DIR

$(TARGET) : $(OBJ_FILE)
	@$(CPP) $< -o $@

$(OBJ_DIR)/%.o : $(ROOT)/$(DIR)/%.cpp | $(DEP_DIR) $(OBJ_DIR)
	@$(CPP) -MM $< -MT $(DEP_DIR)/$*.d -MT $(OBJ_DIR)/$*.o -o $(DEP_DIR)/$*.d
	@$(CPP) -c $< -o $@

$(OBJ_DIR)/%.o : $(ROOT)/$(DIR)/%.c
	@$(CC) -MM $< -MT $(DEP_DIR)/$*.d -MT $(OBJ_DIR)/$*.o -o $(DEP_DIR)/$*.d
	@$(CC) -c $< -o $@

$(DEP_DIR) $(OBJ_DIR) : 
	@mkdir -p $@

clean:
	@rm -rf $(DEP_DIR) $(OBJ_DIR)

ifneq (clean, $(MAKECMDGOALS))
include $(wildcard $(DEP_DIR)/*.d)
endif