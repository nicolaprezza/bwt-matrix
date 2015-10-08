temp=/home/nico/workspace/bwt-matrix/temp
mkdir $temp

bwt-matrix $1 rev > $temp/source.tex
pdflatex -output-directory $temp $temp/source.tex
mv $temp/source.pdf ~/Desktop/matrix.pdf
rm -rf $temp
