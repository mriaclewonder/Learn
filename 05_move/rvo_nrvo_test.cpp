#include <iostream>
namespace week_05
{
    class Widget
    {
    public:
        Widget() {}
        Widget(const Widget &) { std::cout << "Widget copy\n"; }
        Widget(Widget &&) noexcept { std::cout << "Widget move\n"; }
    };

    Widget make_rvo() { return Widget(); }
    Widget make_nrvo()
    {
        Widget w;
        return w;
    }

    Widget make_move()
    {
        Widget w;
        return std::move(w);
    }

    void test_rvo_nrvo()
    {
        make_rvo();
        std::cout << "1\n";
        make_nrvo();
        std::cout << "2\n";
        make_move();
        std::cout << "3\n";
    }
}

int main(int argc, char const *argv[])
{
    week_05::test_rvo_nrvo();
    return 0;
}
