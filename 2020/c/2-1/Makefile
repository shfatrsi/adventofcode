CC      = gcc
PROF    = -O -g
C_FLAGS = -Wall -g3 -ggdb -std=c11 $(PROF)
L_FLAGS = $(PROF) -lm
P_FLAG  = `perl -MExtUtils::Embed -e ccopts -e ldopts`
OBJDIR  = ofiles
# To add a new path use : between directory names
#vpath %.c

O_FILES := $(sort $(patsubst %.c,%.o,$(wildcard *.c)) \
			$(notdir $(patsubst %.c,%.o,$(wildcard */*.c))))

all: prepdir main
	@echo Make All Compile

prepdir:
	mkdir -p $(OBJDIR)

# The P_FLAG compilation should probably only be for the perl file
#  since not every file needs it but it's working for now
main: $(O_FILES)
	rm -f main
	$(CC) $(L_FLAGS) -o main $(addprefix $(OBJDIR)/,$(O_FILES)) $(P_FLAG)

%.o: %.c
	$(CC) -c $(C_FLAGS) $< -o $(OBJDIR)/$(notdir $(basename $<)).o $(P_FLAG)

tar:
	tar czhf ../backup/main.tgz *.* Makefile

clean:
	rm -rf $(OBJDIR)/*.o
