target         :=  bin
objs           :=  $(wildcard *.c)
objs           :=  $(patsubst %.c,%.o,$(objs))

CC             :=  gcc
CFLAGS         :=  -Wall -Werror -pedantic -std=c11
LDFLAGS         = # math: -lm | ncurses: -lncurses -ltinfo -lmenu

all: $(target)

deps           :=  $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

bin: $(objs)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)
