# Compiler and flags
CC = gcc
CFLAGS = -Wall -ansi

# Output executable file
TARGET = Mad_Polar_Bears

# Source files
SRC = main.c header.c

# Object files (automatically generated)
OBJ = $(SRC:.c=.o)

# Default target: build the proogram
all: $(TARGET)

# Link object files from source files
$(TARGET): $(OBJ)
					 $(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c header.h
		 $(CC) $(CFLAGS) -c $< -o $@
  
# Clean up the generated files
clean:
			rm -f $(OBJ) $(TARGET)