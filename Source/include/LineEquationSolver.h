template <typename T, typename U>
class LineEquationSolver
{
    long double slope_;
    long double constantValue_;
public:
    LineEquationSolver(T x1_point, U y1_point, T x2_point, U y2_point)
    {
        long double deltaY = y2_point - y1_point;
        long double deltaX = x2_point - x1_point;
        slope_ = deltaY / deltaX;

        constantValue_ = y2_point - (slope_ * x2_point);
    }

    long double getY(long double x)
    {
        return slope_ * x + constantValue_;
    }
};
