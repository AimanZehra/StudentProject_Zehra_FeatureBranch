CC = gcc
OBJS = main.o Integrate.o Forces.o Statistics.o ExceptionHandling.o Initialization.o ReadParameters.o WriteSystem.o ReadSystem.o
HDRS =        Integrate.h Forces.h Statistics.h Defs.h Particles.h ExceptionHandling.h Parameters.h Initialization.h ReadParameters.h WriteSystem.h ReadSystem.h
PROG = PMC-Advanced
CFLAGS = 
LDFLAGS = -lm
SRC = main.c Integrate.c Forces.c Statistics.c ExceptionHandling.c Initialization.c ReadParameters.c WriteSystem.c ReadSystem.c

$(PROG): $(OBJS)
	@$(CC) -o $(PROG) $(OBJS) $(LDFLAGS) $(CFLAGS)
	@echo ----------------------------------------
	@echo   "Binary '"$(PROG)"' created"
	@echo
clean:
	@rm -fr $(PROG) $(OBJS)

main.o: Defs.h Particles.h Forces.h Statistics.h Integrate.h ExceptionHandling.h Parameters.h Initialization.h ReadParameters.h WriteSystem.h ReadSystem.h
