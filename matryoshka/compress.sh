#!/bin/sh

output_file=f

if [ -n "$1" ]; then
    output_file="$1"
fi

chmod a-x flag
mv flag .flag.txt.swp
zip -e -P "you're almost there!" flag.zip .flag.txt.swp
zip ls.zip ls
rm .flag.txt.swp

mkdir tmp/
unzip flag.xlsx -d tmp/
mv flag.zip tmp/xl/worksheets/flag.xml
mv ls.zip tmp/xl/worksheets/_rels/ls.xml.rels
cd tmp/
zip -r ../f.xlsx *
cd ../
rm -rf tmp/

mv f.xlsx f

tar czf f.tar.gz f
mv f.tar.gz f

bzip2 -f f
mv f.bz2 f

gzip -f f
mv f.gz f

lzma -f f
mv f.lzma f

tar cf f.tar f
mv f.tar f

rzip -f f
mv f.rz f

compress -f f
mv f.Z f

lzop -fU f
mv f.lzo f

zip flag.zip f
mv flag.zip $output_file

# flag.xlsx.tar.gz.bz2.gz.lzma.tar.rz.Z.lzo.zip is the full chain
# inside flag.xlsx is flag.zip and ls.zip
