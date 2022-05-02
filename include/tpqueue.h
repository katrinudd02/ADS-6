// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[1000];
    int begin, end;

 public:
    TPQueue() :begin(0), end(0) {}
    void push(T value) {
        int temp = end++;
        bool flag = true;
        while (flag) {
            if ((begin <= --temp) && (value.prior > arr[temp % size].prior)) {
                arr[(temp + 1) % size] = arr[temp % size];
            } else {
                flag = false;
            }
        }
        arr[(temp + 1) % size] = value;
    }
    T pop() {
        return arr[(begin++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
