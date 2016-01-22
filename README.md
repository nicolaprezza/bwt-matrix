###BWT Matrix

bwt-matrix.cpp computes the BWT matrix of an input string and generates tex code to print it in a tabular format. The main script bwt-matrix.sh executes the C++ code and pdflatex to generate a pdf.

##compile

> mkdir build; cd build; cmake ..

Then, put the executable bwt-matrix in a place indexed by PATH (e.g. /bin/).

##execute

example: from the main bwt-matrix/ folder, the command

> ./bwt-matrix.sh mississippi

generates and saves on your desktop a pdf with the bwt matrix of the string "mississippi#", where '#' is used as BWT terminator ('#' is lexicographically smaller than all alphabet characters and should not appear in the input string).