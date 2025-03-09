# how to use c++ call matplotlib
There are only 2 steps to call python-matplotlib in c++ file.
## step one
cpp source file
```cpp
#include "../matplotlibcpp.h" // must required
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
```
## step two
CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.0)
project(cppcallmat)

set(Python3_ROOT_DIR /home/u20/anaconda3/envs/rda/bin) # set to anaconda python path if using conda virtual environment.
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

set(Python3_NumPy_ROOT ${Python3_ROOT_DIR})
find_package(Python3 COMPONENTS NumPy REQUIRED)

add_executable(main cpp_call_matplotlib.cpp)
target_link_libraries(main PRIVATE Python3::Python Python3::NumPy)
```
## Acknowledgement

[matplotlib-cpp](https://github.com/Cryoris/matplotlib-cpp/tree/master)