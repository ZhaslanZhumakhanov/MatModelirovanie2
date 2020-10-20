#include <cmath>
#include <iostream>
#include <iomanip>

float Eiler(float x, float y) {
    return 2 * x * std::sqrt(y) - y;
}

int Rounding(double error) {
    int count = 0;
    while (true) {
        double tmp = error;
        if (static_cast<int>(tmp) % 10 != 0 || static_cast<int>(tmp) < 1) {
            error *= 10;
            count++;
        } else {
            count--;
            break;
        }
    }
    return count--;
}

int main() {

    float a, s, b;
    double error;// Погрешность

    std::cout << "Please enter A " << std::endl;
    std::cin >> a;
    std::cout << "Please enter S " << std::endl;
    std::cin >> s;

    while (s < 0) {
        std::cout << "Please enter new S (s>=0)" << std::endl;
        std::cin >> s;
    }

    std::cout << "Please enter B " << std::endl;
    std::cin >> b;
    std::cout << "Please enter Error " << std::endl;
    std::cin >> error;

    while (error <= 0 || error >= 1) {
        std::cout << "Please enter new Error([0;1])" << std::endl;
        std::cin >> error;
    }

    float x_i, y_i, dy_i, yi_2, h;

    int steps = 1;
    while (true) {
        h = (b - a) / steps;
        x_i = a;
        y_i = s;
        for (int i = 0; i < steps; i++) {
            x_i = x_i + h;
            dy_i = h * Eiler(x_i, y_i);
            y_i = y_i + dy_i;
        }
        if (steps == 10000) {
            std::cout << "Didn't reach the point" << std::endl;
            break;
        }
        if (std::abs(y_i - yi_2) < error) {
            break;
        }
        steps++;
        yi_2 = y_i;
    }

    std::cout << "Iterations - " << steps << std::endl;
    std::cout << "Last value - " << std::fixed << std::setprecision(Rounding(error)) << y_i;
}
