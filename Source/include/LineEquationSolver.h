#include <cmath>
#include <limits>
#include <type_traits>
#include <cassert>

template <typename T, typename U>
struct Point
{
    static_assert(std::is_arithmetic<T>::value &&
                  std::is_arithmetic<U>::value,
                  "Only arithmetic data types allowed");
    T x;
    U y;
};

template <typename Point>
struct is_point : std::false_type {};

template <typename T, typename U>
struct is_point<Point<T, U>> : std::true_type {};

template <typename Point1, typename Point2>
class LineEquationSolver
{
    static_assert(is_point<Point1>::value &&
                  is_point<Point2>::value,
                  "Line equation solver needs Point as parameter");

    long double slope_;
    long double constantValue_;

public:
    LineEquationSolver(Point1 p1, Point2 p2)
    {
        long double deltaY = p2.y - p1.y;
        long double deltaX = p2.x - p1.x;
        if (deltaX == 0.0)
        {
            slope_ = std::numeric_limits<long double>::infinity();
            constantValue_ = std::numeric_limits<long double>::infinity();
        }
        else
        {
            slope_ = deltaY / deltaX;
            constantValue_ = p2.y - (slope_ * p2.x);
        }
    }

    template <class P, 
             class = typename std::enable_if<std::is_arithmetic<P>::value>::type>
    long double getY(P x)
    {
        if (std::isinf(slope_))
        {
            return slope_;
        }

        return slope_ * x + constantValue_;
    }
};
