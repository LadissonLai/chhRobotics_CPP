#include "../matplotlibcpp.h"
#include <vector>
#include <cmath>

namespace plt = matplotlibcpp;

int main() {
    // 生成数据
    std::vector<double> x, y;
    for (double i = 0; i < 10; i += 0.1) {
        x.push_back(i);
        y.push_back(std::sin(i));
    }

    // 绘制正弦曲线
    plt::plot(x, y, "r-");
    plt::title("Sine Wave");
    plt::xlabel("X Axis");
    plt::ylabel("Y Axis");
    plt::grid(true);
    plt::show();

    return 0;
}
