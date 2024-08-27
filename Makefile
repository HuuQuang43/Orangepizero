# Tên compiler C++
CXX = g++

# Cờ compiler
CXXFLAGS = -Wall 

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
main.o: main.c
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp -o main.o

# Quy tắc để biên dịch ControlLed.cpp thành file object ControlLed.o
Lib_Led/ControlLed.o: Lib_Led/ControlLed.c Lib_Led/ControlLed.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Lib_Led/ControlLed.c -o Lib_Led/ControlLed.o

# Quy tắc để biên dịch ControlButton.cpp thành file object ControlButton.o
Lib_Button/ControlButton.o: Lib_Button/ControlButton.c Lib_Button/ControlButton.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Lib_Button/ControlButton.c -o Lib_Button/ControlButton.o

# Quy tắc để dọn dẹp các file tạm thời
clean:
	rm -f *.o $(TARGET) Lib_Led/*.o Lib_Button/*.o
