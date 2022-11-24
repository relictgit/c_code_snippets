target         :=  password_gen
objs           :=  generator.o main.o 
CC             :=  gcc
WFLAGS         := -Wall -Wextra -Wdouble-promotion -Wpedantic -Wshadow -Wcast-align -Wunused -Wpedantic -Wconversion -Wsign-conversion -Wfloat-conversion -Wundef -Wformat=2 -Wformat-truncation -Werror=vla -Werror=format-security -Werror=implicit-function-declaration -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference
OFLAG          := -O2
DEBUGFLAG      := -O -g3 -grecord-gcc-switches
FFLAGS         := -D_FORTIFY_SOURCE=2 -fasynchronous-unwind-tables -fexceptions -pie -fpie -fpic -shared -fstack-usage -fstack-clash-protection -fstack-protector-all -fstack-protector-strong -fcf-protection -pipe
CFLAGS         := $(WFLAGS) $(OFLAG)

all: $(target)

deps           :=  $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

password_gen: $(objs)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)
