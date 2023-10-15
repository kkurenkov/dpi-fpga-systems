TOOL        = xrun
TOOL_OPTS   += -sv_lib dpi.so
TOOL_OPTS   += -64
SOURCE_LIST += ./tb_top.sv

#######################################################

all: run

run: compile
	${TOOL} $(TOOL_OPTS) ${SOURCE_LIST}

compile:
	gcc -fPIC -shared c_code.c -I/usr/include/python3.10/ /usr/lib/x86_64-linux-gnu/libpython3.10.so.1 -o dpi.so

clean:
	rm -rf *.so c_code.o __pycache__ xcelium.d xrun.history xrun.log .bpad