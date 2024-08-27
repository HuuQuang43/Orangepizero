# Tên compiler C++
CXX = g++

# Cờ compiler
CXXFLAGS = -Wall -std=c++11

# Các thư viện cần liên kết
LIBS = -lwiringPi

# Bao gồm các thư mục header files
INCLUDES = -I./Lib_Led -I./Lib_Button

# Danh sách các file object được tạo ra từ các file nguồn
OBJS = main.o Lib_Led/ControlLed.o Lib_Button/ControlButton.o

# Tên file thực thi cuối cùng
TARGET = traffic_light_system

# Quy tắc biên dịch toàn bộ dự án
all: $(TARGET)

# Quy tắc để tạo file thực thi
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Quy tắc để biên dịch main.cpp thành file object main.o
main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp

# Quy tắc để biên dịch ControlLed.cpp thành file object ControlLed.o
Lib_Led/ControlLed.o: Lib_Led/ControlLed.cpp Lib_Led/ControlLed.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Lib_Led/ControlLed.cpp

# Quy tắc để biên dịch ControlButton.cpp thành file object ControlButton.o
Lib_Button/ControlButton.o: Lib_Button/ControlButton.cpp Lib_Button/ControlButton.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Lib_Button/ControlButton.cpp

# Quy tắc để dọn dẹp các file tạm thời
clean:
	rm -f *.o $(TARGET) Lib_Led/*.o Lib_Button/*.o
