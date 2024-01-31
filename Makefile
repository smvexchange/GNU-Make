CC = gcc
CFLAGS = -Wall -g -ansi -pedantic
DEFAULT_GOAL = run

SRCMODULES = mod1.c mod2.c mod3.c
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

build: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o app

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

run: build
	./app

clean:
	del *.o app.* deps.mk