#include "chrono.h"

namespace chrono
{
    Date::Date(int dd, Month mm, int yy)
        :d{dd}, m{mm}, y{yy}
    {
        if (y == 0) y = default_date().year;
        if (m == Month{}) m = default_date().month;
        if (d == 0) d = default_date().day;

        if (!is_valid()) throw Bad_date();
    }

    bool Date::is_valid() {
        return is_date(d, m, y);
    }

    Date& Date::add_month(int n) {
        if (n == 0) return *this;
        if (n > 0) {
            int delta_y = n / 12;
            int mm = static_cast<int>(m) + n%12;
            if (12 < mm) {
                ++delta_y;
                mm -= 12;
            }

            y += delta_y;
            m = static_cast<Month>(mm);
            return *this;
        }
        // .. 处理负数 ..
        return *this;
    }
} // namespace chrono
