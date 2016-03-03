PROG = Dvector
OBJS = Dvector.o Main.o
CXX = g++
CXXFLAGS = -Wall -g

$(PROG) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

check: $(PROG)
	./$(PROG)

clean: 
	rm $(OBJS) $(PROG)

