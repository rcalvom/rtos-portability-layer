cc := gcc

RM := rm -rf

SOURCES := lib/log.c portability_layer.c

OBJS := $(SOURCES:.c=.o)

main: $(OBJS)
	$(CC) -shared -g -o portability_layer.so $^

%.o: %.c
	$(CC) -c -g -Wall -Werror -fPIC -Ilib $< -o $@

.PHONY: clean
clean:
	$(RM) *.o *.so
	$(RM) lib/*.o lib/*.so