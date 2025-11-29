#include "Point.hpp"

Fixed sign(Point const& p1, Point const& p2, Point const& p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
	       (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	const Fixed d1 = sign(point, a, b);
	const Fixed d2 = sign(point, b, c);
	const Fixed d3 = sign(point, c, a);

	const float fd1 = d1.toFloat();
	const float fd2 = d2.toFloat();
	const float fd3 = d3.toFloat();

	if (fd1 == 0.0f || fd2 == 0.0f || fd3 == 0.0f)
		return false;

	const bool hasNegative = (fd1 < 0.0f) || (fd2 < 0.0f) || (fd3 < 0.0f);
	const bool hasPositive = (fd1 > 0.0f) || (fd2 > 0.0f) || (fd3 > 0.0f);

	return !(hasNegative && hasPositive);
}
