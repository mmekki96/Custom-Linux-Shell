CC=gcc
CFLAGS=-Iinc
TARGET=build/main
SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c, build/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $^ -o $@
	@echo "[.] main Created successfully: tap 'build/main'"

build/%.o: src/%.c
	@mkdir -p build/
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf build/
	@echo "[.] Project successfully cleaned"