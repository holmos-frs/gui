EXECUTABLE=holmos-gui
OBJDIR=objs
LFLAGS=`pkg-config --libs gtkmm-3.0` -lopencv_imgproc -lopencv_imgcodecs -lopencv_core
CXXFLAGS=-O2 -std=c++14 `pkg-config --cflags gtkmm-3.0` -g
SOURCES=main,Application,ApplicationWindow

run: holmos-gui
	DISPLAY=:0 ./${EXECUTABLE}

holmos-gui: ${OBJDIR}/ApplicationWindow.o ${OBJDIR}/Application.o ${OBJDIR}/main.o
	g++ ${OBJDIR}/{${SOURCES}}.o -o ${EXECUTABLE} ${CXXFLAGS} ${LFLAGS}

${OBJDIR}/%.o: src/%.cpp
	g++ -c ./$< ${CXXFLAGS} ${LFLAGS} -o $@

clean:
	rm ${EXECUTABLE}
	rm ${OBJDIR}/*
