# see https://github.com/gwu-cs-os/evening_os_hour/blob/master/f19/10.2-makefiles/03_featureful_makefile/Makefile

BINARY=bin
CODEDIRS=. ./src # source files
INCDIRS=. ./header # can be list of headers

CC=gcc
OPT_DEBUG=-O0
OPT_RELEASE=-O2
# generate files that encode make rules for the .h dependencies
DEPFLAGS=-MP -MD
# automatically add the -I onto each include directory
CFLAGS_DEBUG=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT_DEBUG) $(DEPFLAGS)
CFLAGS_RELEASE=-Wall -Wextra $(foreach D,$(INCDIRS),-I$(D)) $(OPT_RELEASE) $(DEPFLAGS)
LDFLAGS= # math: -lm | ncurses: -lncurses -ltinfo -lmenu

# for-style iteration (foreach) and regular expression completions (wildcard)
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
# regular expression replacement
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

# only want the .c file dependency here, thus $< instead of $^.
%.o:%.c
	$(CC) $(CFLAGS_RELEASE) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

# shell commands are a set of keystrokes away
distribute: clean
	tar -cJvf dist.tar.xz *

# @ silences the printing of the command
# $(info ...) prints output

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

# include the dependencies
-include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean distribute diff
