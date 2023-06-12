target := bin
objs :=  main.o
logfiles := ERROR_LOG.out update_system_log.out

CC := gcc
CFLAGS := -Wall -Werror

all: $(target)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

bin: $(objs)
        $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
        $(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
        rm -f $(target) $(objs) $(logfiles) $(deps)
