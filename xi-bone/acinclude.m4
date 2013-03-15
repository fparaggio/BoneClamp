AC_DEFUN([AC_CHECK_QT],
[
AC_REQUIRE([AC_PROG_CXX])
AC_REQUIRE([AC_PATH_X])

AC_MSG_CHECKING([QTDIR])
AC_ARG_WITH([qtdir], [  --with-qtdir=DIR        Qt installation directory [default=$QTDIR]], QTDIR=$withval)
# Check that QTDIR is defined or that --with-qtdir given
if test x"$QTDIR" = x ; then
    QT_SEARCH="/usr/lib/qt31 /usr/local/qt31 /usr/lib/qt3 /usr/local/qt3 /usr/lib/qt2 /usr/local/qt2 /usr/lib/qt /usr/local/qt /usr/share/qt3"
    for i in $QT_SEARCH; do
        if test -f $i/include/qglobal.h -a x$QTDIR = x; then QTDIR=$i; fi
    done
fi
if test x"$QTDIR" = x ; then
    AC_MSG_ERROR([*** QTDIR must be defined, or --with-qtdir option given])
fi
AC_MSG_RESULT([$QTDIR])

# Change backslashes in QTDIR to forward slashes to prevent escaping
# problems later on in the build process, mainly for Cygwin build
# environment using MSVC as the compiler
# TODO: Use sed instead of perl
QTDIR=`echo $QTDIR | perl -p -e 's/\\\\/\\//g'`

# Figure out which version of Qt we are using
AC_MSG_CHECKING([Qt version])
QT_VER=`grep 'define.*QT_VERSION_STR\W' $QTDIR/include/qglobal.h | perl -p -e 's/\D//g'`
case "${QT_VER}" in
    2*)
        AC_MSG_ERROR([need QT 3 or better])
    ;;
    3*)
        QT_MAJOR="3"
    ;;
    *)
        AC_MSG_ERROR([*** Don't know how to handle this Qt major version])
    ;;
esac
AC_MSG_RESULT([$QT_VER ($QT_MAJOR)])

# Check that moc is in path
AC_CHECK_PROG(MOC, moc, moc)
if test x$MOC = x ; then
        AC_MSG_ERROR([*** moc must be in path])
fi

# uic is the Qt user interface compiler
AC_CHECK_PROG(UIC, uic, uic)
if test x$UIC = x ; then
        AC_MSG_ERROR([*** uic must be in path])
fi

# Calculate Qt include path
QT_INCLUDES="-I$QTDIR/include"


QT_IS_STATIC=`ls $QTDIR/lib/*.a 2> /dev/null`
if test "x$QT_IS_STATIC" = x; then
  QT_IS_STATIC="no"
else
  QT_IS_STATIC="yes"
fi

if test "x`ls $QTDIR/lib/libqt-mt.* 2> /dev/null`" != x ; then
  QT_LIB="-lqt-mt"
  QT_IS_MT="yes"
elif test "x`ls $QTDIR/lib/libqt.* 2> /dev/null`" != x ; then
  QT_LIB="-lqt"
  QT_IS_MT="no"
fi

AC_MSG_CHECKING([if Qt is static])
AC_MSG_RESULT([$QT_IS_STATIC])
AC_MSG_CHECKING([if Qt is multithreaded])
AC_MSG_RESULT([$QT_IS_MT])

QT_LIBS="$QT_LIB"
if test x"$QT_IS_STATIC" = "xyes" && test x"$QT_IS_EMBEDDED" = "xno"; then
  QT_LIBS="$QT_LIBS -L$x_libraries -lXext -lX11 -lm -lSM -lICE -ldl -ljpeg"
fi

if test x"$QT_IS_MT" = "xyes" ; then
        QT_DEFS="$QT_DEFS -D_REENTRANT -DQT_THREAD_SUPPORT"
fi

QT_LIBS="-L$QTDIR/lib $QT_LIBS"

if test x$QT_IS_STATIC = xyes ; then
    OLDLIBS="$LIBS"
    LIBS="$QT_LIBS"
    AC_CHECK_LIB(Xft, XftFontOpen, QT_LIBS="$QT_LIBS -lXft")
    LIBS="$LIBS"
fi

AC_MSG_CHECKING(QT_INCLUDES)
AC_MSG_RESULT($QT_INCLUDES)
AC_MSG_CHECKING(QT_DEFS)
AC_MSG_RESULT($QT_DEFS)
AC_MSG_CHECKING(QT_LIBS)
AC_MSG_RESULT($QT_LIBS)

AC_SUBST(QT_INCLUDES)
AC_SUBST(QT_DEFS)
AC_SUBST(QT_LIBS)

])
