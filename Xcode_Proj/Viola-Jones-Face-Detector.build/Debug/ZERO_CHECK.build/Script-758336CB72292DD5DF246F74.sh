#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd "/Users/anishghosh/Desktop/Viola Jones Face Detector/Xcode_Proj"
  make -f /Users/anishghosh/Desktop/Viola\ Jones\ Face\ Detector/Xcode_Proj/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd "/Users/anishghosh/Desktop/Viola Jones Face Detector/Xcode_Proj"
  make -f /Users/anishghosh/Desktop/Viola\ Jones\ Face\ Detector/Xcode_Proj/CMakeScripts/ReRunCMake.make
fi

