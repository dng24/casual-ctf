#!/bin/sh

out_file="$1"
challenge_name="$2"

echo "
Welcome to the ${challenge_name} challenge!

Find the imposter binary located somewhere on this machine.

Good luck!

" > ${out_file}
