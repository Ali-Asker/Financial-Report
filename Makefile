CC = gcc
CFLAGS = -ansi -pedantic -Wall -Wextra
TARGET = totals
SRCS = soggyCoaster.c utility.c fileReader.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
