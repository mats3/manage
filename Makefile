application_name = out

compiler = gcc

lib_typ = .a

cflags = $(compiler) -g -Wall -fpic

sub_dirs = $(filter-out src/tests,$(filter-out $(wildcard src/*.c),$(wildcard src/*)))
objdirs = $(patsubst src/%,obj/%,$(sub_dirs))

sublibs_path = $(patsubst obj/%,bin/lib%$(lib_typ),$(objdirs))
sublibs = $(addprefix -l,$(notdir $(sub_dirs)))

sub_srcs = $(wildcard src/*/*.c)
sub_objs = $(patsubst src/%.c,obj/%.o,$(sub_srcs))

srcs = $(wildcard src/*.c)
objs = $(patsubst src/%.c,obj/%.o,$(srcs))

bin = bin/$(application_name)

all:

link: $(bin)

ifeq ($(OS),Windows_NT)
all: gen_subdirs compile link

$(bin): $(objs)
	$(cflags) $(objs) $(sub_objs) -o $@
else
all: gen_subdirs compile libs link

$(bin): $(objs)
	$(cflags) $(objs) -Lbin $(sublibs) -o $@
endif


compile: $(objs) $(sub_objs)

obj/%.o: src/%.c
	$(cflags) -c $< -o $@

libs: $(sublibs_path)

bin/lib%$(lib_typ): obj/%/*.o
	$(cflags) -shared $^ -o $@

run: all
	./$(bin)

clean:
	rm obj -r
	rm bin/*

init:
	mkdir -p src/tests
	mkdir bin

gen_subdirs:
	@for i in $(objdirs) ; do \
		if [ -d "$(i)" ] ; then \
			echo all done; \
		else \
			mkdir -p $(foreach i,$(objdirs),$(i)); \
		fi \
	done
	@if [ -d "./obj" ] ; then \
		echo all done; \
	else \
		mkdir -p obj; \
	fi
