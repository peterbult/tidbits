
all:
	@echo "Nothing to build"

install: 
	cp src/Tools.h       /usr/local/include/CustomTools/
	cp src/StringTools.h /usr/local/include/CustomTools/
	cp src/VectorTools.h /usr/local/include/CustomTools/
	cp src/Segmenter.h   /usr/local/include/CustomTools/
	cp src/Convert.h     /usr/local/include/CustomTools/
	cp src/FileExists.h  /usr/local/include/CustomTools/

