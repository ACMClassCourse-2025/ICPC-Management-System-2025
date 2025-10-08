#include <chrono>
#include <iostream>

class Timer {
public:
    void start() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        auto end_time = std::chrono::high_resolution_clock::now();
        totduration += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    }

    double duration() const {
        return static_cast<double>(totduration) * std::chrono::nanoseconds::period::num / std::chrono::nanoseconds::period::den;
    }

    void show() const {
        std::cout << " took " << duration() << " seconds\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    long totduration = 0;
};

const int N = 1e6;
int a[N];

int main() {
    Timer timer;
    timer.start();
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    timer.stop();
    timer.show();
    return 0;
}