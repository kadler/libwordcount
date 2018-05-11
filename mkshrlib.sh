#!/bin/sh

if [ $# -lt 4 ]
then
  echo "$0 [OS] [shared object] [shared library] [soname]"
  exit 1
fi

OS=$1
SO=$2
LIB=$3
SONAME=$4


case $OS in
aix*)
    (
        echo "#! $LIB.$SONAME(shr_64.o)"
        echo "# 64"
        dump -X64 -nv $SO | grep EXP | awk '{ print $NF }' | sort | sed '/__dso_handle/d; /__init_aix_libgcc_cxa_atexit/d'
    ) > shr_64.imp
    cp $SO shr_64.o
    strip -X64 -e shr_64.o
    ar -X64 cr $LIB.$SONAME shr_64.o shr_64.imp
    rm shr_64.o shr_64.imp
    ranlib -X64 $LIB.$SONAME
    ln -sf $LIB.$SONAME $LIB
    ;;
    
linux*)
    cp $SO $LIB.$SONAME
    ln -sf $LIB.$SONAME $LIB
    ;;

*)
    echo "Unknown platform: $OS"
    exit 1
esac
