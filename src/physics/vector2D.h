#ifndef MEXIBUNNY_VECTOR2D_H
#define MEXIBUNNY_VECTOR2D_H

namespace physics {
    class Vector2D {
    public:
        Vector2D() {};

        Vector2D(float vX, float vY);

        inline Vector2D operator+(Vector2D &vec) const {
            return Vector2D(vX + vec.getVX(), vY + vec.getVY());
        }

        inline Vector2D operator-(Vector2D &vec) const {
            return Vector2D(vX - vec.getVX(), vY - vec.getVY());
        }

        inline Vector2D operator*(const float scalar) const {
            return Vector2D(vX * scalar, vY * scalar);
        }

        float getVX();

        void setVX(float vX);

        float getVY();

        void setVY(float vY);

    private:
        float vX = 0, vY = 0;
    };
}

#endif //MEXIBUNNY_VECTOR2D_H
