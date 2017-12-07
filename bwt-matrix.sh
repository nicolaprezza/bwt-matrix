temp=~/workspace/bwt-matrix/temp
mkdir $temp

bwt-matrix $1 > $temp/source.tex
pdflatex -output-directory $temp $temp/source.tex
mv $temp/source.pdf ~/Desktop/matrix.pdf
mv $temp/source.tex ~/Desktop/matrix.tex
rm -rf $temp
