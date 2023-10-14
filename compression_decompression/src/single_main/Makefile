target := bin
objs :=  main.o 

CC := gcc
CFLAGS := -Wall -Werror
CDEBUG := -O0 -g

all: $(target)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

bin: $(objs)
	$(CC) $(CDEBUG) -o $@ $^

%.o: %.c
	$(CC) $(CDEBUG) -c $< $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)
