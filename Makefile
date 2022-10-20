CC	:= gcc
CLFAGS	:= -O0 -g -Wall
TARGET	:= program
HDRS	:= -I.
SRCS	:= $(wildcard *.c)
OBJS	:= $(patsubst %.c,%.o,$(SRCS))

.PHONY = all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) \
	$(TARGET) \
	$(OBJS)
