#include <cmath>
#include <limits>
#include <type_traits>
#include <cassert>

template <typename T, typename U,
         class = typename std::enable_if<std::is_arithmetic<T>::value && 
                                         std::is_arithmetic<U>::value>::type>
class LineEquationSolver
{
    long double slope_;
    long double constantValue_;
public:
    LineEquationSolver(T x1_point, U y1_point, T x2_point, U y2_point)
    {
        long double deltaY = y2_point - y1_point;
        long double deltaX = x2_point - x1_point;
        if (deltaX == 0.0)
        {
            slope_ = std::numeric_limits<long double>::infinity();
            constantValue_ = std::numeric_limits<long double>::infinity();
        }
        else
        {
            slope_ = deltaY / deltaX;
            constantValue_ = y2_point - (slope_ * x2_point);
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
