DIR_ROOT := $(shell pwd)
DIR_OBJ  := $(DIR_ROOT)/obj
DIR_DEP  := $(DIR_ROOT)/dep

$(shell mkdir -p $(DIR_OBJ) $(DIR_DEP) >/dev/null)



FILES = main.cpp testtime.cpp
OBJ =  $(patsubst %.cpp, $(DIR_OBJ)/%.o, $(FILES))
Dep =  $(patsubst %.cpp, $(DIR_DEP)/%.d, $(FILES))


TARGETNAME = a.out

$(TARGETNAME) : $(OBJ)
	g++ $(OBJ) -o $@

$(DIR_OBJ)/%.o : %.cpp
	g++ -c $< -o $@

$(DIR_DEP)/%.d : %.cpp
	g++ -MM $< -MT $(DIR_OBJ)/$*.o -MT $(DIR_DEP)/$*.d -o $@

clean:
	@if [ -d $(DIR_DEP) ];\
	then \
		rm -rf $(DIR_DEP); \
	fi

	@if [ -d $(DIR_OBJ) ]; \
	then \
		rm -rf $(DIR_OBJ); \
	fi

	@if [ -f $(TARGETNAME) ]; \
	then \
		rm -rf $(TARGETNAME); \
	fi

.PHONY : clean

include $(Dep)