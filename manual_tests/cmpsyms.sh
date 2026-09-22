#! /bin/sh

FILE1="$1"
FILE2="$2"
SRC="$3"
shift 3
ARCHS="$@"

TMPROOT="/tmp/getlibsyms"
TMPEXT=".tmp"
BASE1=$(basename "$FILE1")
BASE2=$(basename "$FILE2")
TMP1="$TMPROOT/$BASE1$TMPEXT"
TMP2="$TMPROOT/$BASE2$TMPEXT"

# Avoid 'nm' errors when lib is empty
if ! [ -s "$SRC" ]; then
  exit 0
fi

get_syms() {
  nm -gU $2 $1 | awk '{print $2 " " $3}' | egrep '^(T|S)'
}

mkdir -p "$TMPROOT" || exit $?

if [ "$ARCHS" == "" ]; then
  get_syms "$FILE1" >"$TMP1" || exit $?
  get_syms "$FILE2" >"$TMP2" || exit $?
  diff "$TMP1" "$TMP2"
else
  for ARCH in $ARCHS; do
    get_syms "$FILE1" "-arch $ARCH" >"$TMP1" || exit $?
    get_syms "$FILE2" "-arch $ARCH" >"$TMP2" || exit $?
    diff "$TMP1" "$TMP2"
  done
fi

if [ "$KEEPTMP" == "" ]; then
 rm -rf "$TMPROOT"
fi
