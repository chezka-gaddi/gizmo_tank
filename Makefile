CXX = g++
CXXFLAGS = -g -std=c++11 -fPIC
INCS = -Isrc/ -I
LIBS = -ldl -lCTF -Llibraries
SOFLAGS = -DDYNAMIC

SRC_PATH= src/
TANK_PATH= tanks/
LIB_PATH= libraries/

TANKS = gizmo/source/Gizmo.so

INCLUDE  := -Igizmo/include/ -Isrc/
TANKS_LINK = src/Actor.o #need to link in the base class for the .so to have everything.
TANKS_LINK += $(filter-out gizmo/source/Gizmo.cpp, $(wildcard gizmo/source/*.cpp))

%.so: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -shared $< $(TANKS_LINK) -o $@ $(SOFLAGS) $(LIBS)

%.h.gch: %.h
	$(CXX) -x c++-header -c $< -o $@ $(INCS) $(LIBS)
	
%.txt:
	cp config.sample config.txt
	
config:	config.txt tanks

tanks:	$(TANKS)
	mkdir -p $(TANK_PATH)
	mv $^ $(TANK_PATH)

cleanTanks:
	rm -rf $(TANK_PATH)
