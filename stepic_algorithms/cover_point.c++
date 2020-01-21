#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef std::pair <int, int> Segment;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return (a.first < b.first);
    return (a.second < b.second);
}

std::vector <int> get_covering_set(std::vector <Segment> segments) {
    std::vector <int> result;

    sort(segments.begin(), segments.end(), cmp);

    // fix this function
    for (std::size_t i = 0; i < segments.size(); i++) {
        if (!result.empty()) {
            if (segments[i].first > result.back())
                result.push_back(segments[i].second);
        } else
            result.push_back(segments[i].second);
    }

    return result;
}

int main(void) {
    int segments_count;
    std::cin >> segments_count;
    std::vector <Segment> segments(segments_count);
    for (int i = 0; i < segments_count; i++) {
        std::cin >> segments[i].first >> segments[i].second;
    }

    std::vector <int> points = get_covering_set(segments);
    std::cout << points.size() << std::endl;
    for (std::size_t i = 0; i < points.size(); i++) {
        std::cout << points[i] << " ";
    }
    std::cout << std::endl;
}