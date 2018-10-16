FILE=main
TEX=pdflatex
BIB=bibtex
FLAGS="-synctex=1 -interaction=nonstopmode"

$(FILE).pdf: $(FILE).aux $(FILE).bbl
	$(TEX) $(FILE) $(FLAGS)

$(FILE).bbl: $(FILE).bib
	$(BIB) $(FILE)

$(FILE).aux: $(FILE).tex data/*.tex
	$(TEX) $(FILE) $(FLAGS)

