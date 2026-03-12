# adapto make del paper de las notas
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Iinclude 

OBJ = main.o src/DTFecha.o src/Alojamiento.o src/DTExpe.o src/EventoCultural.o src/Experiencia.o src/TourGuiado.o src/Turista.o

EXEC = lab0

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)

test:
	valgrind ./$(EXEC)