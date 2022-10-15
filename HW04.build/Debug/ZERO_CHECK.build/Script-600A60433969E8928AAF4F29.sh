#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/irisjeong/Documents/hw04-iris-jeong
  make -f /Users/irisjeong/Documents/hw04-iris-jeong/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/irisjeong/Documents/hw04-iris-jeong
  make -f /Users/irisjeong/Documents/hw04-iris-jeong/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/irisjeong/Documents/hw04-iris-jeong
  make -f /Users/irisjeong/Documents/hw04-iris-jeong/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/irisjeong/Documents/hw04-iris-jeong
  make -f /Users/irisjeong/Documents/hw04-iris-jeong/CMakeScripts/ReRunCMake.make
fi

