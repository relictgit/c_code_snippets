#!/bin/bash

makefilec_dynamic () {
	printf '%s\n%s\n%s\n%s\n\n%s\n%s\n%s\n\n%s\n\n%s\n%s\n%s\n\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n%s\n\n%s\n' \
        "target         :=  bin" \
        "srcdirs        :=  \$(shell find . -type d)" \
        "srcfiles       :=  \$(foreach dir,\$(srcdirs),\$(wildcard \$(dir)/*.c))" \
        "objs           :=  \$(patsubst %.c,%.o,\$(srcfiles))" \
        "CC             :=  gcc" \
        "CFLAGS         :=  -Wall -Werror -pedantic -std=c11" \
        "LDFLAGS        :=  # math: -lm | ncurses: -lncurses -ltinfo -lmenu" \
        "all: \$(target)" \
        "deps           :=  \$(patsubst %.o,%.d,\$(objs))" \
        "-include \$(deps)" \
        "DEPFLAGS = -MMD -MF \$(@:.o=.d)" \
        ".PHONY: all clean" \
        "\$(target): \$(objs)" \
        "	\$(CC) \$(CFLAGS) \$(LDFLAGS) -o \$@ \$^" \
        "%.o: %.c" \
        "	\$(CC) \$(CFLAGS) -c \$< \$(DEPFLAGS) -o \$@" \
        "clean:" \
        "	rm -f \$(target) \$(objs) \$(deps)" \
        "define make-goal" \
        "\$1: \$2" \
        "endef" \
        "\$(foreach obj,\$(objs),\$(eval \$(call make-goal,\$(obj),\$(filter %/\$(basename \$(notdir \$(obj))).c,\$(srcfiles)))))" \
        > makefile
}
