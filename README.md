### BWT Matrix

bwt-matrix.cpp computes the BWT matrix of an input string and generates tex code to print it in a tabular format. 

## compile

> mkdir build; cd build; cmake ..

## run

(from the build folder)

> ./bwt-matrix mississippi > text.tex
> pdflatex test.tex

generates a pdf with the bwt matrix of the string "mississippi#", where '#' is used as BWT terminator ('#' is lexicographically smaller than all alphabet characters and should not appear in the input string). 

The pdf also also shows the suffix array, the text, and separates (using horizontal lines) BWT rows belonging to the same  equal-letter run. In the text, positions that in the BWT are the first in their equal-letter run are underlined. 