#! /bin/sh

# Script to derive arch-specific symbol lists from a library
#
# Some of these steps could be parallelized across archs, but neither
# the degree of potential parallelism nor the amount of data are sufficent
# to justify the added complexity.

IN="$1"
OUTROOT="$2"
shift 2
ARCHS="$@"

OUTEXT=".tmp"
TMPROOT="/tmp/getlibsyms"
TMPOUT="$TMPROOT/$(basename $OUTROOT)"

mkdir -p "$TMPROOT" || exit $?

# First get a symbol list for each arch.
# Run through 'sort' for consistency, so don't bother with nm's sort.
# Suppress stderr to avoid "no symbols" warnings in empty cases.
for ARCH in $ARCHS; do
  nm -arch "$ARCH" -gUp "$IN" 2>/dev/null \
      | grep '^[^/]' | awk '{print $2 " " $3}'| sort \
      >"$TMPOUT-$ARCH$OUTEXT" || exit $?
done

# Get complete list of syms for all archs (union of per-arch sets).
for ARCH in $ARCHS; do
  cat "$TMPOUT-$ARCH$OUTEXT" || exit $?
done | sort | uniq >"$TMPOUT-all$OUTEXT" || exit $?

# For each arch, get list of syms not in that arch.
for ARCH in $ARCHS; do
  comm -23 "$TMPOUT-all$OUTEXT" "$TMPOUT-$ARCH$OUTEXT" \
      >"$TMPOUT-$ARCH-not$OUTEXT" || exit $?
done

# Get combined list of syms missing from at least one arch.
for ARCH in $ARCHS; do
  cat "$TMPOUT-$ARCH-not$OUTEXT" || exit $?
done | sort | uniq >"$TMPOUT-all-not$OUTEXT" || exit $?

# Get list of syms common to all archs (i.e., not in combined 'missing' list).
comm -23 "$TMPOUT-all$OUTEXT" "$TMPOUT-all-not$OUTEXT" \
    >"$OUTROOT-all-only$OUTEXT" || exit $?

# For each arch, get list of syms in that arch but not in common list.
for ARCH in $ARCHS; do
  comm -23 "$TMPOUT-$ARCH$OUTEXT" "$OUTROOT-all-only$OUTEXT" \
      >"$OUTROOT-$ARCH-only$OUTEXT" || exit $?
done

if [ "$KEEPTMP" == "" ]; then
 rm -rf "$TMPROOT"
fi
