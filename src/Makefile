# Compiler
CXX = g++


# Source files
SRCS = main.cpp InputArr.cpp BloomPart.cpp AddURL.cpp CheckURL.cpp BytesArray.cpp URLlist.cpp HashFunction.cpp Node.cpp

# Executable name
TARGET = myprogram

# Default target
all: $(TARGET)

# Compile and link source files into executable
$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $(TARGET)

# Clean up executable
clean:
	rm -f $(TARGET)
