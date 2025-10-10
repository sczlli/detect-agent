CC = gcc
CFLAGS = -Wall -g -Isrc/core
VPATH = src/core

TARGET = agent_test
SRCS = main.c logger.c config.c
OBJS = $(SRCS:.c=.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)\


rm -f $(OBJS) $(TARGET) src/core/*.o
