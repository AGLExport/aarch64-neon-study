AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

bin_PROGRAMS = smixer smixerauto smixerneon

smixer_SOURCES = \
	smixer.c \
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


smixerauto_SOURCES = \
	smixer.c \
	main.c

smixerauto_LDADD = \
	-lrt -lpthread

# C compiler options
smixerauto_CFLAGS = \
	-g -O3 \
	-I$(top_srcdir)/include \
	-D_GNU_SOURCE

# Linker options
smixerauto_LDFLAGS = 


smixerneon_SOURCES = \
	smixer_neon.c \
	main.c

smixerneon_LDADD = \
	-lrt -lpthread

# C compiler options
smixerneon_CFLAGS = \
	-g -O2 \
	-I$(top_srcdir)/include \
	-D_GNU_SOURCE

# Linker options
smixerneon_LDFLAGS = 

