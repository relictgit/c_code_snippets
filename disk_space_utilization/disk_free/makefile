target         :=  disk_free.bin
objs           :=  $(wildcard *.c)
objs           :=  $(patsubst %.c,%.o,$(objs))

CC             :=  gcc
CFLAGS         :=  -Wall -Werror -pedantic -std=c11

all: $(target)

deps           :=  $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

disk_free.bin: $(objs)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)
