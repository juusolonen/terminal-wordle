BUILDDIR := build
OBJDIR := obj
CLASSDIR := classes

terminal-wordle: main.cpp wordgame | createdir
	g++ -I${CLASSDIR} -o ${BUILDDIR}/terminal-wordle main.cpp \
	${OBJDIR}/printerwriter.o \
	${OBJDIR}/wordgame.o

wordgame: classes/wordgame.cpp printerwriter| createdir
	g++ -c ${CLASSDIR}/wordgame.cpp -o ${OBJDIR}/wordgame.o

printerwriter: classes/printerwriter.cpp | createdir
	g++ -c ${CLASSDIR}/printerwriter.cpp -o ${OBJDIR}/printerwriter.o

createdir:
	mkdir -p ./${BUILDDIR}
	mkdir -p ./${OBJDIR}

clean:
	rm -rf ./${BUILDDIR}
	rm -rf ./${OBJDIR}