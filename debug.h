#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG_H
#define DEBUG_H

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec);
template <typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::set<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::multiset<T> & vec);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::pair<T1,T2> & p);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::map<T1,T2> & p);

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec){
    os << "{";
    bool flag = 0;
    for(auto elem : vec) {
        if(!flag) os << elem;
        else os << " " << elem;
        flag = 1;
    }
    os << "}";
    return os;
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &vec) {
    os << "{";
    bool flag = 0;
    for(auto elem : vec) {
        if(!flag) os << elem;
        else os << " " << elem;
        flag = 1;
    }
    os << "}";
    return os;
}

template <typename T>
std::ostream & operator << (std::ostream & os, const std::set<T> & vec){
    os << "{";
    bool flag = 0;
    for(auto elem : vec) {
        if(!flag) os << elem;
        else os << " " << elem;
        flag = 1;
    }
    os << "}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::multiset<T> & vec){
    os << "{";
    bool flag = 0;
    for(auto elem : vec) {
        if(!flag) os << elem;
        else os << " " << elem;
        flag = 1;
    }
    os << "}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::pair<T1,T2> & p){
    os << "{" << p.first << " " << p.second << "}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::map<T1,T2> & p){
    os << "{";
    bool flag = 0;
    for(auto x: p) {
        if(!flag) os << "{" << x.first << " " << x.second << "}";
        else os << " {" << x.first << " " << x.second << "}"; 
        flag = 1;
    }
    os << "}";
    return os;
}

#define dbg1(x) cerr << #x << " = " << x << "\n"
#define dbg2(x, y) cerr << #x << " = " << x << " " << #y << " = " << y << "\n"
#define dbg3(x, y, z) cerr << #x << " = " << x << " " << #y << " = " << y << " " << #z << " = " << z << "\n"
#define dbg4(a, b, c, d) cerr << #a << " = " << a << " " << #b << " = " << b << " " << #c << " = " << c << " " << #d << " = " << d << "\n"
#define dbg5(a, b, c, d, e) cerr << #a << " = " << a << " " << #b << " = " << b << " " << #c << " = " << c << " " << #d << " = " << d << " " << #e << " = " << e << "\n"
#define GET_MACRO(_1, _2, _3, _4, _5, NAME,...) NAME
#define debug(...) GET_MACRO(__VA_ARGS__, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)

#endif