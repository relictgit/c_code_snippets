target := bin
objs :=  main.o

CC := gcc

# ncurses necessary linker options "-lncurses -ltinfo"
CFLAGS := -Wall -Werror -lncurses -ltinfo

all: $(target)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

bin: $(objs)
        $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
       $(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
        rm -f $(target) $(objs) $(deps)
