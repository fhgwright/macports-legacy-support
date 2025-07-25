#! /bin/sh

# Script to determine which architectures can build and run on this machine.
# The list of architectures to test can be specified on the command line;
# the default is to test all known architectures.  The final output is
# the filtered architecture list.
#
# We need to verify that the program can actually run; not just that it built.
#
# Some gccs ignore unsupported -arch options, so we need to include a check
# in the test program to verify the expected architecture.
#
# In addition, some MacPorts clangs segfault when given unsupported -arch
# options, causing an error message from bash rather than clang.  To get
# around this, we wrap the entire compiler execution in another level of
# shell, so that we can suppress the error message.
#
# Similarly, attempting to run an executable with an unsupported architecture
# sometimes produces an error message from the shell, so we also wrap this
# in another shell to allow suppressing the error message.

ALLARCHS="${@:-ppc ppc64 i386 x86_64 arm64}"

if [ "$CC" == "" ]; then CC=cc; fi

TESTBIN="/tmp/testprog-$$"
TESTSRC="${TESTBIN}.c"

RUNARCHS=""
for a in $ALLARCHS; do
	cat >$TESTSRC <<EOD
	int
	main(int argc, char *argv[])
	{
		(void) argc; (void) argv;
	  #ifdef __${a}__
  		return 0;
  	#else
  	  return 1;
  	#endif
	}
EOD
  rm -f $TESTBIN
  if sh -c "$CC -arch $a $TESTSRC -o $TESTBIN 2>/dev/null" 2>/dev/null; then
    if sh -c "$TESTBIN" 2>/dev/null; then
      RUNARCHS="$RUNARCHS $a"
    fi
  fi;
done

rm -f $TESTSRC $TESTBIN

echo $RUNARCHS
