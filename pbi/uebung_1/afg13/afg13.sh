#! /bin/sh

echo
echo "  >>afg1.3"
echo

grep -v '>' ychrIII.fna | tr -d "\n" | head -c 123 | fold -60

echo
echo