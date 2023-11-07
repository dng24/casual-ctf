#!/bin/sh

out_file="$1"
challenge_name="$2"
binary="$3"

echo "
Welcome to the ${challenge_name} challenge!

The challenge is located in the ${binary} binary in the current directory.

Feel free to solve it here in the Docker container or on your local machine (use
scp to copy the binary off the container).

Good luck!

" > ${out_file}
