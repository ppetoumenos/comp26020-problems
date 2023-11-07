#include <array>
#include <chrono>
#include <iostream>
#include <iomanip>

template <typename Clock>
void _clock_gettime(timespec* tp) {
  auto elapsed = Clock::now().time_since_epoch();
  auto secs = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
  auto nsecs = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed - secs);

  tp->tv_sec = secs.count();
  tp->tv_nsec = nsecs.count();
}

int my_clock_gettime(clockid_t clockid, timespec* tp) {
  if (clockid == CLOCK_REALTIME) {
    _clock_gettime<std::chrono::system_clock>(tp);
    return 0;
  }
  if (clockid == CLOCK_MONOTONIC) {
    _clock_gettime<std::chrono::steady_clock>(tp);
    return 0;
  }
  return 1;
}

void print_time(timespec& t) {
  tm tm;
  char buf[128];
  gmtime_r(&t.tv_sec, &tm);
  strftime(buf, 128, "%Y-%m-%dT%H:%M:%S.", &tm);
  std::cout << buf << std::setw(9) << std::setfill('0') << t.tv_nsec << "\n";
}

int main(int argc, char **argv) {
  std::array<clockid_t, 3> clocks{CLOCK_MONOTONIC, CLOCK_REALTIME, CLOCK_TAI};
  std::array<std::string, 3> clock_names{"CLOCK_MONOTONIC", "CLOCK_REALTIME", "CLOCK_TAI"};

  for (int i = 0; i < clocks.size(); ++i) {
    std::cout << clock_names[i] << ": ";

    timespec curtime;
    int retval = my_clock_gettime(clocks[i], &curtime);
    if (retval == 0) {
      print_time(curtime);
    } else {
      std::cout << "ERROR!\n";
    }
  }

  return 0;
}
