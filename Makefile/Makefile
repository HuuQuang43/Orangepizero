CXX = g++
CXXFLAGS = -Wall
LIBS = -lwiringPi
INCLUDES = -I./Lib_Led -I./Lib_Button
OBJS = main.o Lib_Led/ControlLed.o Lib_Button/ControlButton.o

TARGET = traffic_light_system

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp

Lib_Led/ControlLed.o: Lib_Led/ControlLed.cpp Lib_Led/ControlLed.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Lib_Led/ControlLed.cpp

Lib_Button/ControlButton.o: Lib_Button/ControlButton.cpp Lib_Button/ControlButton.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Lib_Button/ControlButton.cpp

clean:
	rm -f *.o $(TARGET)

