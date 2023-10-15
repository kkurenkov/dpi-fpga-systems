TOOL        = xrun
TOOL_OPTS   += -sv_lib dpi.so
TOOL_OPTS   += -64
TOOL_OPTS   += -uvmhome CDNS-1.2 # for UVM!
SOURCE_LIST += ./tb_top.sv

#######################################################

all: run

run: compile
	${TOOL} ${TOOL_OPTS} ${SOURCE_LIST}

compile:
	gcc 3.c -fPIC -shared -o dpi.so

clean:
	rm -rf *.so xcelium.d xrun.history xrun.log .bpad