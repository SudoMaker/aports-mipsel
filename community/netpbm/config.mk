DEFAULT_TARGET = nonmerge
NETPBMLIBTYPE = unixshared
NETPBMLIBSUFFIX = so
STATICLIB_TOO = Y
LDRELOC = ld --reloc
LINKER_CAN_DO_EXPLICIT_LIBRARY = Y
LINKERISCOMPILER = Y
CFLAGS_SHLIB += -fPIC
TIFFLIB = -ltiff
JPEGLIB = -ljpeg
PNGLIB = -lpng
ZLIB = -lz
X11LIB = -lX11
NETPBM_DOCURL = https://netpbm.sourceforge.net/doc/