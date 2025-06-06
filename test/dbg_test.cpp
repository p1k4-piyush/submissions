#include <array>
#include <bitset>
#include <chrono>
#include <forward_list>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <span>
#include <vector>

#include "dbg.hpp"

std::mt19937_64 rng(std::chrono::steady_clock().now().time_since_epoch().count());

struct Point {
    int x {}, y {};
};

auto& operator<<(std::ostream& os, Point pt)
{
    return os << "Point(" << pt.x << ", " << pt.y << ')';
}

using namespace std;

int main()
{
    {
        dbg(), dbg("# Writing to a custom stream");

        std::stringstream ss;
        _dbglib::dbg_impl(ss, vector { 1, 2, 3, 4 });
        dbg(ss.str());
    }

    {
        dbg(), dbg("# Tuple (empty too)");

        tuple t { 42 };
        dbg(t);

        tuple unit {};
        dbg(unit);

        dbg(tuple {});
        dbg(tuple { 1, 2, 3 });

        tuple nums { 1, 2ULL, 3.f, 4.0, 5.0l };
        dbg(nums);

        tuple nested { 1, 2ULL, 3.f, 4.0, vector(5, 3.f) };
        vector vec(20, nested);
        dbg(vec);

        tuple t2 { nums, nums, nums, nums, nums, nums, nums, nums };
        dbg(t2);
        dbg(vector(5, t2));
    }

    {
        dbg(), dbg("# Signed vs unsigned int");

        dbg(1 << 20);
        dbg(1u << 20);

        dbg(int64_t(rng()));
        dbg(rng());
    }

    {
        dbg(), dbg("# Angle brackets in expr");

        int a = 13, b = 42;
        dbg(1U << a, b);
        dbg(1 < a, b);
        dbg(a, b < 4);
        dbg(a, b <= 4, b);

        dbg(1 << 9 | 3, "hi"sv);
        dbg(4 < 8, 3 > 6);
        dbg(vector(10, pair { 5u, "abc"sv }));

        dbg(vector { 1 > 2 and 3 > 1 }, "broken");
    }

    {
        char chr = 'A';
        int arr[] = { 1, 2, 3, 4 };
        bitset<8> bs(100);
        map<string, int> mp {
            { "apple", 5 },
            { "banana", 3 },
            { "orange", 7 }
        };
        dbg(chr, arr, bs, mp);
    }

    {
        dbg(), dbg("# Custom types");

        constexpr Point pt { 1, 2 };
        dbg(pt);

        dbg(Point { 42, 24 });

        vector<array<Point, 3>> pts(5);
        dbg(pts);
    }

    {
        dbg(), dbg("# Vector of strings");

        vector lorem_ipsum {
            "Lorem ipsum odor amet, consectetuer adipiscing elit.",

            "Torquent aliquet mus volutpat dictumst justo nibh?",

            "Accumsan cursus odio facilisis gravida pulvinar rutrum.",

            "Eros penatibus malesuada inceptos aenean turpis penatibus pharetra. Morbi auctor varius ridiculus "
            "bibendum diam erat finibus nisi sociosqu. Dis semper eros ullamcorper in mus. Proin lacus venenatis nulla "
            "senectus cursus proin libero. Aliquet vehicula erat natoque ex; integer tellus vel. Aliquam ex luctus "
            "maximus non cras montes dignissim finibus.",

            "Turpis congue potenti, himenaeos tristique ridiculus platea.",

            "Tellus facilisis integer posuere bibendum urna conubia. Faucibus est porttitor purus ullamcorper ut non "
            "facilisi ex sollicitudin.",

            "Molestie sodales euismod scelerisque nibh mus quam. Ac nascetur tincidunt magnis tincidunt maximus ac "
            "integer augue scelerisque. Varius cubilia sollicitudin consequat dolor in quam class. Efficitur ad "
            "pretium morbi massa taciti morbi nunc congue maximus."
        };

        dbg(lorem_ipsum);
    }

    using views::join;

    {
        dbg(), dbg("# Boolean matrix");

        vector vis(10, vector(20, false));
        for (auto& row : vis) {
            for (int i = 0; i < ssize(row); ++i)
                row[i] = bool(rng() % 2);
        }
        dbg(vis);
    }

    {
        dbg(), dbg("# Nested vectors");

        vector vec0(12, vector(25, 0));
        for (auto& i : vec0 | join)
            i = int(rng() % 1000);
        dbg(vec0), dbg();

        vector vec1(4, vector(6, vector(24, 0)));
        for (auto& i : vec1 | join | join)
            i = int(rng() % 1000);
        dbg(vec1), dbg();

        vector bruh(3, vector(2, vector(4, vector(3, vector(3, 0)))));
        for (auto& i : bruh | join | join | join | join)
            i = int(rng() % 100);
        dbg(bruh), dbg();
    }

    {
        dbg(), dbg("# Other STL containers");

        queue<pair<int, string>> q;
        q.emplace(3, "three"s);
        q.emplace(4, "four"s);
        q.emplace(5, "five"s);
        dbg(q);
        dbg(vector<int> {});
        dbg(queue<int> {});

        dbg(map<int, string_view> {
            { 1, "one"sv },
            { 2, "two"sv } });

        std::array<std::vector<int>, 3> x {
            vector { 1, 2, 3 },
            vector { 1, 2 },
            vector { 3, 4 }
        };

        std::vector<std::array<int, 3>> y {
            array { 1, 2, 3 },
            array { 4, 5, 6 },
            array { 1, 3, 6 },
            array { 0, 1, 4 },
        };

        std::list l {
            vector { array { 1, 2 }, array { 3, 4 } },
            vector { array { 3, 4 }, array { 4, 5 } },
        };
        dbg(x, y, l);
        dbgl(x, y, l);

        dbg("abcdef"s);
        dbg("abcdef"sv);
        dbg(deque { "abc"s, "def"s });
        dbg(forward_list { "abc", "def" });
        dbg(deque { "abcdef"sv, "xyz"sv });

        auto s = "abc";
        dbg(s);

        char str[] = "def";
        dbg(str);
    }

    {
        dbg(), dbg("# C strings and char arrays");

        int a[] = { 1, 2, 3 };
        char s[] = "char arr test";
        char const* t = "char ptr test";
        dbg(a, s, t);
    }

    {
        dbg(), dbg("# C arrays");

        int a[] = { 1, 2, 3 };
        dbg(a);

        int* p = a;
        dbg(span(p, 3)); // Printing decayed arrays

        int n = 3;
        int d[n];
        iota(d, d + n, 42);
        dbg(span(d, n)); // Printing VLAs

        int arr[1 << 5] {};
        for (auto& i : arr)
            i = int(rng() % 1000);
        dbg(arr);

        double mat[2][3][4][5] {};
        for (auto& i : mat | join | join | join)
            i = double(rng() % 1000) / 100.;
        dbg(mat);

        auto* decayed_mat = mat;
        dbg(span(decayed_mat, 2)); // Printing decayed nested arrays
        dbg(decayed_mat);
    }

    {
        dbg(), dbg("# Pointers");

        void* ptr = (void*)__LINE__;
        dbg(ptr);

        void* raw_nptr = (void*)0;
        dbg(raw_nptr);

        dbg((void*)0x4242424242, (int*)0x0000696969);

        auto nptr = nullptr;
        dbg(nptr);
    }

    {
        using Ids = std::variant<int, double, std::string>;
        Ids var { 42 };
        dbg(var);
        var = "does it work?"s;
        dbg(var);

        vector v(7, Ids { string(101, 'A') });
        dbg(v);
    }
}
