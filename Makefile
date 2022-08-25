CC=gcc
TARGET=calendar

all:
	$(CC) calendar.c utils/string_utils.c datetime/date.c terminal/print.c -o $(TARGET)

clean:
	rm $(TARGET)