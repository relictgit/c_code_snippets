target	:=	bin
objs	:=	main.o

CC		:=	gcc
CCFLAGS	:= -Wall -Werror

all: $(target)

@# now comes the dependencie tracing
@# with it the program will be recompiled after there have
@# been some changes on a .h file
deps	:=	$(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

bin: $(objs)
	$(CC) $(CCFLAGS) $^ -o $@
	@# $@: replaced by name of target
	@# $^: replaced by name of all prerequisites

@# this section is a pattern rule, which combine similar rules into one
@# it generalise a rule to files with similar names
%.o: %.c
	$(CC) $(CCFLAGS) -c $< $(DEPFLAGS)
	@# $<: replaced by name of first prerequisite
	@# the @ before the # prevents the comment from beeing printed out to the screen

clean:
	rm -f $(target) $(objs) $(deps)
