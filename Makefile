#the compiler: gcc for C program, defined as g++ for C++
CC = g++ -std=c++11

#compiler flags
#-g adds debugging information to the executable file
#-Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall

#the build target exectuable
TARGET = test_Polynom
POLYNOM = Polynom
TEST_POLYNOM = test_polynom

all: $(TARGET)

$(TARGET): $(POLYNOM).o $(TEST_POLYNOM).o
	$(CC) $(CFLAGS) -o $(TARGET) $(POLYNOM).o $(TEST_POLYNOM).cpp

$(POLYNOM).o: $(POLYNOM).cpp $(POLYNOM).h
	$(CC) $(CFLAGS) -c $(POLYNOM).cpp

$(TEST_POLYNOM).o: $(POLYNOM).cpp $(POLYNOM).h
	$(CC) $(CFLAGS) -c $(TEST_POLYNOM).cpp

clean:
	$(RM) -f $(TARGET) $(POLYNOM).o $(TEST_POLYNOM).o
