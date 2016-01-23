
all:
	@echo "Nothing to build"

install: 
	cp src/Tools.h       /usr/local/include/CustomTools/
	cp src/StringTools.h /usr/local/include/CustomTools/
	cp src/VectorTools.h /usr/local/include/CustomTools/

