AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

bin_PROGRAMS = smixer

smixer_SOURCES = \
	smixer.c \
	smixer_neon.c \
	testdata.c \
	main.c

smixer_LDADD = \
	-lrt -lpthread

# C compiler options
smixer_CFLAGS = \
	-g -O2 \
	-I$(top_srcdir)/include \
	-D_GNU_SOURCE

# Linker options
smixer_LDFLAGS = 
