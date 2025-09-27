
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

long long cross(const std::vector<int>& p1, const std::vector<int>& p2){
    int ax = p1[0];
    int ay = p1[1];
    int bx = p2[0];
    int by = p2[1];
    return (long long)ax * by - (long long)ay * bx;
}

double area(const std::vector<int>& p1, const std::vector<int>& p2, const std::vector<int>& p3){
    return std::abs(cross(p1, p2) + cross(p2, p3) + cross(p3, p1)) / 2.0;
}

// i could do the convex hull and then find the area, with rotating clipers algorithm
double largestTriangleArea(std::vector<std::vector<int>>& points) {
        double max_area = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    max_area = std::max(max_area, area(points[i], points[j], points[k]));
                }
            }
        }
        return max_area;
}

int main(){
    std::vector<std::vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    std::cout << largestTriangleArea(points) << std::endl;
    return 0;
}
