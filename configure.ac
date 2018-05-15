AC_INIT(wordcount, 1.0)
AC_LANG(C)
AC_PROG_CC
AC_CANONICAL_HOST

AC_ARG_ENABLE(dependency-tracking, []], [], [])

AC_ARG_WITH(zlib, [AS_HELP_STRING([--with-zlib], [Include zlib support (default=auto)])], [], [with_zlib=auto])
case "$with_zlib" in
  no|yes|auto) ;;
  *)
    echo "Invalid option $with_zlib"
    exit 1
esac

if test "$with_zlib" != no
then
    AC_SEARCH_LIBS(deflate, z, [x=0], [x=1])

    if test $x == 0
    then
        AC_DEFINE(HAVE_LIBZ)
    else
        if test "$with_zlib" = "yes"
        then
            AC_MSG_ERROR(cannot find zlib library)
        fi
    fi
fi

AC_SUBST(host_os)
AC_CONFIG_HEADERS(config.h)
AC_OUTPUT(Makefile)
