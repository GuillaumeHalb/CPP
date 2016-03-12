PROG = Darray Dvector Dmatrix
OBJS = Darray.o TestDmatrix.o Dvector.o Dmatrix.o
CXX = g++
CXXFLAGS = -Wall -g

$(PROG) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

check: $(PROG)
	./$(PROG)

clean: 
	rm $(OBJS) $(PROG)

