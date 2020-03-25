# Makefile for libcheck_example
TARGETS := \
	program \
	test \
	test_program



.PHONY: all clean check

all: $(TARGETS)

clean:
	@rm -fv $(TARGETS)
	@rm -rfv *.dSYM

check: $(TARGETS)
	@echo "\n--- test ---"
	@./test
	@echo "\n--- test_program ---"
	@./test_program



# CFLAGS common to all builds
CFLAGS += \
	-O3 \
	-I./libmoney \
	-Wall \
	-Wextra

# normal program build
program: program.c

# test build linking against libcheck
test: CFLAGS += -lcheck
test: test.c

# test-version of 'program' using address sanitizer
test_program: CFLAGS += -O0 -g -fsanitize=address -fno-omit-frame-pointer \
			-Wno-macro-redefined  # silence build complaint
test_program: program.c



# common build definition for all targets (they all depend on everything in libmoney)
$(TARGETS) : $(wildcard libmoney/*.c)
	$(CC) -o $@ $(CFLAGS) $^
