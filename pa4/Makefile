#
# Makefile for CSE 30 -- PA4
# You should not need to change anything in this file.
#

HEADERS		= pa4.h pa4Strings.h test.h

C_SRCS		= pa4.c buildFileInfoTable.c printFileInfoTable.c \
		  modTimeCompare.c nameCompareRev.c pa4Globals.c \
		  printOwnerName.c printPermissions.c parseArgs.c

ASM_SRCS	= printGroupName.s modTimeCompareRev.s \
		  nameCompare.s

C_OBJS		= $(C_SRCS:.c=.o)
ASM_OBJS	= $(ASM_SRCS:.s=.o)

TEST_BINS	= testparseArgs testnameCompare testmodTimeCompareRev \
		  testbuildFileInfoTable

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= myls
TESTERS 	= testnameCompare


GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -W -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -W -Wall


#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}

clean:
	@echo "Cleaning up project directory ..."
	rm -f *.o a.out *.ln core $(EXE) ${TEST_BINS}
	@echo ""
	@echo "Clean."

# --- Test for testparseArgs ---
testparseArgs: ${HEADERS} parseArgs.o testparseArgs.o
	@echo "Compiling testparseArgs.c"
	gcc -g -o testparseArgs testparseArgs.o parseArgs.o
	@echo "Done."

# --- Test for testnameCompare ---
testnameCompare: ${HEADERS} nameCompare.o testnameCompare.o
	@echo "Compiling testnameCompare.c"
	gcc -g -o testnameCompare testnameCompare.o nameCompare.o
	@echo "Done."

# --- Test for testmodTimeCompareRev ---
testmodTimeCompareRev: ${HEADERS} modTimeCompareRev.o testmodTimeCompareRev.o
	@echo "Compiling testmodTimeCompareRev.c"
	gcc -g -o testmodTimeCompareRev testmodTimeCompareRev.o \
	modTimeCompareRev.o pa4Globals.c
	@echo "Done."

# --- Test for testbuildFileInfoTable ---
testbuildFileInfoTable: ${HEADERS} buildFileInfoTable.o testbuildFileInfoTable.o
	@echo "Compiling testbuildFileInfoTable.c"
	gcc -g -o testbuildFileInfoTable testbuildFileInfoTable.o \
	buildFileInfoTable.o
	@echo "Done."

new:
	make --no-print-directory clean
	make --no-print-directory

