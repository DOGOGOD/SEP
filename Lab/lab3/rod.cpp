#include "rod.h"
#include <cstddef>

Rod::Rod(const int capacity, const int id) : capacity(capacity), id(id) { }

bool Rod::push(const Disk d) {
    if (full()) {
        return false;
    }
    stack.push(d);
    return true;
}

const Disk &Rod::top() {
    return stack.top();
}

void Rod::pop() {
    stack.pop();
}

size_t Rod::size() const {
    return stack.size();
}

bool Rod::empty() const {
    return stack.empty();
}

bool Rod::full() const {
    return int(size()) == capacity;
}

void Rod::draw(Canvas &canvas) {
    const int s_x = 5 + (id * 15);
    int n = int(size());
    Disk *tmp = new Disk[n];
    for (int i = n - 1; i >= 0; i--) {
        tmp[i] = stack.top();
        stack.top().draw(canvas, i, id);
        stack.pop();
        canvas.buffer[Canvas::HEIGHT - i * 2 - 1][s_x] = '|';
    }
    for (int i = 0; i < Canvas::HEIGHT - n * 2; i++) {
        canvas.buffer[i][s_x] = '|';
    }
    for (int i = 0; i < n; i++) {
        stack.push(tmp[i]);
    }
    delete[] tmp;
}
