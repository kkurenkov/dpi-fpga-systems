TOOL        = xrun
TOOL_OPTS   += -sv_lib dpi.so
TOOL_OPTS   += -64
SOURCE_LIST += ./tb_top.sv

#######################################################

all: run

run: compile
	${TOOL} $(TOOL_OPTS) $(UVM_OPTS) $(RTL_OPTS) ${ENGUI} ${SOURCE_LIST}

compile:
	gcc 4.c -fPIC -shared -o dpi.so -I${CDS_INST_DIR}/tools.lnx86/include

clean:
	rm -rf *.so xcelium.d xrun.history xrun.log .bpad