#!/usr/bin/env bash

set -euo pipefail

DIR="$(dirname "$(realpath "$0")")"

if [[ -d '/edg/workspace/dev_tools' ]] ; then
  # Configure EDG PATH and Python pylibs
  #
  # In this context the container PATH is given priority.  This makes sure the
  # /edg/native-tools/bin takes priority (and thus the native binaries built
  # for docker are used over native binaries built for the host).
  #
  export PATH="$PATH:/edg/workspace/dev_tools/bin"
  export PYTHONPATH="$PYTHONPATH:/edg/workspace/dev_tools/pylibs"

  # Configure EDG compiler scraping exports
  export EDG_GCC_INCL_SCRAPE=$(edg-scrape-compiler gcc --lang c++ includes)
  export EDG_GCC_CINCL_SCRAPE=$(edg-scrape-compiler gcc --lang c includes)
  export EDG_GCC_VER_SCRAPE=$(edg-scrape-compiler gcc version)
  export EDG_CLANG_INCL_SCRAPE=$(edg-scrape-compiler clang --lang c++ includes)
  export EDG_CLANG_CINCL_SCRAPE=$(edg-scrape-compiler clang --lang c includes)
  export EDG_CLANG_VER_SCRAPE=$(edg-scrape-compiler clang version)
fi

exec "$@"
