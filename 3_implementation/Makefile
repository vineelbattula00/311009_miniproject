# Name of the project
PROJ_NAME = grocery billing system
TEST_PROJ_NAME = Test_$(PROJ_NAME)

# Output directory
BUILD_DIR = build

# All include folders with header files
INC = -Iinc\
-Iunity

# All source code files
SRC = Main.c\
src/1.c\
src/2.c\
src/3.c\
src/4.c\
src/5.c\
src/6.c\
src/test.c\


# All test source files
TEST_SRC = src/src/1.c\
src/2.c\
src/3.c\
src/4.c\
src/5.c\
src/6.c\
src/test.c\
src/unity.c\
# Document files
DOCUMENTATION_OUTPUT = documentation/html

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
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

# Run the target even if the matching name exists
.PHONY : all test coverage run clean doc

# Project Output name
all:$(BUILD_DIR)
	gcc $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

# Call `make run` to run the application
run: all
	./$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

coverage:${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(SRC)

# Document the code using Doxygen
doc:
	make  -C ./documentation

# Remove all the built files, invoke by `make clean`
clean:
	$(RM) $(call FixPath,$(BUILD_DIR)*.$(EXEC))
	make clean ./documentation
	rmdir $(BUILD_DIR) $(DOCUMENTATION_OUTPUT)

# Create new build folder if not present
$(BUILD_DIR):
	mkdir $(BUILD_DIR)
