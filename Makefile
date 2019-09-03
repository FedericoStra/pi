CFLAGS += -Wall -Wpedantic -O2
LDFLAGS += -lm
BINARIES = pi-agm pi-serial pi-parallel

.PHONY: all clean

all: $(BINARIES)

pi-parallel: CFLAGS += -fopenmp

pi-agm: LDFLAGS +=  -lmpfr -lgmp

clean:
	$(RM) $(BINARIES)
