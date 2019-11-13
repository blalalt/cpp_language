#include <iostream>
#include <string>
namespace chrono {

    enum class Month{ jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dev};

    class Date {
    public:
        class Bad_date{}; // 异常类
        explicit Date(int dd={}, Month mm={}, int yy={}); // 表示 选择默认值

        // 非修改性函数
        inline int day() const {return d;}; 
        Month month() const;
        int year() const;

        std::string string_rep() const;
        void char_rep(char s[], int max) const;

        // 修改性函数,改变对象的状态
        Date& add_year(int n);
        Date& add_month(int n);
        Date& add_day(int n);
    private:
        bool is_valid();
        int d, y;
        Month m;
    };

    // 一些辅助函数，若定义在类内会增加类接口的复杂性，还会着呢改嫁那些考虑修改类表现时需要检查的函数数目
    // 将其放在同一个命名空间显式两者的关联
    bool is_date(int d, Month m, int y);
    bool is_leapyear(int y);

    inline bool operator==(const Date& a, const Date& b) {
        return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
    }
    bool operator!=(const Date& a, const Date& b);

    const Date& default_date();

    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& d);

    Date& operator++(Date& d) {
        return d.add_day(1);
    }

    // --
    // += -= + -....
};