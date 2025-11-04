CC := gcc
LD := gcc # Use the gcc toolchain
PYTHON := python3
GCCOPTS := -O3 -fno-math-errno -ffinite-math-only -frounding-math
CFLAGS := -std=c99 -Wall -Wextra --pedantic $(GCCOPTS)
# NOTE: this must not be := defined, as it has to reeval CFLAGS for SIZE def
CFLAGS_SIMD = $(CFLAGS) -mavx512f \
# Nicholas Robinson
# HDF5 custom include and link paths
# HDF5 include and library paths
HDF5_INC    := -I/usr/include/hdf5/serial
HDF5_LIB    := -L/usr/lib/x86_64-linux-gnu/hdf5/serial

# Static HDF5 libraries
HDF5_STATIC := \
    /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl.a \
    /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.a

# Additional dependencies required for static HDF5
HDF5_DEPS   := -lcrypto -lcurl -lpthread -lsz -lz -ldl -lm
							 -march=native -D__HYPERION_USE_SIND
CFLAGS      := -std=c99 -Wall -Wextra --pedantic $(GCCOPTS) $(HDF5_INC)
LD_LIBS     := $(HDF5_STATIC) $(HDF5_DEPS) -lc -L$(OBJECT_DIR) -l:libhyburn.a -lm
LD_FLAGS    := -static
