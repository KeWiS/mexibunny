#ifndef MEXIBUNNY_VECTOR2D_H
#define MEXIBUNNY_VECTOR2D_H

namespace physics {
    class Vector2D {
    public:
        Vector2D() {};
        Vector2D(double vX, double vY);

        inline Vector2D operator+(Vector2D &vec) const {
            return Vector2D(vX + vec.getVX(), vY + vec.getVY());
        }

        inline Vector2D operator-(Vector2D &vec) const {
            return Vector2D(vX - vec.getVX(), vY - vec.getVY());
        }

        inline Vector2D operator*(const double scalar) const {
            return Vector2D(vX * scalar, vY * scalar);
        }

        double getVX();

        void setVX(double vX);

        double getVY();

        void setVY(double vY);

    private:
        double vX = 0, vY = 0;
    };
}

#endif //MEXIBUNNY_VECTOR2D_H
