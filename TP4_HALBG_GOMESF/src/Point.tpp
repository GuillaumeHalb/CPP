Point::Point(double x, double y) 
{
	abs = x;
	ord = y;
}

double Point::x() const
{
  return abs;
}

double Point::y() const
{
  return ord;
}

Point::~Point()
{}