#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define EPSILON 0.00001
#define CENTER_RADIUS 800
#define MAP_RADIUS 5000

struct Point {
    double x,y;

    explicit Point(double x, double y) : x(x), y(y) {

    }

    virtual double distance(const Point & p) {
        return sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y));
    }

    virtual double getAngle(const Point & p2) {
        double dx = p2.x-x;
        double dy = p2.y-y;
        return atan2(dy, dx);
    }

    virtual void moveTo(const Point & p, double dist) {
        double d = distance(p);

        if (d < EPSILON) {
            return;
        }

        double dx = p.x - x;
        double dy = p.y - y;
        double coef = dist / d;

        this->x += dx * coef;
        this->y += dy * coef;
    }

    virtual Point getPoint(const Point & target, double dist) {
        double d = distance(target);

        if (d < EPSILON) {
            return target.clonePoint();
        }

        double dx = target.x - x;
        double dy = target.y - y;
        double coef = dist / d;

        double x = this->x + dx * coef;
        double y = this->y + dy * coef;
        return Point(x, y);
    }

    virtual Point clonePoint() const {
        return Point(x,y);
    }
};

struct Unit : Point {
    int id;
    double vx, vy;
    double radius;
    double mass;
    double friction;

    explicit Unit(double x, double y) : Point(x,y) {
        vx = 0;
        vy = 0;
        radius = 0;
        mass = 0;
    }

    virtual void move(double t) {
        x += vx * t;
        y += vy * t;
    }

    virtual void thrust(const Point & p, int power) {
        double dist = distance(p);

        // Avoid a division by zero
        if (abs(dist) <= EPSILON) {
            return;
        }

        double coef = (((double) power) / mass) / dist;
        vx += (p.x - this->x) * coef;
        vy += (p.y - this->y) * coef;
    }
};

struct Center : Unit {
    explicit Center() : Unit(0,0) {
        radius = CENTER_RADIUS;
        friction = 1.0;
        mass = 0;
    }
};


struct Game {
    Center map;
    Center center;

    Game() {
        map.radius = MAP_RADIUS;
    }
};


#endif // GAME_H
